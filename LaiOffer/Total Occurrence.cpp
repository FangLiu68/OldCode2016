//
//  total occurrence.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a target integer T and an integer array A sorted in ascending order, Find the total number of occurrences of T in A.

 Examples
 A = {1, 2, 3, 4, 5}, T = 3, return 1
 A = {1, 2, 2, 2, 3}, T = 2, return 3
 A = {1, 2, 2, 2, 3}, T = 4, return 0
 Corner Cases
 What if A is null? We should return 0 in this case
 */

#include "Header.h"

int first_occur(vector<int> input, int target);
int last_occur(vector<int> input, int target);
int toal_occurrence(vector<int> input, int target) {
    if(input.empty()) return 0;
    int left = first_occur(input, target);
    int right = last_occur(input, target);
    if(left == -1 || right == -1) return 0;
    return right - left + 1;
}

int first_occur(vector<int> input, int target){
    if(input.empty()) return -1;
    int left = 0;
    int right = input.size()-1;
    int mid;
    while(left < right-1){
        mid = left + (right-left)/2;
        if(input[mid] == target)
            right = mid;
        else if(input[mid] < target)
            left = mid+1;
        else
            right = mid-1;
    }
    if(input[left] == target) return left;
    else if(input[right] == target) return right;
    return -1;
}

int last_occur(vector<int> input, int target){
    if(input.empty()) return -1;
    int left = 0;
    int right = input.size()-1;
    int mid;
    while(left < right-1){
        mid = left + (right-left)/2;
        if(input[mid] == target)
            left = mid;
        else if(input[mid]< target)
            left = mid+1;
        else
            right = mid-1;
    }
    if(input[right] == target) return right;
    else if(input[left] == target) return left;
    return -1;
}