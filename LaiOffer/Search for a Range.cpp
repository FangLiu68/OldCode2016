//
//  Search for a Range.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/28/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a sorted array of integers, find the starting and ending position of a given target value.

 Your algorithm's runtime complexity must be in the order of O(log n).
 If the target is not found in the array, return [-1, -1].
 For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].
 */
#include "Header.h"

// 方法和上一题一样。先找出第一次出现的位置，再找出最后一次出现的位置。O(logN)+O(logN) = O(logN)
int findFirst(int arr[], int len, int target);
int findLast(int arr[], int len, int target);
vector<int> searchRange(int A[], int n, int target) {
    vector<int> res;
    if(A==NULL || n<=0) return res;
    res.push_back(findFirst(A,n,target));
    res.push_back(findLast(A,n,target));
    return res;
}

int findFirst(int arr[], int len, int target){
    if(arr==NULL || len<=0){
        return -1;
    }
    int left = 0;
    int right = len-1;
    while(left < right-1){
        int mid = left+(right-left)/2;
        if(arr[mid] == target){
            right = mid;
        }else if(arr[mid] < target){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    if(arr[left] == target) return left;
    if(arr[right] == target) return right;
    return -1;
}

int findLast(int arr[], int len, int target){
    if(arr==NULL || len<=0){
        return -1;
    }
    int left = 0;
    int right = len-1;
    while(left < right-1){
        int mid = left+(right-left)/2;
        if(arr[mid] == target){
            left = mid;
        }else if(arr[mid] < target){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    if(arr[right] == target) return right;
    if(arr[left] == target) return left;
    return -1;
}

//===================================================================
// 下面的做法时间复杂度为O(N) 不好  不用看
int helper_BS(int A[], int n, int target){
    int start = 0;
    int end = n-1;
    // 二分法是start <= end 这里等号不能少   记住
    while(start <= end){
        int mid = (start+end)/2;
        if(A[mid] == target) return mid;
        else if(A[mid] < target) start = mid+1;
        else end = mid-1;
    }
    return -1;
}


// 首先二分法，然后根据二分的坐标往前往后查找
// 最差时间复杂度是O(N),平均时间复杂度O(logN)
vector<int> searchRange1(int A[], int n, int target) {
    vector<int> res;
    if(A==NULL || n<=0) return res;
    int pos = helper_BS(A,n,target);
    if(pos==-1){
        res.push_back(-1);
        res.push_back(-1);
        return res;
    };

    // 注意左边界限，要保证left-1 和 right+1都有效
    int left = pos;
    while(left>0 && A[left-1]==target) left--;

    int right = pos;
    while(right<n-1 && A[right+1]==target) right++;

    res.push_back(left);
    res.push_back(right);
    return res;
}


