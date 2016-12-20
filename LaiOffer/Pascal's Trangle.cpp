//
//  Pascal's Triangle.cpp
//  LeetCode
//
//  Created by Fang Liu on 12/9/14.
//  Copyright (c) 2014 Fang Liu. All rights reserved.
//

/*
 Given numRows, generate the first numRows of Pascal's triangle.

 For example, given numRows = 5,
 Return
 [
        [1],
       [1,1],
      [1,2,1],
     [1,3,3,1],
    [1,4,6,4,1]
 ]

 思路：
 下一行的第一个元素和最后一个元素赋值为1，中间的每个元素，等于上一行的左上角和右上角元素之和。
 即a[i][j]=a[i-1][j-1]+a[i-1][j]
 注意：vector<int>(10,1)表示里面有10个元素，每个元素的值为1
 */


#include <vector>
#include <iostream>
using namespace std;

// O(n^2) runtime, O(n) space
/*
 1. push the first row into result
 2. from second row to numRows, iterate to create new rows
    there are total numRows elements in each row
    and we initiate all number as value 1
 3. for each row, except first and last element, cur[j] = pre[j-1] + pre[j]
    since there are total i elements on each row, so last element index is i-1, so j vary from [1, i-1)
 */
vector < vector <int> > generate(int numRows){
    vector < vector <int> > res;
    res.push_back(vector <int>(1,1)); // first row
    for(int i=2; i <= numRows; i++){
        vector <int> cur(i, 1); // 当前行，一共有i个元素，每个元素值为1
        vector <int> pre = res[i-2]; // 上一行
        for(int j=1; j < i-1; j++)
            cur[j] = pre[j-1] + pre[j]; // 当前行的值等于上一行的左上角+右上角值之和
        res.push_back(cur);
    }
    return res;
}

void print_pascal(int n){
    vector<vector<int>> res;
    if(n <= 0){
        return ;
    }
    res.push_back(vector<int>(1,1)); // first row
    cout << 1 << endl;
    for(int i=2; i<=n; ++i){
        vector<int> pre = res[i-2]; // pre row
        vector<int> cur(i, 1);
        for(int j=1; j<i-1; ++j){
            cur[j] = pre[j-1]+pre[j];
        }
        for(int j=0; j<i; ++j){
            cout << cur[j] << " ";
        }
        cout << endl;
        res.push_back(cur);
    }
}
/*
int main(){
    print_pascal(10);
    return 0;
}*/