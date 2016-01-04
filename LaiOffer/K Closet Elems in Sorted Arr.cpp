//
//  closet k elem to target.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a target integer T, a non-negative integer K and an integer array A sorted in ascending order, find the K closest numbers to T in A.

 Assumptions
 K is guranteed to be >= 0 and K is guranteed to be <= A.length
 Return
 A size K integer array containing the K closest numbers(not indices) in A, sorted in ascending order by the difference between the number and T.
 Examples
 A = {1, 2, 3}, T = 2, K = 3, return {2, 1, 3} or {2, 3, 1}
 A = {1, 4, 6, 8}, T = 3, K = 3, return {4, 1, 6}
 Corner Cases
 What if A is null? We should return null in this case.
 */

#include "Header.h"

int helper_close(vector<int> input, int target);
vector<int> K_close_elems_to_target(vector<int> input, int target, int k) {
    vector<int> res(k);
    if(input.empty() || k==0) return res;
    int close = helper_close(input, target);
    int smaller = close-1;
    int bigger = close+1;
    res[0] = input[close];
    
    for(int i=1; i<k; i++){
        if(smaller>=0 && bigger<input.size()){
            if(target-input[smaller] <= input[bigger]-target)
                res[i] = input[smaller--];
            else
                res[i] = input[bigger++];
        }
        else if(bigger >= input.size())
            res[i] = input[smaller--];
        else if(smaller < 0)
            res[i]= input[bigger++];
    }
    return res;
}

// 先找出最close的那个，返回的是Index，然后向其位置的左右开始延伸
int helper_close(vector<int> input, int target){
    if(input.empty()) return -1;
    int left = 0;
    int right = input.size()-1;
    while(left < right-1){
        int mid = left+(right-left)/2;
        if(input[mid] == target){
            return mid;
        }else if(input[mid]<target){
            left = mid;
        }else{
            right = mid;
        }
    }
    if(abs(input[left]-target) <= abs(input[right]-target))
        return left;
    else 
        return right;
}
