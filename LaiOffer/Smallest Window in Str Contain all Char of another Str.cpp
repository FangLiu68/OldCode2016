//
//  Smallest Window in Str Contain all Char of another Str.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Find the smallest window in a string containing all characters of another string
 Given two strings s1 and s2, find the shortest substring in s1 containing all characters in s2.
 For Example:
 s1= “The given test strings”
 s2: “itst”
 Output string: “t stri”

 Two hash_table
 h1:  store <key = char, value = counter>
 <i, 1>
 <t, 2>
 <s,1>
 global_count = 4 = s2.size()   // initially
 0
 int start = 0 //x
 int minlen  = s.length() + 1;
 h2:
	 s1= “xx  The given test strings”
 Scan s1,             j
                                         i
 // int i = 0; //use index i to go over s, if s[i] is in hashmap, reduce occurrence by 1. if the occurrent of s[i] - 1 is >=0, global cnt--; else we do not reduce global cnt
 while (cnt == 0), that means we find all char in the string, then we start to move index j until global cnt > 0. That means if map contains s[j] and the occurrence + 1 if > 0 (which means if we exclude the char in the res, this must be the start of temp result) temp result will be s.substring(j, i + 1) compare to and replace the result. global cnt ++, quit while loop.
 while (cnt == 0) {
 char c = s.charAt(start);
 if (need.containsKey(c)) {
 need.put(c, need.get(c) + 1);
 if (need.get(c) > 0) {
 cnt++;
 //….if 
 }
	}
 start++;
 }

 */