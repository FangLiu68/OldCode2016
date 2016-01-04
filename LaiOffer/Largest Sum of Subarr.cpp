//
//  Largest Sum of Subarr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/13/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Given an unsorted array, find the subarray that has the greatest sum. Return the sum.
// eg. If the input array is {1, 2, 4, -1,  -2, 10,  -1}, the greatest sum is achieved by subarray {1, 2, 4, -1, -2, 10}.

#include <iostream>
#include <vector>
using namespace std;

/*
 Base case: only element M[0] = A[0]
 Induction rule: Define M[i]
 M[i] represents the largest possible sum from A[0] to A[i] (including A[i])
 M[i] = case1: M[i-1] + A[i] (if M[i-1] >= 0)
        case2: A[i]          (if M[i-1] < 0)
 
 index 0  1  2   3   4   5    6  7  8  9
 A[] = 1, 2, 4,	-1, -2, -10, -1, 2, 4, 7
 M[] = 1  3  7	 6   4	 -6  -1  2  6  13
 */

int largestSum(vector<int> input){
    if(input.empty()){
        return INT_MIN;
    }
    int max_val = input[0];
    int cur_val = input[0];
    for(int i = 1; i < input.size(); ++i){
        if(cur_val > 0){
            cur_val = cur_val + input[i];
        }else{
            cur_val = input[i];
        } // 先确定在不同情况下cur_val(即M[i-1])是多少,然后再判断是否更新max_val的值

        max_val = max(max_val, cur_val);
    }
    return max_val;
}

int largestSumI(vector<int> input){
    if(input.empty()){
        return INT_MIN;
    }
    int max_val = input[0];
    int cur_val = input[0];
    for(int i=1; i<input.size(); ++i){
        cur_val = max(cur_val+input[i], input[i]);
        max_val = max(max_val, cur_val);
    }
    return max_val;
}
