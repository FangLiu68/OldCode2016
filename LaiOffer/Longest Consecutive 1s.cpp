//
//  Longest Consecutive 1s.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/13/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array containing only 0s and 1s, find the length of the longest subarray of consecutive 1s.

 Assumptions
 The given array is not null
 Examples
 {0, 1, 0, 1, 1, 1, 0}, the longest consecutive 1s is 3.
 */

#include <iostream>
using namespace std;

/*
 base case: M[0]=1 // if A[0]==1
                =0 // else
 induction rule:
 M[i]=M[i-1]+1  // if A[i]==1
     =0         // else
 */

int Longest_consecutive_1(int arr[], int len){
    if(arr==NULL || len<=0){
        return -1;
    }
    int cur_val = (arr[0]==1)? 1:0;
    int max_val = cur_val; // 注意把max_val初始值设置为cur_val
    for(int i=1; i<len; ++i){
        cur_val = (arr[i]==1)?(cur_val+1):0;
        max_val = max(max_val, cur_val);
    }
    return max_val;
}

int Longest_consecutive_1I(int arr[], int len){
    if(arr==NULL || len<=0){
        return -1;
    }
    int cur_longest = 0;
    int longest = 0;
    for(int i=0; i<len; ++i){
        if(arr[i] == 1){
            cur_longest++;
            longest = max(longest, cur_longest);
        }else{
            cur_longest = 0; // reset curLongest to 0 if array[i] == 0
        }
    }
    return longest;
}