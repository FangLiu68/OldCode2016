//
//  Combination Sum Dup.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/21/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

 The same repeated number may be chosen from C unlimited number of times.

 Note:
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 The solution set must not contain duplicate combinations.
 For example, given candidate set 2,3,6,7 and target 7,
 A solution set is:
 [7]
 [2, 2, 3]
 */

#include <vector>
#include <iostream>
using namespace std;

void comSum_helper(vector<int>& candidates, vector<vector<int>>& res, vector<int> cur, int gap, int index){
    if(gap < 0) {
        return;
    }
    if(gap == 0){
        res.push_back(cur);
        return;
    }
    for(int i=index; i<candidates.size(); ++i){
        cur.push_back(candidates[i]);
        comSum_helper(candidates, res, cur, gap-candidates[i], i);
        cur.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    if(candidates.empty()) return res;
    vector<int> cur;
    sort(candidates.begin(), candidates.end());
    comSum_helper(candidates, res, cur, target, 0);
    return res;
}

