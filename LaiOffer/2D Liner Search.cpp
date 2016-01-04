//
//  2D Liner Search.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/24/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Write an efficient algorithm that searches for a value in an n x m table (two-dimensional array). This table is sorted along the rows and columns — that is,

 Table[i][j] ≤ Table[i][j + 1],
 Table[i][j] ≤ Table[i + 1][j]
 
 即  search for a value in Young's Matrix
 */

#include <iostream>
#include <vector>
using namespace std;

// O(m+n)
bool search_2d(vector<vector<int>> matrix, int target){
    if(matrix.empty() || matrix[0].empty()){
        return false;
    }
    int i = 0;
    int j = matrix[0].size()-1; // 从最右上角开始search
    while(i<matrix.size() && j>=0){
        if(matrix[i][j] == target){
            return true;
        }else if(matrix[i][j] < target){
            i++;
        }else{
            j--;
        }
    }
    return false;
}