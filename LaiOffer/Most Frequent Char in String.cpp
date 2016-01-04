//
//  Most Frequent Char in String.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/24/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// find the most frequent charactor in a string

#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

char most_frequent_char_in_string(string str){
    if(str.empty()){
        return ' ';
    }
    unordered_map<char, int> mp; // key: char in the string; value: count for each char
    for(int i=0; i<str.size(); ++i){
        if(mp.find(str[i]) == mp.end()){
            mp[str[i]] = 1;
        }else{
            mp[str[i]]++;
        }
    }
    pair<char, int> res = make_pair(' ', 0);
    for(unordered_map<char, int>::iterator IT = mp.begin(); IT != mp.end(); ++IT){
        if(res.second < IT->second){
            res.first = IT->first;
            res.second = IT->second;
        }
    }
    return res.first;
}
/*
int main(){
    string str = "abceaabbbc";
    char res = most_frequent_char_in_string(str);
    cout << res << endl;
    return 0;
}*/