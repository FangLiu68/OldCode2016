//
//  subset II.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/14/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a set of characters represented by a String, return a list containing all subsets of the characters.

 Assumptions
 There could be duplicate characters in the original set.
 ​Examples
 Set = "abc", all the subsets are ["", "a", "ab", "abc", "ac", "b", "bc", "c"]
 Set = "abb", all the subsets are ["", "a", "ab", "abb", "b", "bb"]
 Set = "", all the subsets are [""]
 Set = null, all the subsets are []
 */

#include "Header.h"

// 和没有重复元素的方法一样，只是用set提前保存结果去掉重复
void helper_subsetII_str(string input, int cur_level, string tmp, set<string>& _res);
vector<string> subsetII(string input) {
    vector<string> res;
    if(input == " "){
        res.push_back(" ");
        return res;
    }
    set<string> _res;
    string tmp;
    helper_subsetII_str(input, 0, tmp, _res);
    return vector<string>(_res.begin(), _res.end());
}

void helper_subsetII_str(string input, int cur_level, string tmp, set<string>& _res){
    if(input.size() == cur_level){
        _res.insert(tmp);
        return;
    }
    tmp.push_back(input[cur_level]);
    helper_subsetII_str(input, cur_level+1, tmp, _res);
    tmp.pop_back();
    
    helper_subsetII_str(input, cur_level+1, tmp, _res);
}

//============================================================
/*
 Given a collection of integers that might contain duplicates, S, return all possible subsets.

 Note:
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If S = [1,2,2], a solution is:
 [
 [2],
 [1],
 [1,2,2],
 [2,2],
 [1,2],
 []
 ]
 */
void helper_subsetII_int(vector<int>& S, int cur_level, vector<int> tmp, set<vector<int>>& _res);
vector<vector<int> > subsetsWithDup(vector<int> &S) {
    if(S.empty()) return vector<vector<int>>();
    set<vector<int>> _res;
    vector<int> tmp;
    helper_subsetII_int(S, 0, tmp, _res);
    vector<vector<int>> res(_res.begin(), _res.end());
    sort(res.begin(), res.end());
    return res;
}
void helper_subsetII_int(vector<int>& S, int cur_level, vector<int> tmp, set<vector<int>>& _res){
    if(S.size() == cur_level){
        sort(tmp.begin(), tmp.end());
        _res.insert(tmp);
        return;
    }
    tmp.push_back(S[cur_level]);
    helper_subsetII_int(S, cur_level+1, tmp, _res);
    tmp.pop_back();
    helper_subsetII_int(S, cur_level+1, tmp, _res);
}