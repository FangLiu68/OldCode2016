//
//  permutation with dup.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a string with possible duplicate characters, return a list with all permutations of the characters.

 Examples
 Set = “abc”, all permutations are [“abc”, “acb”, “bac”, “bca”, “cab”, “cba”]
 Set = "aba", all permutations are ["aab", "aba", "baa"]
 Set = "", all permutations are [""]
 Set = null, all permutations are []
 */

#include "Header.h"

void swap_permuII(string& input, int i, int index);
void helper_permutation_withDup(string& input, vector<string>& res, int index);
vector<string> permutation_withDup(string input) {
    vector<string> res;
    if(input.empty()){
        res.push_back("");
        return res;
    }
    int index = 0;
    helper_permutation_withDup(input, res, index);
    return res;
}
/*
 // permutation
 public void permutation(String remain, String ans) {
	// base case
	if (remain.length() == 0) {
        System.out.println(ans);
	}

	HashSet<Character> sh = new HashSet<Character>();
	for (int i = 0; i < remain.length(); i++) {
        if (sh.contains(remain.charAt(i)) ){
            continue;
        }
        sh.put(remain.charAt(i));
        // remove the selected char
  		String newInput = remain.substring(0, i);// substring before i
 		newInput += remain.substring(i+1, remain.length());
 		permutation(newInput, ans + remain.charAt(i));
	}
 }

 */
// 在for()循环之外定义一个hashset
void helper_permutation_withDup(string& input, vector<string>& res, int index){
    if(index == input.size()){
        res.push_back(input);
        return;
    }
    unordered_set<char> tmp;
    for(int i=index; i<input.size(); ++i){
        if(tmp.find(input[i]) == tmp.end()){
            tmp.insert(input[i]);
            swap_permuII(input, i, index);
            helper_permutation_withDup(input, res, index+1);
            swap_permuII(input, i, index);
        }
    }
}

void swap_permuII(string& input, int i, int index){
    if(i == index) return;
    char tmp = input[i];
    input[i] = input[index];
    input[index] = tmp;
}