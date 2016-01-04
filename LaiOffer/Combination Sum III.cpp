//
//  Combination Sum III.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/22/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

 Ensure that numbers within the set are sorted in ascending order.

 Example 1:
 Input: k = 3, n = 7
 Output:
 [[1,2,4]]

 Example 2:
 Input: k = 3, n = 9
 Output:
 [[1,2,6], [1,3,5], [2,3,4]]
 */

#include <vector>
#include <iostream>
using namespace std;

void helper_comBi3(int k, int gap, vector<vector<int>>& res, vector<int> cur, int index){
    if(gap < 0) return;
    if(gap == 0){
        if(cur.size() == k){
            res.push_back(cur);
        }
        return;
    }
    for(int i=index; i<=9; ++i){
        cur.push_back(i);
        helper_comBi3(k, gap-i, res, cur, i+1);
        cur.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> cur;
    if(n<=0) return res;
    helper_comBi3(k, n, res, cur, 1);
    return res;
}

