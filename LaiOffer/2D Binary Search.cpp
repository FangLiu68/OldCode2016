//
//  2D Binary Search.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/28/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 2D matrix, sorted on each row, first element of next row is larger(or equal) to the last element of previous row, now giving a target number, returning the position that the target locates within the matrix
 
 Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

 Integers in each row are sorted from left to right.
 The first integer of each row is greater than the last integer of the previous row.
 For example,
 Consider the following matrix:
 [
 [1,   3,  5,  7],
 [10, 11, 16, 20],
 [23, 30, 34, 50]
 ]
 Given target = 3, return true.

 */

#include <vector>
#include <iostream>
using namespace std;

// convert 2D array to 1D array to do the binary search
// log(mn) runtime.
bool search_2D(vector<vector<int>> matrix, int target){
    if(matrix.empty() || matrix[0].empty()) return false;
    int row = matrix.size();
    int col = matrix[0].size();
    int left = 0;
    int right = row*col-1;
    while(left <= right){
        int mid = left+(right-left)/2;
        int index_row = mid / col; // 注意mid的index只和col有关
        int index_col = mid % col;
        if(matrix[index_row][index_col] == target){
            return true;
        }else if(matrix[index_row][index_col] < target){
            left = mid+1;
        }else {
            right = mid-1;
        }
    }
    return false;
}