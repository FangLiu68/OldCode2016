//
//  Remove Adjacent Repeated Char.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/20/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Remove adjacent, repeated characters in a given string, leaving only one character for each group of such characters.

 Assumptions
 Try to do it in place.
 Examples
 “aaaabbbc” is transferred to “abc”
 Corner Cases
 If the given string is null, we do not need to do anything.
 */

#include <string>
#include <iostream>
using namespace std;

/*
 E.g.,
 index	        0 1 2 3 4 5 6 7
 string s = "a a a a a b b b b b _ c c c c";      -> “ab c”
 f
 s

 f is the fast/current index to scan the string (from left to right)
 s is the slow/index  all letters to the left of s (including s) should be the final answer.
 */

// slow左边（不包括slow）都是满足要求的结果
string remove_adj_charI(string s){
    if(s.size() <= 1) return s;
    int slow = 1;
    int fast = 1;
    while(fast < s.size()){
        if(s[fast] == s[slow-1]){
            fast++;
        }else{
            s[slow++] = s[fast++];
        }
    }
    return s.substr(0, slow);
}

// 注意：唯一不同的是，slow的左边（包括slow在内）都是满足要求的结果
string remove_adj_repeated_char_I(string s) {
    if(s.empty()) return "";
    int slow = 0;
    int fast = 0;
    while(fast < s.size()){
        if(s[fast] == s[slow]){
            fast++;
        }else{
            s[++slow] = s[fast++];
        }
    }
    return s.substr(0, slow+1);
}
/*
int main(){
    string s = "a";
    cout << remove_adj_charI(s) << endl;
    return 0;
}*/