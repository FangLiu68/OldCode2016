//
//  Num of Possible Triangles.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Q1. Given an unsorted array of positive integers. Find the number of triangles that can be
 formed with three different array elements as three sides of triangles.

 For example, if the input array is {4, 6, 3, 7}, the output should be 3. There are three triangles possible {3, 4, 6}, {4, 6, 7} and {3, 6, 7}. Note that {3, 4, 7} is impossible
 */

#include "Header.h"

/*
 solution 1: DFS find all the possible 3 elements triangles from the input array, then iterate the above solution, to find the counts of right triangles (smallest + middle > biggest)
 time complexity:
 

 solution 2: sort the array, use move three pointers to get the possible result
 */