//
//  One Edit Distance.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/19/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Given two strings S and T, determine if they are both one edit distance apart.

#include <string>
#include <iostream>
using namespace std;

/*
 Hint:
 1. If | n – m | is greater than 1, we know immediately both are not one-edit distance apart.
 2. It might help if you consider these cases separately, m == n and m ≠ n.
 3. Assume that m is always ≤ n, which greatly simplifies the conditional statements.
 If m > n, we could just simply swap S and T.
 4. If m == n, it becomes finding if there is exactly one modified operation. 
    If m ≠ n, you do not have to consider the delete operation. Just consider the insert operation in T.

 Solution:
 Let us assume m = length of S, n = length of T.
 Although this problem is solvable by directly applying the famous Edit distance dynamic programming algorithm with runtime complexity of O(mn) and space complexity of O(mn) (could be optimized to O(min(m,n)), it is far from desirable as there exists a simpler and more efficient one-pass algorithm.
 O(n) runtime, O(1) space – Simple one-pass:
 
 For the case where m is equal to n, it becomes finding if there is exactly one modified
 character. Now let’s assume m ≤ n. (If m > n we could just swap them).
 
 Assume X represents the one-edit character. There are three one-edit distance operations
 that could be applied to S.
 i. Modify operation – Modify a character to X in S.
    S = “abcde” 
    T = “abXde”

 ii. Insert operation – X was inserted before a character in S.
    ￼￼￼￼￼￼￼￼￼￼S = “abcde” 
    T = “abcXde”

 iii. Append operation – X was appended at the end of S.
 ￼￼   S = “abcde” 
    T = “abcdeX”
 ￼￼￼￼￼
 We make a first pass over S and T concurrently and stop at the first non-matching character between S and T.
 1. If S matches all characters in T, then check if there is an extra character at the end of T. (Modify operation)
 2. If | n – m | == 1, that means we must skip this non-matching character only in T and make sure the remaining characters between S and T are exactly matching. (Insert operation)
 3. If | n – m | == 0, then we skip both non-matching characters in S and T and make sure the remaining characters between S and T are exactly matching. (Append operation)
 */

bool isOneEditDistance(string s, string t){
    int m = s.size();
    int n = t.size();
    if(m > n){
        return isOneEditDistance(t, s);
    }
    if(n-m > 1){
        return false;
    }

    int i=0;
    int shift = n-m;
    while(i<m && s[i]==t[i]){
        i++;
    }
    if(i==m){
        return shift>0;
    }
    if(shift == 0){
        i++; // 如果两个str长度相同，skip both non-matching char in s and t
    }
    // otherwise, only skip the non-matching char in t
    while(i<m && s[i]==t[i+shift]){
        i++;
    }
    return i == m;
}

