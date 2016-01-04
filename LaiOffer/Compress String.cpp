//
//  Compress String.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/6/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a string, replace adjacent, repeated characters with the character followed by the number of repeated occurrences. If the character does not has any adjacent, repeated occurrences, it is not changed.

 Assumptions
 The string is not null
 The characters used in the original string are guaranteed to be ‘a’ - ‘z’
 There are no adjacent repeated characters with length > 9

 Examples
 “abbcccdeee” → “ab2c3de3”
 aaabbcddd  a3b2cd3
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string compress_string(string str){
    string res;
    if(str.empty()) return res;
    int i = 0;
    while(i<str.size()){
        char ch = str[i];
        int count = 1;
        while(str[i+1] == ch){
            count++;
            i++;
        }
        if(count>1){
            res.push_back(ch);
            res.push_back(count+'0');
        }
        else
            res.push_back(ch);
        i++;
    }
    return res;
}

// “abbcccdeee” → “ab2c3de3”
// change inplace
string compress_string1(string input){
    if(input.empty()){
        return "";
    }

    vector<pair<char, int>> v;
    for(int i=0; i<input.size(); ++i){
        int count = 1;
        char cur = input[i];
        while(i+1<input.size() && input[i+1]==cur){
            count++;
            i++;
        }
        pair<char, int> cur_pair = make_pair(input[i], count);
        v.push_back(cur_pair);
    }
    int newSize = 0;
    for(int i=0; i<v.size(); ++i){
        if(v[i].second == 1){
            newSize = newSize + 1;
        }else{
            newSize = newSize + 2;
        }
    }
    input.resize(newSize);
    int index = 0;
    for(int i=0; i<v.size(); ++i){
        if(v[i].second == 1){
            input[index++] = v[i].first;
        }else{
            input[index++] = v[i].first;
            input[index++] = v[i].second+'0';
        }
    }
    return input;
}

// 看上面的方法  这个有点麻烦
string test1(string str){
    string res;
    if(str.size()<=1) return str;
    char pre = str[0];
    int i = 1;
    while(i<str.size()){
        int count = 1;
        while(pre == str[i]){
            count++;
            i++;
        }
        if(count>1){
            res.push_back(pre);
            res.push_back(count+'0');
        }
        else
            res.push_back(pre);
        pre = str[i];
        i++;
    }
    int len = str.size();
    if(str[len-1] != str[len-2]) res.push_back(str[len-1]);
    return res;
}
/*
int main(){
    string str = "abbcccdeeef";
    string res = compress_string1(str);
    cout << res << endl;
    return 0;
}*/