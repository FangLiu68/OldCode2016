//
//  Encode Space.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/20/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 In URL encoding, whenever we see an space " ", we need to replace it with "20%". Provide a method that performs this encoding for a given string.

 Examples
 "google/q?flo wer market" → "google/q?flo20%wer20%market"
 Corner Cases
 If the given string is null, we do not need to do anything.
 */

#include "Header.h"

string encode_space(string input) {
    if(input.empty()) return "";
    int blank_count = 0;
    int len = input.size(); // true len (不包括多余的空格)

    for(int i=0; i<len; i++)
        if(input[i]==' ') blank_count++;

    int final_len = len + 2 * blank_count;
    input.resize(final_len);
    final_len--;
    for(int i = len-1; i >= 0; --i){
        if(input[i] == ' '){
            input[final_len--] = '0';
            input[final_len--] = '2';
            input[final_len--] = '%';
        }else{
            input[final_len--] = input[i];
        }
    }
    return input;
} // 输入是s在外面仍旧不变，传值调用

void encode_spaceI(char input[], int len){
    if(input == NULL || len <= 0){
        return;
    }
    int blank = 0;
    for(int i=0; i<len; ++i){
        if(input[i] == ' '){
            blank++;
        }
    }
    int final_len = len + blank*2;
    input[final_len] = '\0';
    final_len--;

    for(int i=len-1; i>=0; --i){
        if(input[i] == ' '){
            input[final_len--] = '0';
            input[final_len--] = '2';
            input[final_len--] = '%';
        }else{
            input[final_len--] = input[i];
        }
    }
}

/*
int main(){
    char s[50] = "how are you";
    encode_spaceI(s, 12);
    //for(int i=0; s[i]!='\0'; ++i) cout << s[i]; cout << endl;
    string input = "how are you";
    string res = encode_space(input);
    cout << res << endl;
    return 0;
}
*/