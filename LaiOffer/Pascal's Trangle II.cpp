//
//  Pascal's Trangle II.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/29/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an index k, return the kth row of the Pascal's triangle.

 For example, given k = 3,
 Return [1,3,3,1].

 Note:
 Could you optimize your algorithm to use only O(k) extra space?
 
 1. iterate row index from 0 to rowIndex. [0, rowIndex]
 2. generate new index from back to front, and skip the first element (which is 1) and the last element(which will be pushed into vector at last)
    the index we generate is from i-1 to 1. [1, i-1]
    so if rowIndex<=1, do nothing but push 1 into res.
 */

#include <vector>
#include <iostream>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> res;
    if(rowIndex <= 0){
        return res;
    }
    for(int i=0; i<=rowIndex; ++i){
        for(int j=i-1; j>0; --j){
            res[j] = res[j-1]+res[j];
        }
        res.push_back(1);
    }
    return res;
}