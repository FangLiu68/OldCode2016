//
//  Largest Set of Points with Positive Slope.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/18/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array of 2D coordinates of points (all the coordinates are integers), find the largest number of points that can form a set such that any pair of points in the set can form a line with positive slope. Return the size of such a maximal set.

 Assumptions
 The given array is not null and is not empty
 Examples
 <0, 0>, <1, 1>, <2, 3>, <3, 3>, the maximum set of points are {<0, 0>, <1, 1>, <2, 3>}, the size is 3.
 */

#include <iostream>
using namespace std;

/*
 step1, sort by x-coordinate and put it in an array A
 step2, in A find the longest increasing subsequence by y-coordinate
 
 Review of LIS problem
 */