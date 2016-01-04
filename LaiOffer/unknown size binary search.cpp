
//
//  unknown size binary search.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a integer dictionary A of unknown size, where the numbers in the dictionary are sorted in ascending order, determine if a given target integer T is in the dictionary. Return the index of T in A, return -1 if T is not in A.

 Assumptions

 dictionary A is not null
 dictionary.get(i) will return null if index i is out of bounds
 Examples

 A = {1, 2, 5, 9, ......}, T = 5, return 2
 A = {1, 2, 5, 9, 12, ......}, T = 7, return -1
 */

#include "Header.h"

int helper_binary_search(vector<int> arr, int left, int right, int target);

// return INT_MIN if out of bound, otherwise return the element value
int get(vector<int> arr, int index){
    if(index > arr.size()-1) return INT_MIN;
    else return arr[index];
}

int unknow_size_binary_search(vector<int> arr, int target){
    if(arr.empty()) return -1;

    int left = 0;
    int right = 0; // initialize right index as 2^0-1

    // 1. move left to right,
    // 2. double right index, since the array's indices are started from 0,
    // we use right = 2 ^ n - 1
    while(get(arr, right) != INT_MIN && arr[right] < target){
        left = right;
        right = 2*right +1;
    }

    // not very necessary, but can return earlier
    if(get(arr, right) != INT_MIN && get(arr, right) == target)
        return right;

    return helper_binary_search(arr, left, right, target);
}

// classical binary search
int helper_binary_search(vector<int> arr, int left, int right, int target){
    if(left > right) return -1;

    int mid;
    while(left <= right){
        mid = left + (right-left)/2;
        if(arr[mid] < target) left = mid+1;
        else if(get(arr, mid) == INT_MIN || arr[mid] > target)  right = mid-1;
        else return mid;
    }
    return -1;
}

/*
int main(){
    int arr[] = {1,2,3,4,5};
    int size = getsize(arr);
    cout << size << endl;
    int* pint = new int;
    cout << sizeof(pint) << endl;
    return 0;
}*/