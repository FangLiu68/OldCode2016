//
//  Decompress String I.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/6/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a string in compressed form, decompress it to the original string. The adjacent repeated characters in the original string are compressed to have the character followed by the number of repeated occurrences. If the character does not have any adjacent repeated occurrences, it is not compressed.

 Assumptions
 The string is not null
 The characters used in the original string are guaranteed to be ‘a’ - ‘z’
 There are no adjacent repeated characters with length > 9

 Examples
 “acb2c4” → “acbbcccc”
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 因为字符和数字不一定是成对出现的，所以我们要先判断当前字符的下一个是不是数字
// 如果是数字，就push as many count of the current char into res
// otherwise, only push one current char into res
// 利用string buffer更改
string decompressI(string input) {
    if(input.empty()){
        return "";
    }
    string res;
    for(int i=0; i<input.size(); ++i){
        if(i+1<input.size() && input[i+1]>='0' && input[i+1]<='9'){
            int count = input[i+1]-'0';
            for(int j=0; j<count; ++j){
                res.push_back(input[i]);
            }
            i++;
        }else{
            res.push_back(input[i]);
        }
    }
    return res;
}

// 在inplace上更改
string decompressI1(string input){
    if(input.empty()){
        return "";
    }
    int len = input.size();
    int newLen = len;
    for(int i=0; i<input.size(); ++i){
        if(input[i]>'2' && input[i]<'9'){
            newLen = newLen + (input[i]-'0'-2);
        }
    }
    input.resize(newLen);
    int runner = len-1;
    int cur = newLen-1;
    while(runner >= 0){
        if(input[runner]>='2' && input[runner]<='9'){
            int count = input[runner]-'0';
            runner--;
            for(int j=0; j<count; ++j){
                input[cur--] = input[runner];
            }
            runner--;
        }else{
            input[cur--] = input[runner--];
        }
    }
    return input;
}
/*
int main(){
    string str = "acb2c4";
    string res = decompressI1(str);
    cout << res << endl;
    return 0;
}*/