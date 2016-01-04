//
//  Num of Values Smaller than Target in Young's Matrix.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/29/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// find number of values <= k in young's matrix
// 相同类型的题：two sorted array, pick one element from each of them, how many pairs has sum <= k.

/*
 -5, -3, 0, 1               3
 -2,  2, 3, 4               1
 -1,  5, 6, 7               1
  0,  6, 7, 9               1
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 1. method 1: same as "smallest k elements"
    从左上角开始将元素不停Push进minHeap中(logN)，再pop出来(logN).一共有N*N个元素，则O(N*N*log(N*N))
    注意，如果matrix[x][y]>0,则matrix[x+][y+]都可以跳过忽略，因为matrix[x+][y+]也必然>0
 2. method 2: binary search for each row. O(N*logN)
 3. Method 3: search for <= k, when move down, we can determine how many values <= k at the left side of the current row.  O(N + N)
    和“search value in young's matrix”做法一样
 */

int smaller_than_target(vector<vector<int>> matrix, int k){
    if(matrix.empty() || matrix[0].empty()){
        return INT_MIN;
    }
    int row = matrix.size();
    int col = matrix[0].size();
    int res = 0;
    int i = 0;
    int j = matrix[0].size()-1;
    while(i<matrix.size() && j>=0){
        if(matrix[i][j] > k){
            j--;
        }else if(matrix[i][j] <= k){
            res = res + j + 1;
            i++;
        }
    }
    return res;
}
/*
int main(){
    vector<int> v1 = {-5, -3, 0, 1};
    vector<int> v2 = {-2,  2, 3, 4};
    vector<int> v3 = {-1,  5, 6, 7};
    vector<int> v4 = {0,  6, 7, 9};
    vector<vector<int>> v = {v1, v2, v3, v4};
    cout << smaller_than_target(v, 0) << endl;
    return 0;
}
*/