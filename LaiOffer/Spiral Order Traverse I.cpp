//
//  Spiral Order Traverse.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/3/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Traverse an N * N 2D array in spiral order clock-wise starting from the top left corner. Return the list of traversal sequence.

 Assumptions
 The 2D array is not null and has size of N * N where N >= 0
 Examples
 { {1,  2,  3},
 {4,  5,  6},
 {7,  8,  9} }
 the traversal sequence is [1, 2, 3, 6, 9, 8, 7, 4, 5]
 */

#include <iostream>
#include <vector>
using namespace std;

// 用这种方法 不看第二种
vector<int> spiralI(vector<vector<int>> input){
    vector<int> res;
    if(input.empty() || input[0].empty()){
        return res;
    }

    int left = 0;
    int right = input[0].size()-1;
    int up = 0;
    int down = input.size() - 1;

    /* 上下都是全部遍历，左右两边的起始位置都各自-1
     * 然后，上下左右各自增长*/
    while(left < right && up < down){
        for(int i=left; i<=right; ++i){
            res.push_back(input[up][i]);
        }
        for(int i=up+1; i<=down-1; ++i){
            res.push_back(input[i][right]);
        }
        for(int i=right; i>=left; --i){
            res.push_back(input[down][i]);
        }
        for(int i=down-1; i>=up+1; --i){
            res.push_back(input[i][left]);
        }
        left++, right--;
        up++, down--;
    }

    if(left > right || up > down){ // 行数列数相等
        return res;
    }
    if(left == right){ // 行数大于列数
        for(int i=up; i<=down; ++i){
            res.push_back(input[i][right]);
        }
    }else{ // 列数大于行数
        for(int i=left; i<=right; ++i){
            res.push_back(input[up][i]);
        }
    }
    return res;
}


/*
int main(){
    vector<int> v1 = {1};
    vector<int> v2 = {2};
    vector<int> v3 = {3};
    vector<vector<int>> vv = {v1, v2, v3};
    vector<int> res = spiral(vv);
    for(int i=0; i<res.size(); ++i)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}*/