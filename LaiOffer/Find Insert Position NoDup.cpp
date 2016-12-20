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
  0 1 2 3
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

int searchInsert1(vector<int> input, int target) {
    if(input.empty()) return -1;
    
    if(target <= input[0]) return 0;
    if(target > input[input.size()-1]) return input.size();
    int left = 0;
    int right = input.size()-1;
    
    while(left < right-1){ // 注意条件
        int mid = left+(right-left)/2;
        if(input[mid] == target){
            return mid;
        }
        if(target < input[mid]){
            right = mid;
        }else{
            left = mid;
        }
    }
    return right;
}

// 和binary search 一样，不过最后返回的是left. 和下个题不同，仔细看
int searchInsert(vector<int>& nums, int target) {
    if(nums.empty()){
        return 0;
    }
    
    int left = 0;
    int right = nums.size() - 1;
    
    while(left <= right){
        int mid = left + (right - left)/2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] < target){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    
    return left;
}
