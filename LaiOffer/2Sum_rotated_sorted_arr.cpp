//
//  1.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array that is sorted and then rotated by an unknown number of positions.
 Find if the array has a pair of elements that sum up to a target number X.
 Assumed there is no duplicated numbers in the array.
 */

/*
 M1: (Junwei)   Proposed to use Binary search
	For each element A[i], you want to perform a binary search to find target - A[i]
	O(n * log(n))
 M2:  Use a hash_map, regardless whether the array is sorted or not.
	Time = O(n)
	Space = O(n)
 M3: time O(1), space O(1)
 rotated sorted arr找
 */

#include <iostream>
#include <vector>
using namespace std;

bool twoSum_rotated_arr(vector<int> arr, int target){
    if(arr.empty()){
        return false;
    }

    int len = arr.size();

    // find min element index in the arr
    int min_index = 0;
    for(int i=0; i<len; ++i){
        if(arr[i] <= arr[min_index]){
            min_index = i;
        }
    }

    int left = min_index;
    int right = (min_index-1+len)%len; // 避免超过数组界限
    while(left <= right){
        if(arr[left] + arr[right] == target){
            return true;
        }else if(arr[left] + arr[right] < target){
            left = (left+1) % len;
        }else{
            right = (right-1+len) % len;
        }
    }
    return false;
}