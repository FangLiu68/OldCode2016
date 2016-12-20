//
//  Min Num of Replacements to Seperate Elem.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/3/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 String containing only ‘a’ or ‘b’, for example, “aaabbab”. we want to replace some of the ‘a’ with ‘b’ and/or some of the ‘b’ with ‘a’, so that the result String has all ‘a’s at the left side and all ‘b’s at right side.
 What is the minimum number of replacements?
 “aaabbab” → replace the last ‘a’ with ‘b’ → “aaabbbb”
 */

/*
 aa  |  abbab
 aaab | bab
 aaa | bbab
 
 aaa b bab
 does not matter if the blue element is ‘a’ or ‘b’.
 
 left_b[i] = num of ‘b’s on the left side of index i, exclude index i
 right_a[i] = num of ‘a’ on the right side of index i, exclude index i
 num_replacement[i] = left_b[i] + right_a[i];
 
 public int conversion(String str) {
	int len = str.length();
 int[] a = new int[len]; // exclusive
 int[] b = new int[len]; // exclusive
 a[0] = 0;
 for (int i = 1; i < len; i++) {
	if (str.charAt(i - 1) == ‘b’ ) {
 a[i] = a[i - 1] + 1;
	} else {
 a[i] = a[i - 1;]
	}
 }
 b[len - 1] = 0;
 for (int i = len - 2; i >= 0; i--) {
	if (str.charAt(i + 1) == ‘a’ ) {
 b[i] = b[i + 1] + 1;
	} else {
 b[i] = b[i + 1];
	}
 }
 
 int min = len;
 for (int i = 0; i < len; i++) {
 min = Math.min(min, a[i] + b[i]);
 }
 return min;
 }
 
 Space Optimization: O(n) → O(1)
 
 b[i] = num of ‘a’ on the right side of index i, exclude index i
 b’[i] = num of ‘a’ on the left side of index i, include index i
 
 b[i] = total_num_a - b’[i]
 
 Homework 1

 */