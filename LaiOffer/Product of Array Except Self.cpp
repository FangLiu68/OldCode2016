//
//  Product of Array Except Self.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/10/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 
 Solve it without division and in O(n).
 
 For example, given [1,2,3,4], return [24,12,8,6].
 
 Follow up:
 Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
 */

#include "Header.h"

/*
 num[i]:        1  2  3 4
 left to right: 1  1  2 6
 right to left: 24 12 4 1
 res:           24 12 8 6
 
 res[i] = (num[0] * .. * num[i-1]) multiply (num[i+1] * .. * num[num.size()-1])
 
 we use two arrays to store the multiply from left to right and from right to left, then multiply together
 time O(n), space O(n)
 */
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size());
    
    vector<int> v1(nums.size(), 1);
    vector<int> v2(nums.size(), 1);
    
    // scan from left to right
    for(int i=0; i<nums.size()-1; ++i){
        v1[i+1] = nums[i] * v1[i];
    }
    
    // scan from right to left;
    for(int i=nums.size()-1; i>0; --i){
        v2[i-1] = nums[i] * v2[i];
    }
    
    // multiply
    for(int i=0; i<nums.size(); ++i){
        res[i] = v1[i] * v2[i];
    }
    
    return res;
}

// time O(n), space O(1) 
vector<int> productExceptSelf1(vector<int>& nums) {
    vector<int> res(nums.size(), 1);
    //if(nums.empty()) return res;
    
    for(int i=nums.size()-2; i>=0; --i){
        res[i] = res[i+1] * nums[i+1];
    }
    
    int left = 1;
    for(int i=0; i<nums.size(); ++i){
        res[i] = left * res[i];
        left = left * nums[i];
    }
    
    return res;
}