//
//  House Robber.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/18/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

 Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 
 Example: {5, 2, 2, 4, 1} → 5 + 4 = 9.

 */

#include <vector>
#include <iostream>
using namespace std;

/*
 state: m[i] = max profit of subarray(0, i),
 function: m[i] = max(A[i] + m[i - 2], m[i - 1])
 result: m[A.length - 1]
 base case: m[0] = A[0], m[1] = max(A[0], A[1])

 time complexity: O(n)
 space complexity: O(n) → O(1)
 
 */

int rob(vector<int>& nums){
    if(nums.empty()){
        return 0;
    }
    if(nums.size() == 1) return nums[0];

    int M[nums.size()-1];
    M[0] = nums[0];
    M[1] = max(nums[0], nums[1]);

    for(int i=2; i<nums.size(); ++i){
        M[i] = max(M[i-1], nums[i]+M[i-2]); // 取A[i] / 或者不取A[i]
    }
    return M[nums.size()-1];
}




