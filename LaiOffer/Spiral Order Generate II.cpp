//
//  Spiral Order Generate II.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/3/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Generate an M * N 2D array in spiral order clock-wise starting from the top left corner, using the numbers of 1, 2, 3, …, M * N in increasing order.

 Assumptions
 M >= 0, N >= 0
 Examples
 M = 3, N = 4, the generated matrix is
 { {1,  2,  3,  4}
   {10, 11, 12, 5}
   {9,  8,  7,  6} }
 */

#include <vector>
#include <assert.h>
#include <iostream>
using namespace std;

vector<vector<int> > spiral_generateII(int rows, int cols) {
    assert(rows>0 && cols>0);
    vector<vector<int>> matrix(rows, vector<int>(cols));
    int top = 0, bottom = rows-1;
    int left = 0, right = cols-1;
    int cur = 1;
    while(top<bottom && left<right){
        for(int i=left; i<=right; ++i){
            matrix[top][i] = cur++;
        }
        for(int j=top+1; j<=bottom-1; ++j){
            matrix[j][right] = cur++;
        }
        for(int i=right; i>=left; --i){
            matrix[bottom][i] = cur++;
        }
        for(int j=bottom-1; j>=top+1; --j){
            matrix[j][left] = cur++;
        }
        top++, bottom--;
        left++, right--;
    }
    if(top>bottom || left>right){
        return matrix;
    }
    if(top == bottom){
        for(int i=left; i<=right; ++i){
            matrix[top][i] = cur++;
        }
    }else{
        for(int i=top; i<=bottom; ++i){
            matrix[i][left] = cur++;
        }
    }
    return matrix;
}

