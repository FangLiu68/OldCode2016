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

// O(N^2) runtime, O(1) space
int threeSumClosest(vector<int> &num, int target) {
    int res = 0;
    int closet = INT_MAX;
    sort(num.begin(), num.end());
    for(int i=0; i<num.size(); i++){
        int j = i+1;
        int k = num.size()-1;
        while(j < k){
            int sum = num[i]+num[j]+num[k];
            if(sum == target) return sum;

            int gap = abs(target-sum);
            if(gap < closet){
                res = sum;
                closet = gap;
            }
            if(sum < target) j++;
            else if(sum > target) k--;
        }
    }
    return res;
}

// 先排序，然后左右夹逼。time complexity O(N^2), space complexity O(1)
int threeSumClosest1(vector<int> &num, int target){
    int closest = INT_MAX;
    int res = 0;
    sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++){
        for (int j = i+1, k = num.size()-1; j < k; ){
            int sum = num[i]+num[j]+num[k];
            if (sum == target) return sum;
            int t = abs(sum-target);
            if (t<closest){
                res = sum;
                closest = t;
            }
            if (sum < target) j++;
            else if (sum > target) k--;
        }
        while (i < num.size() && num[i] == num[i+1]) i++; // 这个不可少
    }
    return res;
}