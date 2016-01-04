//
//  2Sum All Pair I.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/23/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Find all pairs of elements in a given array that sum to the given target number. 
 Return all the pairs of indices.
 
 Assumptions
 The given array is not null and has length of at least 2.
 Examples
 A = {1, 3, 2, 4}, target = 5, return [[0, 3], [1, 2]]
 A = {1, 2, 2, 4}, target = 6, return [[1, 3], [2, 3]]
 */

#include <vector>
#include <map>
#include <iostream>
using namespace std;


vector<vector<int> > allPairs(vector<int> array, int target) {
    vector<vector<int> > result;
    map<int, vector<int>> mp;
    for (int i = 0; i < array.size(); i++) {
        int gap = target - array[i];
        vector<int> indices = mp[gap];
        if (!indices.empty()) {
            for (int j : indices) {
                vector<int> v;
                v.push_back(j);
                v.push_back(i);
                result.push_back(v);
            }
        }

        if (mp.find(array[i]) == mp.end()) {
            vector<int> v;
            mp[array[i]] = v;
        }
        mp[array[i]].push_back(i);
    }
    return result;
}