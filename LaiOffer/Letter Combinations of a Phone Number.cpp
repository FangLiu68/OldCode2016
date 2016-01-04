//
//  Letter Combinations of a Phone Number.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/19/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a digit string, return all possible letter combinations that the number could represent.

 A mapping of digit to letters (just like on the telephone buttons) is given below.

 Input:Digit string "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 Note:
 Although the above answer is in lexicographical order, your answer could be in any order you want.
 */

#include "Header.h"

void generater(string trans[], string& digits, int deep, string& seq, vector<string>& res){
    if(deep == digits.size()){
        res.push_back(seq);
        return;
    }
    int curDig = digits[deep] - 48;
    for(int i=0; i<trans[curDig].size(); ++i){
        seq.push_back(trans[curDig][i]);
        generater(trans, digits, deep+1, seq, res);
        seq.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    string trans[] = {"", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    if(digits.empty()) return res;
    string seq;
    generater(trans, digits, 0, seq, res);
    return res;
}

