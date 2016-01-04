//
//  set_matrix_zeroes.cpp
//  LeetCode
//
//  Created by Fang Liu on 8/11/14.
//  Copyright (c) 2014 Fang Liu. All rights reserved.
//

// Write an algorithm such that if an element in an M*N matrix is 0, its entire row and column are set to 0.

#include "Header.h"

/*
 不能从最外面的element一个一个对应着设置其行和列都为0.因为这样下去整个Matrix都会变成0.
 将matrix的最外面一行和最外面一列当成tag用。如果matrix[i][0]中有0，就先标记着，同样对于matrix[0][i]的情况。
 然后对于所有的matrix[m-1][n-1]的element，如果有任何一个是0，就对这一行的第一个元素和这一列的第一个元素标记为0.
 go through matrix的第一行和第一列，如果有0，就对所有的相对应的行列(除了第一行第一列)都标为0。
 最后看第一步标记的第一行中是否原本存有0的情况，如果有，就对第一行和第一列标记为0.
 */
/*
 we can use the first column to represent which row we need to set to full zero,
 and use the first row to record which column we need to set to full zero.
 By doing that, we don't need extra space to record those flags! The space complexity is O(1).

 use col 0 to record rows which need to set to zero
 use row 0 to record cols which need to set to zero
 by this way, you saved space!
 which means, set the first node in row i to zero when there's a node in row i is zero;
 set the first node in column j to zero when there's a node in column j is zero;

 search from row 1 and column 1, if the first node in that row/column is zero,
 set the whole row/column is zero
 */

// time complexity O(m*n), space complexity O(1)
void setMatrixValue(int** mat, int mrow, int ncol){
    bool row0 = false;
    bool col0 = false;
    // 如果这行有0，标记上
    for(int i=0; i<mrow; i++){
        if(mat[i][0]==0) {
            row0 = true;
            break;
        }
    }
    // 如果这列有0，标记上
    for(int i=0; i<ncol; i++){
        if(mat[0][i]==0)  {
            col0 = true;
            break;
        }
    }
    // 从第一行和第一列开始，如果中间某个数为0，就把他对应的第0行和第0列标记上为0
    for(int i=1; i<mrow; i++){
        for(int j=1; j<ncol; j++){
            if(mat[i][j]==0){
                mat[i][0] = 0;
                mat[0][j] = 0;
            }
        }
    }
    // 从第一行和第一列开始，如果在第零行和第零列有被标记为0，则把中间的所对应的数置零
    for(int i=1; i<mrow; i++){
        for(int j=1; j<ncol; j++){
            if(mat[i][0]==0 || mat[0][j]==0)
                mat[i][j]=0;
        }
    }
    // 最后再看第零行和第零列，如果最开始的时候我们检测的里面有零，现在再把整个第零行第零列置零
    if(row0)    for(int i=0; i<mrow; i++)   mat[i][0]=0;
    if(col0)    for(int i=0; i<ncol; i++)   mat[0][i]=0;
}