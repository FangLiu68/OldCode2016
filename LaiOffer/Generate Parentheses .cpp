//
//  All Valid Permutations Of Parentheses.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given N pairs of parentheses “()”, return a list with all the valid permutations.

 Assumptions
 N >= 0
 Examples
 N = 1, all valid permutations are ["()"]
 N = 3, all valid permutations are ["((()))", "(()())", "(())()", "()(())", "()()()"]
 N = 0, all valid permutations are [""]
 */

#include "Header.h"

/*
 DFS 基本方法：
 what does it store on each level? (每层代表什么意义？一般来讲解题之前就知道DFS要recurse多少层)
 6 levels, for each level we try to put one ( or ) on that level
 How many different states should we try to put on this level? （每层有多少个状态/case 需要try？
 two states to try out from each node
 
 try同一层的不同状态时，只要其中一个状态是添加了新元素，则在try另一个状态时，一定要把这个新元素去掉再try
 */


void helper_permutation(int num, int left, int right, string solution, vector<string>& res);
vector<string> valid_permutation(int num) {
    vector<string> res;
    if(num<=0) return res;
    string solution;
    helper_permutation(num, 0, 0, solution, res);
    return res;
}

// left = how many ( we already have
// right = how many ) we already have
// only when we have some ( left, we can append (
// only when we have less ) than (, we can append )
void helper_permutation(int num, int left, int right, string solution, vector<string>& res){
    if(num*2 == left+right){
        res.push_back(solution);
        return;
    }
    // try to put '('
    if(left < num){
        solution.push_back('(');
        helper_permutation(num, left+1, right, solution, res);
        solution.pop_back();
    }
    // try to put ')'
    if(left > right){
        solution.push_back(')');
        helper_permutation(num, left, right+1, solution, res);
        solution.pop_back();
    }
}