//
//  Search Insert Position.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/28/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

 You may assume no duplicates in the array.
 Here are few examples.
 [1,3,5,6], 5 → 2
 [1,3,5,6], 2 → 1
 [1,3,5,6], 7 → 4
 [1,3,5,6], 0 → 0
 */

#include "Header.h"

/*
 插入元素比头元素小，则直接返回0
 插入元素比末元素大，则直接返回len
 插入元素不在数组中，则当左右index相邻时，直接返回right index
 */
int searchInsert(int A[], int n, int target) {
    if(A==NULL || n<=0) return -1;
    if(target <= A[0]) return 0;
    if(target > A[n-1]) return n;
    int left = 0;
    int right = n-1;
    
    while(left < right-1){ // 注意条件
        int mid = left+(right-left)/2;
        if(A[mid] == target){
            return mid;
        }
        if(target < A[mid]){
            right = mid;
        }else{
            left = mid;
        }
    }
    return right;
}

