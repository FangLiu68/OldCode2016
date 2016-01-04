//
//  Find Peak Num.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/28/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 A peak element is an element that is greater than its neighbors.
 Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 You may imagine that num[-1] = num[n] = -∞.

 For example, 
 in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2
 */
#include "Header.h"

// binary search. O(logN)
int findPeakElement(vector<int>& nums) {
    if(nums.empty()){
        return INT_MAX;
    }
    if(nums.size() == 1){
        return 0;
    }
    int left = 0;
    int right = nums.size()-1;
    
    while(left < right-1){
        int mid = left+(right-left)/2;
        if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
            return mid;
        }
        if(nums[mid] < nums[mid-1]){
            right = mid;
        }else{
            left = mid;
        }
    }
    return nums[left] > nums[right]? left:right;
}