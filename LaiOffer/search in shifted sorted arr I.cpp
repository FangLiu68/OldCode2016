//
//  search in shifted sorted arrI.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a target integer T and an integer array A, A is sorted in ascending order first, then shifted by an arbitrary number of positions.
 For Example, A = {3, 4, 5, 1, 2} (shifted left by 2 positions). 
                Find the index i such that A[i] == T or return -1 if there is no such index.
 Assumptions
 There are no duplicate elements in the array.
 Examples
 A = {3, 4, 5, 1, 2}, T = 4, return 1
 A = {1, 2, 3, 4, 5}, T = 4, return 3
 A = {3, 5, 6, 1, 2}, T = 4, return -1
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 1. mid is res
 2. left part is sorted
 3. right part is sorted
 */

int search(vector<int>& nums, int target) {
    if(nums.empty()) return -1;
    int left = 0;
    int right = nums.size()-1;
    
    while(left <= right){
        int mid = left + (right-left)/2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[left]<=nums[mid]){ // left part is sorted. 这里是left<=mid，因为mid是向下取整
            if(nums[left]<=target && target<nums[mid]){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }else{ // right part is sorted
            if(nums[mid]<target && target<=nums[right]){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
    }
    return -1;
}

