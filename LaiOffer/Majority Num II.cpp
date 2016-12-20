//
//  Majority Num II.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/14/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an integer array of length L, find all numbers that occur more than 1/3 * L times if any exist.

 Assumptions
 The given array is not null
 Examples
 A = {1, 2, 1, 2, 1}, return [1, 2]
 A = {1, 2, 1, 2, 3, 3, 1}, return [1]
 A = {1, 2, 2, 3, 1, 3}, return []
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
 摩尔投票法。投票法的核心是找出两个候选众数进行投票，需要两遍遍历，第一遍历找出两个候选众数，第二遍遍历重新投票验证这两个候选众数是否为众数即可。
 
 这道题让我们求出现次数大于n/3的众数，而且限定了时间和空间复杂度，那么就不能排序，也不能使用哈希表，这么苛刻的限制条件只有一种方法能解了，那就是摩尔投票法 Moore Voting，这种方法在之前那道题Majority Element 求众数中也使用了。题目中给了一条很重要的提示，让我们先考虑可能会有多少个众数，经过举了很多例子分析得出，任意一个数组出现次数大于n/3的众数最多有两个，具体的证明我就不会了，我也不是数学专业的。那么有了这个信息，我们使用投票法的核心是找出两个候选众数进行投票，需要两遍遍历，第一遍历找出两个候选众数，第二遍遍历重新投票验证这两个候选众数是否为众数即可，选候选众数方法和前面那篇Majority Element 求众数一样，由于之前那题题目中限定了一定会有众数存在，故而省略了验证候选众数的步骤，这道题却没有这种限定，即满足要求的众数可能不存在，所以要有验证。
 */
vector<int> majorityElement(vector<int>& nums) {
    vector<int> res;
    if(nums.empty()) return res;
    
    int m1 = 0;
    int c1 = 0;
    int m2 = 0;
    int c2 = 0;
    
    // find two candidates
    for(int i=0; i<nums.size(); ++i){
        int x = nums[i];
        
        if(x == m1) ++c1;
        else if(x == m2) ++c2;
        else if(c1 == 0){
            m1 = x;
            c1 = 1;
        }else if(c2 == 0){
            m2 = x;
            c2 = 1;
        }else{
            --c1, --c2;
        }
    }
    
    // test
    c1 = 0;
    c2 = 0;
    for(int i=0; i<nums.size(); ++i){
        if(m1 == nums[i]) ++c1;
        else if(m2 == nums[i]) ++c2;
    }
    
    if(c1>nums.size()/3) res.push_back(m1);
    if(c2>nums.size()/3) res.push_back(m2);
    
    return res;
}

/*
 找>N/K的数，就需要(k-1)size map. key:arr[i], value:count of show time
 */

vector<int> majority(vector<int> array) {
    vector<int> res;
    if(array.empty()) return res;

    // 注意这里用的是map而不是unordered_map. map是有序的，得到结果直接push到res里，但如果用unorderd_map存的话最后还要再sort(res.begin(), res.end())一遍
    map<int, int> mp;
    
    for(int i=0; i<array.size(); ++i){
        if(mp.find(array[i]) == mp.end()){
            mp[array[i]] = 1;
        }else{
            mp[array[i]]++;
        }
    }
    int k = array.size()/3;
    for(map<int, int>::iterator IT = mp.begin(); IT != mp.end(); ++IT){
        if(IT->second > k){
            res.push_back(IT->first);
        }
    }
    //sort(res.begin(), res.end());
    return res;
}