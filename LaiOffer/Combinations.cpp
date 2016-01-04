//
//  Combinations.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/22/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

 For example,
 If n = 4 and k = 2, a solution is:

 [
 [2,4],
 [3,4],
 [2,3],
 [1,2],
 [1,3],
 [1,4],
 ]
 */

#include <iostream>
#include <vector>
using namespace std;

void helper_comBi(int n, int k, vector<vector<int>>& res, vector<int> cur, int index){
    if(cur.size() == k){
        res.push_back(cur);
        return;
    }
    for(int i=index; i<=n; ++i){
        cur.push_back(i);
        helper_comBi(n, k, res, cur, i+1);
        cur.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> cur;
    if(n<=0) return res;
    helper_comBi(n, k, res, cur, 1);
    return res;
}
/*
int main(){
    int n = 4;
    int k = 2;
    vector<vector<int>> res = combine(n, k);
    for(int i=0; i<res.size(); ++i){
        vector<int> cur = res[i];
        for(int j=0; j<cur.size(); ++j){
            cout << cur[j] << " ";
        }
        cout << endl;
    }
    return 0;
}*/
