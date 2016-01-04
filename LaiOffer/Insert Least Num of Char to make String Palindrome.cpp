//
//  Insert Least Num of Char to make String Palindrome.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
  Insert the least number of characters to a string in order to make the new string a palindrome. Return the least number of characters should be inserted.
 
 
   String input = f“a b c d e f”
 i i+1      j
 void makePalindrom(string s, int left, int right) {
 if (left >= right) {
 return;
	}
	if (s[left] == s[])
 }
 M[i][j] the num of insert needed to make substring(i, j) palindrome
 M[i][j] = M[i+1][j-1]      if (s[i] == s[j])
        = min(M[i + 1][j], M[i][j - 1])    if (s[i] != s[j])
 int makePalindrome(string s) {
 int size = s.size();
 vector<vector<int> > M(size, vector<int> (size, 0));
 for(int i = 0; i < size; ++i) {
 M[i][i] = 0;
 if (S[i] == s[i+1]) {
 M[i][i+1] = 0;
 } else {
 M[i][i+1] = 1;
 }
	}
 for(int i = size - 1; i > 0 ; --i) {
 for(int j = i + 1; j < size; ++j) {
 if (s[i] == s[j]) {
 M[i][j] = M[i + 1][j - 1];
 } else {
 M[i][j] = min(M[i+1][j], M[i][j - 1]) + 1;
 }
 }
	}
	return M[0][size-1];
 }
 M[i][j] represents the least number insertions to make the substring a palindrome.
 0 1 2 3 4
	a b c d e      [i][j]   i <= j   2 3
 0 a  0 1 2 3 4
 1 b  x 0 1 2 3
 2 c  x x 0 1 2    M[2][3] ==??
 3 d  x x x 0 1 start letter is d (index=3),end letter is e (index= 4)   4 e  x x x x 0
 M[i][i] = 0 for all 0<= i <= n-1
 M[i][j] =  M[i+1][j-1]      if(A[i] == A[j]);
 min(M[i+1][j],  M[i][j-1]) + 1;   otherwise
 a b c d e a
 i=0     j=4    M[0][4] ⇐   M[1][4] or M[0][3]
 __ __ __ __
 

 */