//
//  3Sum Closest.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/9/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

 For example, given array S = {-1 2 1 -4}, and target = 1.

 The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 这道题和3Sum差不多，不过也有不一样的，主要是：
 1 这里不用判断处理重复问题
 2 要比较其中的三个数的和与目标数的差的大小。
 */

#include <iostream>
#include <vector>
using namespace std;

// O(N^2) runtime, O(1) space 先排序，再左右夹逼
int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size() < 3){
        return INT_MIN;
    }
    
    int close = INT_MAX;
    int res = 0;
    
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); ++i){
        int start = i+1;
        int end = nums.size()-1;
        while(start < end){
            int sum = nums[i] + nums[start] + nums[end];
            if(sum == target){
                return sum;
            }
            int gap = abs(target - sum);
            if(gap < close){
                close = gap;
                res = sum;
            }
            if(sum < target){
                start++;
            }else{
                end--;
            }
        }
    }
    
    return res;
}
