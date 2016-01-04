//
//  Combination Sum II.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/21/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

 Each number in C may only be used once in the combination.

 Note:
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 The solution set must not contain duplicate combinations.
 For example, given candidate set 10,1,2,7,6,1,5 and target 8,
 A solution set is:
 [1, 7]
 [1, 2, 5]
 [2, 6]
 [1, 1, 6]
 */

#include <vector>
#include <iostream>
using namespace std;

void helper_comBi2(vector<int>& candidates, vector<vector<int>>& res, vector<int> cur, int gap, int index){
    if(gap < 0){
        return;
    }
    if(gap == 0){
        res.push_back(cur);
        return;
    }

    int pre = -1;
    for(int i=index; i<candidates.size(); ++i){
        if(pre == candidates[i]){
            continue;
        }
        pre = candidates[i]; // 每层往下传的时候，记录已经用过的值
        cur.push_back(candidates[i]);
        helper_comBi2(candidates, res, cur, gap-candidates[i], i+1); // 注意这里是i+1
        cur.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    if(candidates.empty()){
        return res;
    }
    vector<int> cur;
    sort(candidates.begin(), candidates.end());
    helper_comBi2(candidates, res, cur, target, 0);
    return res;
}

