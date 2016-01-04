//
//  Print Matrix Clockwise.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/9/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a matrix of m × n elements (m rows, n columns), return all elements of the matrix in spiral order.
 For example, Given the following matrix:
 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
 ]
 You should return [1,2,3,6,9,8,7,4,5].
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 1[0][0]    2                          3                       4   5
 16         17[offset =1][offset=1]   18                       19  6
 15         24                        25[offset=2, offset=2]   20  7
 14         23                        22                       21  8
 13         12                        11                       10  9
 */
/*
// offset is the [x] and [y] cooridnates of the upper-left cornner of the box
void sprialprint(int[][] a, int offset, int size, int counter) {
    if (size <= 1)
        print matrix  // base case

    for(i = 0; i < size-1; i++) {   // size == 5;   upper row
            a[offset][i] = counter++;
    }

    for(i = 0; i< size; i++)   // right column
    for     // bottom row (from right to left)
    for    //  left column

    //recursive rule
    spiralprint(a, offset + 1, size - 2, counter);
}*/

#define N_MAX 10
void print_spiral(int mat[][N_MAX], int m, int n, int offset) {
    // base case
    if (m <= 0 || n <= 0)
        return;
    if (m == 1) {
        for (int j = 0; j < n; j++)
            cout << mat[offset][offset+j] << " ";
        return;
    }
    if (n == 1) {
        for (int i = 0; i < m; i++)
            cout << mat[offset+i][offset] << " ";
        return;
    }

    for (int j = 0; j < n - 1; j++) // print from top left
        cout << mat[offset][offset+j] << " ";

    for (int i = 0; i < m - 1; i++) // print from top right
        cout << mat[offset+i][offset+n-1] << " ";

    for (int j = 0; j < n - 1; j++) // print from bottom right
        cout << mat[offset+m-1][offset+n-1-j] << " ";

    for (int i = 0; i < m - 1; i++) // print from bottom left
        cout << mat[offset+m-1-i][offset] << " ";

    print_spiral(mat, m-2, n-2, offset+1);
}

void print_spiral_helper(int mat[][N_MAX], int m, int n) {
    print_spiral(mat, m, n, 0);
}

//======================================================

// time complexity O(N^2), space complexity O(1)
vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> res;
    if(matrix.empty()) return res;
    int beginX = 0;
    int endX = matrix.size()-1;
    int beginY = 0;
    int endY = matrix[0].size()-1;
    // 由beginX,beginY的每次+1 和 endX,endY的每次减一，来缩小圆圈
    while(1){
        for(int i=beginY; i <= endY; i++) // from left to right
            res.push_back(matrix[beginX][i]);
        beginX++;
        if(beginX > endX) break;

        for(int i=beginX; i <= endX; i++) // from top to bottom
            res.push_back(matrix[i][endY]);
        endY--;
        if(endY < beginY) break;

        for(int i=endY; i >= beginY; i--) // from right to left
            res.push_back(matrix[endX][i]);
        endX--;
        if(endX < beginX) break;

        for(int i=endX; i >= beginX; i--) // from bottom to top
            res.push_back(matrix[i][beginY]);
        beginY++;
        if(beginY > endY) break;
    }
    return res;
}