//
//  First Occurrence Elem.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Given a sorted array, return the first index of the target element. If the target couldn't be found, return -1.

#include <iostream>

/*
 Iteration 1: L = 0, R = 6, M = 3    A[M] == A[3] == 5 == target, so    R = M = 3;
 Iteration 2: L = 0, R = 3, M = 1    A[M] == A[1] == 5 == target, so    R = M = 1;
 因为左右边界相邻，我们terminate binary search， 再做post processing.
 // e.g. int a[7] = {4, 5, 5, 5, 5, 5, 5};
 // if target == 5;  then index 1 is returned;
 // if target == 10; then -1 is returned;
 // Termination condition: 当L和R 相邻的时候，跳出while 循环，再判断L和R究竟哪个是最终答案 (= post-processing)。
 */
int find_first_occr(int arr[], int len, int target){
    if(arr == NULL || len<=0) return -1;
    int left = 0;
    int right = len-1;
    int mid;

    while(left < right-1){ // terminate when left==right-1
        mid = left + (right-left)/2;
        if(arr[mid] == target)
            right = mid; // not stop, keep checking left
        else if(arr[mid] < target)
            left = mid+1;
        else right = mid-1;
    }

    if(arr[left] == target) return left; // check left against target first
    if(arr[right] == target) return right; // then check right against target
    return -1;
}