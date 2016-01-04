//
//  2Sum One Pair Find Value.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// same question as before. just need to return pair of values and solve it in O(N) time complexity

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> pair_sum(vector<int> arr, int target){
    vector<pair<int, int>> res;
    if(arr.empty()){
        return res;
    }
    unordered_map<int, bool> present;
    for(int i=0; i<arr.size(); ++i){
        if(present.count(target - arr[i]) != 0){
            res.push_back(make_pair(arr[i], target-arr[i]));
        }
        present[arr[i]] = true;
    }
    return res;
}
/*
int main(){
    vector<int> arr = {2, 1, 3, 2, 4, 3, 4, 2};
    int target = 6;
    vector<pair<int, int>> res = pair_sum(arr, target);
    for(int i=0; i<res.size(); ++i){
        cout<< res[i].first << " " << res[i].second<< endl;
    }
    cout << endl;
    return 0;
}*/