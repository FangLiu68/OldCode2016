//
//  3Sum 3 Arrays.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given three arrays, determine if a set can be made by picking one element from each array that sums to the given target number.

 Assumptions
 The three given arrays are not null and have length of at least 1
 Examples
 A = {1, 3, 5}, B = {8, 2}, C = {3}, target = 14, return true(pick 3 from A, pick 8 from B and pick 3 from C)
 */

#include <vector>
#include <iostream>
using namespace std;

// 外层从a入手，内层的index left从b的最左侧开始，index right从c的最右侧开始，往中间iterate
bool exist(vector<int> a, vector<int> b, vector<int> c, int target) {
    if(a.empty() || b.empty() || c.empty()){
        return false;
    }
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    for(int i=0; i<a.size(); ++i){
        int cur = target - a[i];
        int left = 0;
        int right = c.size() - 1;
        while(left<b.size() &&  right>=0){
            if(b[left] + c[right] == cur){
                return true;
            }else if(b[left] + c[right] < cur){
                left++;
            }else{
                right--;
            }
        }
    }
    return false;
}