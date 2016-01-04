//
//  Spiral Order Generate I.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/3/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Generate an N * N 2D array in spiral order clock-wise starting from the top left corner, using the numbers of 1, 2, 3, …, N * N in increasing order.
 Assumptions
 N >= 0
 Examples
 N = 3, the generated matrix is
 { 
 {1,  2,  3}
 {8,  9,  4},
 {7,  6,  5}
 }
 */

#include <iostream>
using namespace std;

// spiral order(clock-wise) generate matrix with specified rows and columns.
// the number is starting from 1.
int** spiralGenerate(int row, int col){
    if(row<=0 || col<=0) return NULL;
    int** matrix = new int*[row];
    for(int i=0; i<row; i++)
        matrix[i] = new int[col];
    int top = 0;
    int bottom = row-1;
    int left = 0;
    int right = col-1;
    int cur = 1;
    while(top<bottom && left<right){
        for(int i=left; i<=right; i++)
            matrix[top][i] = cur++;
        for(int i=top+1; i<=bottom-1; i++)
            matrix[i][right] = cur++;
        for(int i=right; i>=left; i--)
            matrix[bottom][i] = cur++;
        for(int i=bottom-1; i>=top+1; i--)
            matrix[i][left] = cur++;
        top++,bottom--;
        left++, right--;
    }
    if(top>bottom || left>right)
        return matrix;
    if(top == bottom){
        for(int i=left; i<=right; i++)
            matrix[top][i] = cur++;
    }
    else{
        for(int i=top; i<=bottom; i++)
            matrix[i][left] = cur++;
    }
    return matrix;
}

//=================================
/*
 Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 For example,
 Given n = 3,
 You should return the following matrix:
 [
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
 ]
 */

#include <vector>
#include <iostream>
using namespace std;

// O(n^2) runtime, O(n^2) space 用这个方法，更清楚。
vector<vector<int> > generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    if(n<=0) return matrix;
    int beginX = 0, endX = n-1;
    int beginY = 0, endY = n-1;
    int num = 1;
    while(beginX <= endX && beginY <= endY){
        for(int i=beginY; i<=endY; i++) matrix[beginX][i] = num++;
        beginX++;
        for(int i=beginX; i<=endX; i++) matrix[i][endY] = num++;
        endY--;
        for(int i=endY; i>=beginY; i--) matrix[endX][i] = num++;
        endX--;
        for(int i=endX; i>=beginX; i--) matrix[i][beginY] = num++;
        beginY++;
    }
    return matrix;
}

// time complexity O(N^2), space complexity O(N^2)
vector<vector<int>> generateMatrix1(int n){
    vector<vector<int>> matrix(n, vector<int>(n));
    int begin = 0;
    int end = n-1;
    int num = 1;
    while(begin < end){
        for(int j=begin; j<end; j++)  matrix[begin][j] = num++;
        for(int i=begin; i<end; i++)  matrix[i][end] = num++;
        for(int j=end; j>begin; j--)  matrix[end][j] = num++;
        for(int i=end; i>begin; i--)  matrix[i][begin] = num++;
        begin++, end--;
    }
    if(begin == end) matrix[begin][end] = num;
    return matrix;
}