//
//  Longest Common Substring btw two strings.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Find the longest common subsequence between two strings

/*
 we want to find subsequence, 所以答案中的字母在原string中可以不连续
 A = student
     i
 B = swedenasyt
     j
 那么longest common subsequence btw A and B is: sdent
 
 m[i][j] represents the length of the longest common subsequence of A[1...i], B[1...j]
 m[i][j] = m[i-1][j-1] + 1              (if A[i] == B[j])
         = max(m[i-1][j], m[i][j-1])    (if A[i] != B[j])
           这里其实是max(m[i-1][j], m[i][j-1], m[i-1][j-1])，最后的ma[i-1][j-1]可以省略，因为此部分的结果必然是前面两个结果之一
           对吗？？？？？？问老师
 
 原表
 ind_j 0 1 2 3 4 5 6 7
 i       s t u d e n t
 0     0 0 0 0 0 0 0 0
 1 s   0 0 0 0 0 0 0 0
 2 w   0 0 0 0 0 0 0 0
 3 e   0 0 0 0 0 0 0 0
 4 d   0 0 0 0 0 0 0 0
 5 e   0 0 0 0 0 0 0 0
 6 n   0 0 0 0 0 0 0 0
 7 a   0 0 0 0 0 0 0 0
 8 s   0 0 0 0 0 0 0 0
 9 y   0 0 0 0 0 0 0 0

 填表
 ind_j 0 1 2 3 4 5 6 7
 i       s t u d e n t
 0     0 0 0 0 0 0 0 0
 1 s   0 1 1 1 1 1 1 1
 2 w   0 1 1 1 1 1 1 1
 3 e   0 1 1 1 1 2 2 2
 4 d   0 1 1 1 2 2 2 2
 5 e   0 1 1 1 2 3 3 3
 6 n   0 1 1 1 2 3 4 4
 7 a   0 1 1 1 2 3 4 4
 8 s   0 1 1 1 2 3 4 4
 9 y   0 1 1 1 2 3 4 4
 */

#include <string>
#include <iostream>
using namespace std;

 // Dynamic programming formulation:
 // Let a(i, j) be the length of the longest sub sequence ending at position i - 1
 // in s1, and ending at position j - 1 in s2. (Meaning that both characters are selected.))
 // a(i, j) satisfies:
 // if s[i - 1] == s[j - 1], then a(i, j) = a(i - 1, j - 1) + 1
 // else, a(i, j) = max(a(i - 1, j), a(i, j - 1))
 // i.e., the bigger one of (a) including the current char in s2, not including the current
 // char in s1, and (b) including the current char in s1, not including the current char in s2.

int longest_common_subsequence(string s1, string s2) {
    int res = 0;
    int len1 = s1.length();
    int len2 = s2.length();
    if (len1 == 0 || len2 == 0) return res;
    len1++;
    len2++;
    int a[len1][len2];
    for (int i = 0; i < len1; ++i) {
        for (int j = 0; j < len2; ++j)
            a[i][j] = 0;
    }
    for (int i = 1; i < len1; ++i) {
        for (int j = 1; j < len2; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                a[i][j] = a[i - 1][j - 1] + 1;
                if (a[i][j] > res) res = a[i][j];
            }
            else
                a[i][j] = max(a[i - 1][j], a[i][j - 1]);
        }
    }
    return res;
}