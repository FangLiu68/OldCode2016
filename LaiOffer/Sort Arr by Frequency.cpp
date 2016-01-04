//
//  Sort Arr by Frequency.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// sort an array of numbers by their frequency.

#include "Header.h"

struct comp2{
    bool operator()(pair<int, int> p1, pair<int, int> p2){
        return p1.second > p2.second; // min heap
    }
};

vector<int> sort_by_freq(vector<int> input){
    vector<int> res;
    if(input.empty()){
        return res;
    }
    map<int, int> mp;
    for(int i=0; i<input.size(); ++i){
        if(mp.find(input[i]) == mp.end()){
            mp[input[i]] = 1;
        }else{
            mp[input[i]]++;
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp2> min_heap;
    for(map<int, int>::iterator IT = mp.begin(); IT != mp.end(); ++IT){
        min_heap.push(*IT);
    }
    while(!min_heap.empty()){
        pair<int, int> cur = min_heap.top();
        min_heap.pop();
        for(int i=0; i<cur.second; ++i){
            res.push_back(cur.first);
        }
    }
    return res;
}

/*
int main(){
    vector<int> input = {1,2,1,3,1,4,3,4,4,4,4};
    vector<int> res = sort_by_freq(input);
    for(int i=0; i<res.size(); ++i){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}*/