//
//  Permutations.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/20/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a collection of numbers, return all possible permutations.

 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 
 和上一题一样，只是这个是数字
 */

#include "Header.h"

void helper_swapPermute(vector<int>& nums, int i, int j){
    int t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
}

void helper_permute(vector<int>& nums, vector<vector<int>>& res, int index){
    if(index == nums.size()){
        res.push_back(nums);
        return;
    }
    for(int i=index; i<nums.size(); ++i){
        helper_swapPermute(nums, index, i);
        helper_permute(nums, res, index+1);
        helper_swapPermute(nums, index, i);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    if(nums.empty()){
        return res;
    }
    helper_permute(nums, res, 0);
    return res;
}

