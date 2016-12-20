//
//  4Sum.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/19/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given an array S of n integers, are there elements a, b, c and d in S such that a+b+c+d = target? Find all unique quadruplets in teh array which gives the sum of target.
 Note: The solution set must not contain duplicate quadruplets.
 For example:
 given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 
 A solution set is:
 [
 [-1,  0, 0, 1],
 [-2, -1, 1, 2],
 [-2,  0, 0, 2]
 ]
 */

#include <vector>
#include <iostream>
using namespace std;

// O(N^3) 去重复方法和3sum相同
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    if(nums.size()<4){
        return res;
    }
    
    sort(nums.begin(), nums.end());
    vector<int> cur(4, 0);
    
    for(int i=0; i<nums.size()-3; ++i){
        if(i>0 && nums[i]==nums[i-1]) continue;
        
        for(int j=i+1; j<nums.size()-2; ++j){
            if(j>i+1 && nums[j]==nums[j-1]) continue;
            
            int start = j+1;
            int end = nums.size() - 1;
            while(start < end){
                if(nums[i] + nums[j] + nums[start] + nums[end] == target){
                    cur[0] = nums[i];
                    cur[1] = nums[j];
                    cur[2] = nums[start++];
                    cur[3] = nums[end--];
                    res.push_back(cur);
                    
                    while(start < end && nums[start] == nums[start-1]) start++;
                    while(start < end && nums[end] == nums[end+1]) end--;
                }else if(nums[i] + nums[j] + nums[start] + nums[end] < target){
                    start++;
                }else{
                    end--;
                }
            }
            // 下面这两个while用不用都行 结果相同
            // while(j<nums.size()-3 && nums[j]==nums[j+1]) j++;
        }
        //while(i<nums.size()-2 && nums[i]==nums[i+1]) i++;
    }
    return res;
}