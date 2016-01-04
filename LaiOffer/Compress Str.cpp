//
//  Compress Str.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/1/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the "compressed" string would not become smaller than the orig- inal string, your method should return the original string.
 */

#include "Header.h"

string compStr(string& input){
    if(input.empty()) return "";

    int len = 0;
    char pre = input[0];
    for(int i=1; i<input.size(); ++i){
        if(pre == input[i]){
            continue;
        }else{
            len = len+2;
            pre = input[i];
        }
    }
    if(len >= input.size()) return input;

    string res;
    len = 1;
    pre = input[0];
    for(int i=1; i<input.size(); ++i){
        if(pre == input[i]){
            len++;
            continue;
        }else{
            res.push_back(pre);
            res.push_back(len+'0');
            pre = input[i];
            len = 1;
        }
    }
    res.push_back(pre);
    res.push_back(len+'0');
    return res;
}
/*
int main(){
    string input = "aabccccaaa";
    cout << compStr(input) << endl;
    return 0;
}*/