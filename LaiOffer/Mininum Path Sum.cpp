//
//  Mininum Path Sum.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/26/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a mxn grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 
 You can only move either down or right at any point in time.
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 二维DP。设数组 A[row][col]
 Min[i][j] = min(Min[i-1][j], Min[i][j-1]) + A[i][j]
 */

int minPathSum(vector<vector<int>>& grid) {
    if(grid.empty()) return INT_MAX;
    
    int row = grid.size();
    int col = grid[0].size();
    
    vector<int> minCol(col, 0);
    vector<vector<int>> minPath(row, minCol);
    
    minPath[0][0] = grid[0][0];
    
    for(int i=1; i<row; ++i){
        minPath[i][0] = minPath[i-1][0] + grid[i][0];
    }
    
    for(int i=1; i<col; ++i){
        minPath[0][i] = minPath[0][i-1] + grid[0][i];
    }
    
    for(int i=1; i<row; ++i){
        for(int j=1; j<col; ++j){
            minPath[i][j] = min(minPath[i][j-1], minPath[i-1][j]) + grid[i][j];
        }
    }
    
    return minPath[row-1][col-1];
}

// 没必要用二维数组，可以用一维滚动数组，不断覆盖上一层结果
int minPathSumI(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    
    vector<int> steps(col, INT_MAX);
    steps[0] = 0;
    
    for(int i=0; i < row; ++i){
        steps[0] = steps[0] + grid[i][0];
        
        for(int j=1; j < col; ++j){
            steps[j] = min(steps[j-1], steps[j]) + grid[i][j];
        }
    }
    
    return steps[col-1];
}