//
//  Contains Duplicate II.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/18/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
 */

#include "Header.h"

/*
 如果nums[i]存在于mp中，当且仅当两个重复元素的距离<=k时，才返回true
 如果nums[i]存在于mp中，但距离>k / 或者nums[i]不存在于mp中时，令mp[nums[i]]=i.
                      意思是，对于不存在的，放入当前pair；对于存在过的，更新其mp[nums[i]]的值 为当前最新(最近)的index值
 O(N) time, O(N) space
 */
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if(nums.empty()) return false;
    unordered_map<int, int> mp; // key: nums[i]; value: i
    mp[nums[0]] = 0;
    for(int i=1; i<nums.size(); ++i){
        if(mp.find(nums[i]) != mp.end()){
            if(i-mp[nums[i]] <= k){
                return true;
            }
        }
        mp[nums[i]] = i;
    }
    return false;
}

