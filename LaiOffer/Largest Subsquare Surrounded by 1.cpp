//
//  Largest Subsquare Surrounded by 1.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/13/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a matrix where every element is either ‘0’ or ‘1’, find the largest subsquare surrounded by ‘1’
 Examples:
 Input: mat[N][N] =
 { 
 {'1', '0',  '1', ‘1', '1'},
 {'1', '1', '1',  '1', '1'},
 {'1', '1', '0',  '1', '0'},
 {'1', '1', '1',  ‘1,’ '1'},
 {'1', '1', '1',  '0', '0'},
 };
 Output: 3
 */

#include <iostream>
using namespace std;

/*
 for each element [i][j], n different size, for each size    n
 time = n^2
 O(n^4).

 { {'1', '0',  '1', ‘1', '1'},
 {'1', '1', '1',  '1', '1'},		from right to left,   最长1问题, upper border
 {'1', '1', '0',  '1', '0'},
 {'1', '1', '1',  ‘1,’ '1'},
 {'1', '1', '1',  '0', '0'},

	from bottom up ， 最长1问题， to determine the left border

 for each element [i][j] as the top-left corner of the square.
 O(n^3)
 */