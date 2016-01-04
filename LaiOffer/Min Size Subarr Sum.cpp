//
//  Min Size Subarr Sum.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/19/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

 For example, given the array [2,3,1,2,4,3] and s = 7,
 the subarray [4,3] has the minimal length under the problem constraint
 */

#include "Header.h"

/*
 滑动窗口 [left, right] 初始大小为0，滑动的规则如下：

 若元素之和 < s，窗口右边沿向右延伸，直到 元素之和≥s 为止。
 若元素之和 ≥ s，更新最小长度。然后窗口左边沿右移一位（即移除窗口中第一个元素），重复第1步。
 
 O(N) runtime
 */
int minSubArrayLen(int s, vector<int>& nums) {
    if(nums.empty()) return 0;
    int left = 0;
    int right = 0;
    int cur_sum = 0;
    int res = INT_MAX;
    while(right < nums.size()){
        cur_sum = cur_sum + nums[right];
        while(cur_sum >= s){
            res = min(res, right-left+1);
            cur_sum = cur_sum - nums[left];
            left++;
        }
        right++;
    }
    if(res == INT_MAX){
        return 0;
    }else{
        return res;
    }
}