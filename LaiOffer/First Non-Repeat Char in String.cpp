//
//  First Non-Repeat Char in String.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/29/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// find the first non repeated character in a string. suppose they only have 'a'-'z'

#include "Header.h"

/*
 如果只有26个字母，就用一个26大小的数组
 数组的index 1-26 代表'a'-'z'这26个字母，index对应的内容代表input string中这个character所在的位置(即他在input中的index)
 数组内容初始化都为-2
 如果当前char没有出现过，就把内容设置为当前char在input中的位置
 如果当前char已经出现过，意味着此时已经出现重复，不是我们要找的，就把内容设置成-1
 之后遍历这个大小为26的数组。因为数组里面除了-2、-1外，存的都是non repeated char，现在只要找到the first one就好
 */
char first_non_repeat(string input){
    if(input.empty()){
        return ' ';
    }
    vector<int> mp(26, -2);
    for(int i=0; i<input.size(); ++i){
        char cur = input[i];
        int index = cur - 'a';
        if(mp[index] == -2){
            mp[index] = i;
        }else if(mp[index]>=0 && mp[index]<input.size()){
            mp[index] = -1;
        }
    }
    int res = INT_MAX;
    for(int i=0; i<mp.size(); ++i){
        if(mp[i]!=-1 && mp[i]!=-2){
            res = min(res, mp[i]);
        }
    }
    if(res == INT_MAX){
        return ' ';
    }else{
        return input[res];
    }
}

char first_non_repeat1(string input){
    map<char, int> mp;
    for(int i=0; i<input.size(); ++i){
        if(mp.find(input[i]) == mp.end()){
            mp[input[i]] = 1;
        }else{
            mp[input[i]]++;
        }
    }
    for(int i=0; i<input.size(); ++i){
        if(mp[input[i]] == 1){
            return input[i];
        }
    }
    return ' ';
}
/*
int main(){
    string input = "aabcbc";
    cout << first_non_repeat(input) << endl;
    return 0;
}*/