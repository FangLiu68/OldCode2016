//
//  Reverse a Word.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/25/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// reverse a word inplace

#include "Header.h"

void reverse_char(char* str){
    if(str == 0) return;
    char* end = str;
    while(*end != '\0'){
        end++;
    }
    end--;
    while(str < end){
        char tmp = *str;
        *str = *end;
        *end = tmp;
        str++, end--;
    }
}

// reverse a string iterative
void reverse_string_iter(string& input){
    if(input.empty()) return;
    int left = 0;
    int right = input.size()-1;
    while(left <= right){
        char tmp = input[left];
        input[left++] = input[right];
        input[right--] = tmp;
    }
}

//===================================================================
// use recursion to reverse a string
void helper_reverse_word_recur(string& input, int left, int right){
    if(input.empty() || left>=right){
        return;
    }
    // swap input[left], input[right]
    char tmp = input[left];
    input[left] = input[right];
    input[right] = tmp;
    helper_reverse_word_recur(input, left+1, right-1);
}

void reverse_word_recur(string& input){
    if(input.empty()) return;
    helper_reverse_word_recur(input, 0, input.size()-1);
}
/*
int main(){
    string a = "1235";
    char input[4] = "123";
    reverse_char(input);
    char* start = input;
    cout << strlen(input) << endl;
    cout << *start << endl;
    return 0;
}
*/