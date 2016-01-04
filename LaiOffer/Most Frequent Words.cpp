//
//  Most Frequent Words.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Given a list of strings, find the most frequent words in this list

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

// 用map存储每个string出现的次数。之后遍历整个map，找出次数最大的那个
// 注意记录Map中两个变量的话要用pair<>来标志

string most_frequent(vector<string> input){
    if(input.empty()){
        return "";
    }
    // key: element in input; value: frequence of each element
    unordered_map<string, int> mp;
    for(int i=0; i<input.size(); ++i){
        if(mp.find(input[i]) == mp.end()){ // not contain input[i] so far
            mp[input[i]] = 1;
        }else{
            mp[input[i]]++;
        }
    }
    pair<string, int> res = make_pair("", 0);
    for(unordered_map<string, int>::iterator IT = mp.begin(); IT != mp.end(); ++IT){
        if(res.second < IT->second){
            res.first = IT->first;
            res.second = IT->second;
        }
    }
    return res.first;
}
/*
int main(){
    vector<string> input = {};
    string res = most_frequent(input);
    cout << res << endl;
    return 0;
}*/