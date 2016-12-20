//
//  Triangle.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/25/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//


/*
 Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 For example, given the following triangle
 [
 [2],
 [3,4],
 [6,5,7],
 [4,1,8,3]
 ]
 The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 
 Note:
 bonums point if you are able to do this using only O(n) extra space, where n is the total number of rows in teh triangle.
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 存储每一层的结果，来计算下一层。
 用两个数组prePath和curPath分别存储上一层和本层的每个坐标的min path sum. 如果已知prePath，可以计算curPath
 
 1. 对于第index=i层，有i+1个数 (i从0开始)。上一层有i个数
 2. 除去头尾两个数之外，curPath[i] = min(prePath[i-1], prePath[i]) + triangle[i][j]
 3. 头尾的特殊情况：curPath[0] = prePath[0] + triangle[i][0]
 4. 在计算下一层前，需要交换prePath和curPath
 5. 在最后一层curPath计算结束后，在其中找一个最小值即为整个树的min path sum
 
 额外存储空间是O(2N)
 */


/*
 在三角形的第level行（level从0开始），一共有level+1个元素
 
 每行有level+1个元素，故i的取值范围为[0,level].
 curPath[i]: 到本行的第i个元素为止所得到的min path sum(include the ith element)
 curPath[0]存储从上往下走到本行的第一个元素所得到的min path sum;
 curPath[level]存储从上往下走到本行的最后一个元素所得到的min path sum.
 除了第一个和最后一个元素之外，本行中间的到每个坐标的min path sum都遵循以下原则：
 curPath[i] = min(prePath[i-1], prePath[i]) + triangle[level][i]
 
 time complexity O(n^2), space complexity O(2n)
 */
int minimumTotal(vector<vector<int>>& triangle) {
    if(triangle.empty()){
        return INT_MIN;
    }
    
    if(triangle.size() == 1){
        return triangle[0][0];
    }
    
    int n = triangle.size();
    vector<int> curPath(n, 0);
    vector<int> prePath(n, 0);
    
    curPath[0] = triangle[0][0];
    
    for(int level = 1; level < n; ++level){
        prePath = curPath;
        curPath[0] = prePath[0] + triangle[level][0];
        curPath[level] = prePath[level-1] + triangle[level][level];
        for(int i=1; i<level; ++i){
            curPath[i] = min(prePath[i-1], prePath[i]) + triangle[level][i];
        }
    }
    
    int minPath = INT_MAX;
    for(int i=0; i<n; ++i){
        minPath = min(minPath, curPath[i]);
    }
    
    return minPath;
}