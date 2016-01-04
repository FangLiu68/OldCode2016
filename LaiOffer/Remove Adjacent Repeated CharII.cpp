//
//  Remove Adjacent Repeated CharII.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/20/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Remove adjacent, repeated characters in a given string, leaving only two characters for each group of such characters. The characters in the string are sorted in ascending order.

 Assumptions
 Try to do it in place.
 Examples
 “aaaabbbc” is transferred to “aabbc”
 Corner Cases
 If the given string is null, we do not need to do anything.
 */

#include <string>
#include <iostream>
using namespace std;

// 注意：这里又恢复成了 slow的左边所有字符（不包括slow）都是符合条件的结果
string remove_adj_repeated_char_II(string s){
    if(s.size() <= 2) return s;
    int slow = 2;
    int fast = 2;
    while(fast < s.size()){
        if(s[slow-2] == s[fast]){
            fast++;
        }else{
            s[slow++] = s[fast++];
        }
    }
    return s.substr(0, slow);
}