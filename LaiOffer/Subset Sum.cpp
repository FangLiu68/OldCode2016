//
//  Subset Sum.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/2/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
 Examples: set[] = {1, 4, 20, 5, 7}, sum = 8
 Output:  True 		 //There is a subset (1, 7) with sum 8.


 Subset Sum Problem
 Partition Problem
 http://en.wikipedia.org/wiki/Partition_problem
 */

#include "Header.h"

/*
 Method1:
 用DFS，算出所有可能的subset，同时每个subset保存一份他的sum，看最后结果是否含有target sum
 runtime O(2^N)
 */

bool find_subset(vector<int> arr, int index, int sum, int target){
    if(index == arr.size()){
        if(sum == target){
            return true;
        }
    }
    if(find_subset(arr, index+1, sum+arr[index], target)){
        return true;
    }
    if(find_subset(arr, index+1, sum, target)){
        return true;
    }
    return false;
}