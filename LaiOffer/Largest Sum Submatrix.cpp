//
//  Largest Sum Submatrix.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/13/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a Matrix of integers (positive & negative numbers & 0s), how to find the submatrix with the largest sum?
 */

#include <iostream>
using namespace std;

/*
 M[i][j] represents the sum of all elements in the sub-matrix with A[0][0] as the top-left corner, and A[i][j] as the bottom-right corner.

 1111111  		blue sum =  M[0][6]
 2222222
 3333333   	SUM[1-3][2-6] =  M[2][6] - M[0][6] - M[2][2] + M[0][2]
 top-left & bottom right corners

 red sum = M[2][2]
 444444444
 How to fill in the M[i][j]

 1111111
 2222222
 3333333

 xxxxxxx
 xxxxxxx
 xxxxxxx


 M[i][j] =
 1234 567
 36912      sum_so_far=4

 O(2) = M[i][j] = M[i-1][j] + sum_so_far_in_this_row

 Total time
 Fill in the M[i][j] takes  O(n^2)
 calculate sum for every single sub_matrix  O(n^4)
 for each matrix, it takes O(4) = O(1)
 Total time = O(n^4)
 */