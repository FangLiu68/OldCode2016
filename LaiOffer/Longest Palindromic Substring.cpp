//
//  longest_palindromic_substr.cpp
//  LeetCode
//
//  Created by Fang Liu on 8/2/14.
//  Copyright (c) 2014 Fang Liu. All rights reserved.
//

/*
 Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */

#include <iostream>
#include <string>
using namespace std;

/*
 A simpler approach, O(N^2) time and O(1) space:

 We observe that a palindrome mirrors around its center.
 Therefore, a palindrome can be expanded from its center, and there are only 2N-1 such centers.

 You might be asking why there are 2N-1 but not N centers?
 The reason is the center of a palindrome can be in between two letters.
 Such palindromes have even number of letters (such as “abba”) and its center are between the two ‘b’s.

 Since expanding a palindrome around its center could take O(N) time, the overall complexity is O(N^2).
 */

// 以每个字符为中心，左右看他有没有可能是回文
string expandAroundCenter(string s, int c1, int c2){
    int left = c1, right = c2;
    while(left >= 0 && right <= s.size()-1 && s[left]==s[right]){
        left--;
        right++;
    } // 此时(left+1, right-1)区间内是回文
    return s.substr(left+1, right-left-1);
}

string longestPalindrome(string s){
    if(s.empty()) return "";
    string longest = s.substr(0, 1); // a single char itself is a palindrome
    for(int i=0; i < s.size()-1; i++){
        string p1 = expandAroundCenter(s, i, i);
        string p2 = expandAroundCenter(s, i, i+1);
        string p = (p1.size() > p2.size())? p1 : p2;
        longest = (p.size() > longest.size())? p : longest;
    }
    return longest;
}