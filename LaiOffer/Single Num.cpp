//
//  Single Num.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/29/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//


/* Given an array of integers, every element appears twice except for one. Find that single one.
 Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? */

#include "Header.h"

// 异或,不仅能处理两次的情况,只要出现偶数次,都可以清零。
// 0 ^ 任何数 = 原数; 任何数 ^ 任何数 = 0
// time complexity O(N), space complexity O(1)
int single_num(int arr[], int len){
    int result = 0;
    for(int i=0; i<len; i++)
        result = result ^ arr[i];
    return result;
}

// use hashtable, time complexity O(N), space complexity O(N)
int singleNumber_map(vector<int>& nums) {
    if(nums.empty()){
        return INT_MIN;
    }
    map<int, int> mp;
    for(int i=0; i<nums.size(); ++i){
        if(mp.find(nums[i]) == mp.end()){
            mp[nums[i]] = 1;
        }else{
            mp[nums[i]]++;
        }
    }
    for(map<int,int>::iterator IT = mp.begin(); IT != mp.end(); ++IT){
        if(IT->second == 1){
            return IT->first;
        }
    }
    return INT_MIN;
}

// 先排序再查找。 time complexity O(NlogN)
// 通用性好，适合两种情况
int singleNumber(int A[], int n) {
    //特殊情况1,2
    if(n<=0) return -1;
    if(n==1) return A[0];

    sort(A, A + n);
    int j = 1;
    for(int i = 0; i < n - 1; i++){
        if(A[i] == A[i+1])
            j++;
        else{
            if(j<2) return A[i];//这里修改为j<3那么就可以适用于single number II了。
            j = 1;
        }
    }
    //特殊情况3 最后一个是single number的特殊情况
    return A[n-1];
}