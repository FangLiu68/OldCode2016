//
//  Contains Duplicate.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/18/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
 */

#include "Header.h"

/*
 Method 1: use hashtable. lookup O(1)
            runtime O(N), space O(N)
 Method 2: sort, then check if there are two contigouse elements are the same
            runttime O(NlogN), space O(1)//if we ignore the sort algorithm space
 */

bool containsDuplicate(vector<int>& nums) {
    if(nums.empty()) return false;
    set<int> s;
    s.insert(nums[0]);
    for(int i=1; i<nums.size(); ++i){
        if(s.find(nums[i]) != s.end()){
            return true;
        }else{
            s.insert(nums[i]);
        }
    }
    return false;
}