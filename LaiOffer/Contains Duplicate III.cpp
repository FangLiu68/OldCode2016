//
//  Contains Duplicate III.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/18/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
 */

#include <unordered_map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/*
 比较好的是用Java treeset来做  用C++是下面  没看懂
 
 解题思路：
 给定一个整数数组，判断其中是否存在两个不同的下标i和j满足：| nums[i] – nums[j] | <= t 并且 | i – j | <= k。

 如果： | nums[i] - nums[j] | <= t   式a
 等价： | nums[i] / t - nums[j] / t | <= 1   式b
 推出： | floor(nums[i] / t) - floor(nums[j] / t) | <= 1   式c
 等价： floor(nums[j] / t) ∈ {floor(nums[i] / t) - 1, floor(nums[i] / t), floor(nums[i] / t) + 1} 式d
 其中式b是式c的充分非必要条件，因为逆否命题与原命题等价，所以：

 如果： floor(nums[j] / t) ∉ {floor(nums[i] / t) - 1, floor(nums[i] / t), floor(nums[i] / t) + 1} 非d
 推出： | nums[i] - nums[j] | > t   非a
 用一个hash表来存储滑动窗口的数值，其中键值为nums[i]/t，对于数值nums[k]，若存在键为nums[k]/t，nums[k]/t-1，nums[k]/t+1，再比较他们的数值。

 有两个地方需要注意：
 1、该题目可能会int类型溢出，因此需要先转化成long long类型。
 2、map和unordered_map并不是按插入顺序排序的。因此还需要用一个队列来维持一个滑动窗口。
 */
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if(k<1||t<0){
        return false;
    }
    unordered_map<int, long long> nums_map;
    queue<int> keys;     //顺序存储的一些键值
    int len = nums.size();
    for(int i=0; i<len; i++){
        int key = nums[i]/max(t, 1);
        for(int j=key-1; j<=key+1; j++){
            if(nums_map.find(j)!=nums_map.end() && abs(nums_map[j] - nums[i])<=(long long)t){                     return true;
            }
        }
        nums_map[key]=nums[i];
        keys.push(key);
        if(nums_map.size()>k){
            nums_map.erase(keys.front());
            keys.pop();
        }
    }
    return false;
}
