//
//  len_of_last_word.cpp
//  LeetCode
//
//  Created by Fang Liu on 5/2/14.
//  Copyright (c) 2014 Fang Liu. All rights reserved.
//

/* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 If the last word does not exist, return 0.
 Note: A word is defined as a character sequence consists of non-space characters only. For example, Given s = "Hello World", return 5. */

#include <iostream>
#include <string>
using namespace std;

// 从后往前扫描
// O(N) runtime, O(1) space
int lengthOfLastWord(const char *s) {
    int index_last = strlen(s)-1;
    while(index_last>=0 && s[index_last]==' '){ // 跳过连续空格
        index_last--;
    }
    int len = 0;
    while(index_last>=0 && s[index_last]!=' '){
        index_last--;
        len++;
    }
    return len;
}

int lengthOfLastWord(string s) {
    if(s.empty()){
        return 0;
    }
    int runner = s.size()-1;
    while(s[runner] == ' ') runner--;
    int res = 0;
    while(s[runner] != ' ' && runner>=0){
        res++;
        runner--;
    }
    return res;
}