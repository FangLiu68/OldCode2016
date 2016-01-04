//
//  Longest Common Subsequence btw two strings.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Find the longest common substring of two given strings.
 Assumptions: The two given strings are not null
 Examples
 S = “abcde”, T = “cdf”, the longest common substring of S and T is “cd”
 */

/*
 要求longest substring，那么solution中的字母必须相连

 Example,   student & sweden, then return “den”.
 A[] = sweden;
 B[] = student;

 First: Primitive idea:
 s w e d e n          size = n
 s t u d e n t        size = m
 (1)for sweden, how many substrings are there????
    O(n^2) substrings in sweden
 (2) for each substring of sweden, we check whether this substring is in student. if YES, we check whether it is the longest so far.

 index = 0 1 2 3 4 5 6 7
           s t u d e n t
 sweden    1 == 1
           s
                 d
                 d e=2
                 d e n=2+1
 repeated computation: 
 for each letter as the last letter of the substring, when we increase the substring by one, we need to the repeated comparison for all its prefix
                  i
 B[] = student    dfddf;
 A[] = sweden  d;
               j

 For all DP problems, we care about
 Base case:
 Induction rule (subproblem size(n-1)  → size (n):

 Main idea:
 M[i][j] represents:  
 use the letter at A[i] as the last letter of A[] and use the letter at B[j] as the last letter of B[], 
 what is the length of the common substring in this case (including A[i] and B[j]).

 M[i][j] = M[i-1][j-1] + 1 (if a[i] == b[j])
         = 0               (otherwise)

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

 填表
 ind_j 0 1 2 3 4 5 6 7
 i       s t u d e n t
 0     0 0 0 0 0 0 0 0
 1 s   0 1 0 0 0 0 0 0
 2 w   0 0 0 0 0 0 0 0
 3 e   0 0 0 0 0 1 0 0
 4 d   0 0 0 0 1 0 0 0
 5 e   0 0 0 0 0 2 0 0
 6 n   0 0 0 0 0 0 3 0
 */