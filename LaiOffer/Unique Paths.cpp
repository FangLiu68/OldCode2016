//
//  Unique Paths.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/27/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//


/*
 A robot is located at the top-left corner of a m * n grid.
 The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid.
 How many possible unique paths are there?
 
 Note: m and n will be at most 100.
 */

#include <vector>
#include <iostream>
using namespace std;

int uniquePaths(int m, int n) {
    if(m<1 || n<1){
        return 0;
    }
    
    vector<int> paths(n, 1);
    
    for(int i=1; i<m; ++i){
        for(int j=1; j<n; ++j){
            paths[j] = paths[j] + paths[j-1];
        }
    }
    
    return paths[n-1];
}