//
//  find k-th Smallest Element in Unsorted Arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/18/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 same as above question.
 Find k-th smallest element in unsorted array.
 then when this element in sorted sequence its index should be (k-1)
 */
#include <iostream>
using namespace std;


int helper_partition1(int arr[], int left, int right){
    int pivotPosition = left + (right-left)/2;
    int pivot = arr[pivotPosition];
    swap(arr[pivotPosition], arr[right]);
    int l = left;
    int r = right-1;
    while(l <= r){
        if(arr[l] < pivot){
            l++;
        }else if(arr[r] > pivot){
            r--;
        }else{
            swap(arr[l++], arr[r--]);
        }
    }
    swap(arr[l], arr[right]);
    return l; // l 所指向的元素放在他本来应该存在的位置上
}

int helper_sort1(int arr[], int left, int right, int k){
    if(left > right){ // left==right时不能返回-1，因为如果只有一个元素的话left肯定等于right
        return -1;
    }
    int correct_index = helper_partition1(arr, left, right);
    if(correct_index == k-1){
        return arr[correct_index];
    }else if(k-1 > correct_index){
        return helper_sort1(arr, correct_index+1, right, k);
    }else{
        return helper_sort1(arr, left, correct_index-1, k);
    }
}

int quickSelect1(int arr[], int len, int k){
    if(arr == NULL){
        return INT_MIN;
    }
    int left = 0;
    int right = len-1;
    return helper_sort1(arr, left, right, k);
}

/*
 int main(){
 int arr[] = {12, 3, 1, 9, 20, 5, 25};
 int len = sizeof(arr) / sizeof(int);
 cout << quickSelect(arr, len, 6) << endl;
 return 0;
 }*/