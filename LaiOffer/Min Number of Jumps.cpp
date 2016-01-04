//
//  Min Number of Jumps.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/13/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array A of non-negative integers, you are initially positioned at index 0 of the array. A[i] means the maximum jump distance from index i (you can only jump towards the end of the array). Determine the minimum number of jumps you need to reach the end of array. If you can not reach the end of the array, return -1.

 Assumptions
 The given array is not null and has length of at least 1.
 Examples
 {3, 3, 1, 0, 4}, the minimum jumps needed is 2 (jump to index 1 then to the end of array)
 {2, 1, 1, 0, 2}, you are not able to reach the end of array, return -1 in this case.
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 index 0 1 2 3 4
  A = [2,3,1,0, 4], return true.
       s       goal
  M = [ x x x X 0]

 DP principle:
 Base case:  	    M[n-1] = 0
 Induction rule:    Define M[i] ?????
	M[i] represents the least number of jumps to reach M[n-1].
	M[i] = 1 + min(M[j]) j is all the elements that can be reached by 1 jump from i

 */

// 用数组存储中间结果的方法  稍微简单一些
int minJump(vector<int> input) {
    if(input.empty()) return -1;

    // min_jump[] record the min number of jumps from 0 to each of the index
    int* min_jump = new int[input.size()];
    min_jump[0] = 0; // we do not need to jump for index 0
    for(int i=1; i<input.size(); ++i){
        min_jump[i] = input.size();
        for(int j=i-1; j>=0; --j){
            if(j+input[j] >= i){
                // min_jump[i]=min(min_jump[j]+1) for all the j<i
                // and can jump from j to i
                min_jump[i] = min(min_jump[i], min_jump[j]+1);
            }
        }
    }
    int res = min_jump[input.size()-1];
    delete[] min_jump;
    if(res == input.size()){
        return -1;
    }else{
        return res;
    }
}

int minJumps(int arr[], int len){
    if(arr == NULL || len <= 0){
        return 0;
    }
    int* jumps = new int[len]; // sotre subsolutions
    int min_jumps = INT_MAX;
    jumps[len-1] = 0; // base case
    for(int i = len-2; i >= 0; --i){ // check from right to left
        if(arr[i] == 0){
            jumps[i] = INT_MAX;
        }else if(i+arr[i] >= len-1){ // jumps out of bouder
            jumps[i] = 1;
        }else{
            min_jumps = INT_MAX;
            for(int j = i+1; j<len && j<=arr[i]+i; ++j){
                min_jumps = min(min_jumps, jumps[j]);
            }
            if(min_jumps != INT_MAX){
                jumps[i] = min_jumps + 1;
            }else{
                jumps[i] = INT_MAX;
            }
        }
    }
    int res = jumps[0];
    delete[] jumps;
    return res;
}


