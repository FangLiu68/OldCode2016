//
//  Decompress String II.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/6/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a string in compressed form, decompress it to the original string. The adjacent repeated characters in the original string are compressed to have the character followed by the number of repeated occurrences.

 Assumptions
 The string is not null
 The characters used in the original string are guaranteed to be ‘a’ - ‘z’
 There are no adjacent repeated characters with length > 9

 Examples
 “a1c0b2c4” → “abbcccc”
 */

#include "Header.h"

string decompress_string_useBuffer(string str){
    string res;
    if(str.empty()) return res;
    for(int i=0; i<str.size(); i++){
        char ch = str[i++];
        int count = str[i]-'0';
        for(int i=0; i<count; i++)
            res.push_back(ch);
    }
    return res;
}

// 用pair<char,int>来存储每个char出现的次数
string decompress_string_inplace(string input) {
    if(input.empty()){
        return "";
    }
    vector<pair<char, int>> v;
    int totalSize = 0;
    for(int i=0; i<input.size()-1; i=i+2){ // 注意这里i每次+2
        pair<char, int> cur = make_pair(input[i], input[i+1]-'0');
        v.push_back(cur);
        totalSize = totalSize + cur.second;
    }
    if(totalSize == 0){ // a0b0c0d0  则直接返回空
        return "";
    }
    input.resize(totalSize);
    int index = 0;
    for(int i=0; i<v.size(); ++i){
        for(int j=0; j<v[i].second; ++j){
            input[index++] = v[i].first;
        }
    }
    return input;
}


// 第一种方法是用string buffer，将char一个一个push_back进结果中。比较简单，但面试或许会要求inplace的做法
// O(n) runtime, O(n) space
string decompress_string_II_useStringBuffer(string str){
    string res;
    if(str.empty()) return res;

    int index = 0;
    while(index <= str.size()-1){
        int count = atoi(&str[index+1]);
        if(count != 0){
            for(int i=0; i<count; i++)
                res.push_back(str[index]);
        }
        index = index+2;
    }
    return res;
}

/*
 inplace change string 的做法

 Observation:
 if 数字为0 or 1则可以使得original string变短，
 if 数字 >= 2, 则可以使得original string不变或者变长。
 therefore, we need to deal with the two cases separately.

 solution:
 scan input, decide the output length, increase buffer size if necessary
 process the input in two iterations, one for length 0/1/2, one for length greater than 2.
 */
