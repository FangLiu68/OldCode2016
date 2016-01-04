//
//  find k-th Largest Element in Unsorted Arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/18/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

 For example,
 Given [3,2,1,5,6,4] and k = 2, return 5.

 Note:
 You may assume k is always valid, 1 ≤ k ≤ array's length.
 */

#include "Header.h"

// find k-th largest element, then when this element in sorted sequence its index should be arr.size()-k

int helper_partition(vector<int>& nums, int left, int right){
    int pivotPos = left + (right-left)/2;
    int pivot = nums[pivotPos];
    swap(nums[pivotPos], nums[right]);
    int l = left;
    int r = right-1;
    while(l <= r){
        if(nums[l] < pivot){
            l++;
        }else if(nums[r] > pivot){
            r--;
        }else{
            swap(nums[l++], nums[r--]);
        }
    }
    swap(nums[l], nums[right]);
    return l;
}


int helper_quickSelect(vector<int>& nums, int left, int right, int index){
    if(left>right) return -1;
    int cur_index = helper_partition(nums, left, right);
    if(index == cur_index){
        return nums[cur_index];
    }else if(index < cur_index){
        return helper_quickSelect(nums, left, cur_index-1, index);
    }else{
        return helper_quickSelect(nums, cur_index+1, right, index);
    }
}


int findKthLargest(vector<int>& nums, int k) {
    if(nums.empty()){
        return INT_MIN;
    }
    int index = nums.size()-k;
    return helper_quickSelect(nums, 0, nums.size()-1, index);
}

