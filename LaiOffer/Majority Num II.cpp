//
//  Majority Num II.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/14/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an integer array of length L, find all numbers that occur more than 1/3 * L times if any exist.

 Assumptions
 The given array is not null
 Examples
 A = {1, 2, 1, 2, 1}, return [1, 2]
 A = {1, 2, 1, 2, 3, 3, 1}, return [1]
 A = {1, 2, 2, 3, 1, 3}, return []
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
 找>N/K的数，就需要(k-1)size map. key:arr[i], value:count of show time
 
 */

vector<int> majority(vector<int> array) {
    vector<int> res;
    if(array.empty()) return res;

    // 注意这里用的是map而不是unordered_map. map是有序的，得到结果直接push到res里，但如果用unorderd_map存的话最后还要再sort(res.begin(), res.end())一遍
    map<int, int> mp;
    
    for(int i=0; i<array.size(); ++i){
        if(mp.find(array[i]) == mp.end()){
            mp[array[i]] = 1;
        }else{
            mp[array[i]]++;
        }
    }
    int k = array.size()/3;
    for(map<int, int>::iterator IT = mp.begin(); IT != mp.end(); ++IT){
        if(IT->second > k){
            res.push_back(IT->first);
        }
    }
    //sort(res.begin(), res.end());
    return res;
}