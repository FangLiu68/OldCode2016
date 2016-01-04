//
//  rotate_image.cpp
//  LeetCode
//
//  Created by Fang Liu on 8/11/14.
//  Copyright (c) 2014 Fang Liu. All rights reserved.
//

/*
 Given an image represented by an N*N matrix, where each pixel in the image is 4 bytes, write a method to rotate teh image by 90 degrees. Can you do this in place?
 */

#include "Header.h"

void rotate(vector<vector<int>>& input){
    if(input.empty() || input[0].empty()) return;

    int n = input.size();

    // top和right不包含offset
    // 只有last-offset
    for(int layer = 0; layer < n/2; ++layer){
        int first = layer; // index of first element in the row
        int last = n - 1 - layer; // index of last element in the row
        for(int i = first; i < last; ++i){ // 每行只挪动除了最后一个element之外的前几个 [first, last)
            int offset = i - first;
            // save top
            int top = input[first][i];

            // left -> top
            input[first][i] = input[last-offset][first];

            // bottom -> left
            input[last-offset][first] = input[last][last-offset];

            // right -> bottom
            input[last][last-offset] = input[i][last];

            // top -> right
            input[i][last] = top;
        }
    }
}

void rotate_(vector<vector<int>>& matrix){
    if(matrix.empty()) return;
    int n = matrix.size();
    for(int offset = 0; offset < n/2; ++offset){
        for(int i=offset; i < n-1-offset; ++i){
            int tmp = matrix[offset][i];
            matrix[offset][i] = matrix[n-1-i][offset];
            matrix[n-1-i][offset] = matrix[n-1-offset][n-1-i];
            matrix[n-1-offset][n-1-i] = matrix[i][n-1-offset];
            matrix[i][n-1-offset] = tmp;
        }
    }
}

/*
 原矩阵               转置矩阵             旋转90
 00 01 02 03         00 10 20 30         30 20 10 00
 10 11 12 13         01 11 21 31         31 21 11 01
 20 21 22 23         02 12 22 32         32 22 12 02
 30 31 32 33         03 13 23 33         33 23 13 03


 有两个思路：
 1 原矩阵计算出各个数值在新矩阵中的位置，然后一步到位转换成新的旋转矩阵
 2 原矩阵到转置矩阵是很容易计算的，那么从转置矩阵到选择矩阵就只需要reverse每行的元素就可。
 个人觉得还是第二种方法更为清晰一点。
 time compleixty O(N^2), space complexity O(1)
 */


// 思路2
/*
 1. 把第一行与第一列互换，然后翻转第一行
 2. 把第二行与第二列互换，然后翻转第二行
 ...
 注意：都是沿着左上到右下的斜轴线互换，轴线上的元素不动
 第一行和第一列从01 10开始互换；互换完毕后翻转第一行
 第二行和第二列从12 21开始互换；互换完毕后翻转第二行
 第三行和第三列从23 32开始互换；互换完毕后翻转第三行
 结束互换；翻转第四行
 */
void rotate2(vector<vector<int> > &matrix){
    int n = matrix.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++)
            swap(matrix[i][j], matrix[j][i]);
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// 思路1
void rotate1(vector<vector<int> > &matrix){
    for (int i = 0, j = matrix.size()-1; i < j; i++, j--){
        for (int k = i, d = j; k < j; k++, d--){
            int t = matrix[i][k];
            matrix[i][k] = matrix[d][i];
            matrix[d][i] = matrix[j][d];
            matrix[j][d] = matrix[k][j];
            matrix[k][j] = t;
        }
    }
}


// 先沿着副对角线反转，再沿着水平中线反转