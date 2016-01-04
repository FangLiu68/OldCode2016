//
//  Largest Cross 1s.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/13/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a Matrix that contains only 1s and 0s, how to find the largest cross
 with the same arm lengths and the two arms join at the central point of each other.
 
 exmaple:
 0100
 1111
 0100
 0100

 largest cross is matrix[1][1]
 */

#include <iostream>
using namespace std;

/*
 Four directions total
 from left to right   M1[][] =
 0100
 1234
 0100
 0100
 from right  to left   M2[][] =
 0100
 4321
 0100
 0100
 3) from top down   M3[][] =
 0100
 1211
 0300
 0400

 4) from bottom up   M4[][] =

 Solution
 For  i
    for  j

	||
 ||
	||
	||
 =====> <===			min(four direction’s length)
	||
	||
 

 */