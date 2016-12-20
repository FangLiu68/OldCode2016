//
//  Unique Paths II.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/27/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Follow up for "Unique Paths":
 Now consider if some obstacles are added to the grids. How many unique paths would there be?
 An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 
 For example,
 There is one obstacle in the middle of a 3*3 grid as illustrated below.
 [
 [0,0,0],
 [0,1,0],
 [0,0,0]
 ]
 The total number of unique paths is 2.
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 和上一题一样的状态转移方程：
 steps[i][j] = steps[i-1][j] + steps[i][j-1]    if A[i][j] == 0
 = 0                                if A[i][j] == 1
 
 1. 当(i, j)有障碍时dp[i][j] = 0
 2. dp[0][j]和dp[i][0]未必为1.
 dp[0][j] = obstacleGrid[0][j] ? 0 : dp[0][j-1]
 dp[i][0] = obstacleGrid[i][0] ? 0 : dp[i-1][0]
 3. 当obstacleGrid [0][0] = 1时，return 0
 */

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();
    if(row <= 0 || col <= 0) return 0;
    if(obstacleGrid[0][0] == 1) return 0;
    
    vector<int> steps(col, 1);
    
    for(int j = 1; j < col; ++j){
        if(obstacleGrid[0][j] == 1){
            steps[j] = 0;
        }else{
            steps[j] = steps[j-1];
        }
    }
    
    for(int i = 1; i < row; ++i){
        steps[0] = obstacleGrid[i][0] == 1? 0 : steps[0];
        for(int j = 1; j < col; ++j){
            steps[j] = obstacleGrid[i][j] == 1? 0 : steps[j]+steps[j-1];
        }
    }
    
    return steps[col-1];
}