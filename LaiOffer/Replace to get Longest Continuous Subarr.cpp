//
//  Replace to get Longest Continuous Subarr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/13/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Q1.  Given an array with value = 0 or 1s, find an index of 0 to be replaced with 1 such that we can get the longest contiguous subarray of 1s.  Requirements:   Time =  O(n) , space = O(1).
 Example:
 Input:
 arr[] =  {1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1}
 Output:
 Index 9
 Assuming array index starts from 0, replacing 0 with 1 at index 9 causes the maximum continuous sequence of 1s.


 Solution:
 M[i]  represents the longest subarray from 0 to i, including i-th element itself.
 N[i]  represents the longest subarray from 0 to i,  including i-th element itself by adding only one 1 to the latest position of 0.

 M[i]   =  M[i-1] + 1    if A[i] == 1
               0	        else

 N[i]   =	N[i-1] +1      if A[i]  == 1
	        M[i-1]+	1       else

 i
 arr[] =  {1, 1, 0 ,0, 1, 0, 1, 1, 1, 0, 1, 1, 1}
 M[]         1, 2, 0, 0, 1, 0, 1, 2, 3, 0, 1  1  1
 N[]	    1  2  3  1  2  2  3  4  5  4  5  6  7
 
 */