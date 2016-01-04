//
//  Smallest Larger Than Target.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/28/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// find the element whose value is smallest larger than a target in a sorted arr

#include "Header.h"

int smallest_larger_than(vector<int> arr, int target){
    if(arr.empty()){
        return INT_MIN;
    }
    if(arr[0] > target){
        return arr[0];
    }else if(arr[arr.size()-1] <= target){
        return INT_MIN;
    }
    int left = 0;
    int right = arr.size() - 1;

    while(left < right-1){
        int mid = left + (right-left)/2;
        if(arr[mid] == target){
            return arr[mid+1];
        }else if(arr[mid] < target){
            left = mid;
        }else{
            right = mid;
        }
    }
    
    return arr[right];
}
/*
int main(){
    vector<int> arr1 = {2};
    vector<int> arr2 = {6,8};
    vector<int> arr3 = {2,5,9};
    int target = 2;
    cout << smallest_larger_than(arr1, target) << endl;
    cout << smallest_larger_than(arr2, target) << endl;
    cout << smallest_larger_than(arr3, target) << endl;
    return 0;
}*/