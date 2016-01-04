//
//  Largest Square of 1s in Matrix.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/13/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 What is the edge length of the largest square of 1’s in a given binary matrix. In this case, your solution should return 3 (3x3 square).
   cl    cr
 0 0 0 0 0   rt 0
 1 1 1 1 0           1
 1 1 1 1 0
 1 1 1 0 0   rb 3
 1 1 1 0 0		    4
 */

#include <iostream>
using namespace std;

/*
 Base case:
 size = 1
 1

 size =2
 1 1
 1 1

 size =3
 1 1 1
 1 1 1
 1 1 1

 size =4
 1 1 1 1
 1 1 1 1
 1 1 1 1
 1 1 1 X =1    
 in order to figure out what the largest size of the square with the 1 M[i][j] as the bottom right corner
 1+ min(M[i-1][j], M[i-1][j-1], M[i][j-1])

 Time = O(n^2)
 */