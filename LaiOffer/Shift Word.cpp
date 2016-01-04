//
//  Shift Word.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/25/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// shift the whole string to the right-hand side by two bits
// Example: abcdef -> efabcd

#include <string>
#include <iostream>
using namespace std;

/*
 Step1: reverse the whole word   abcdef  → fedcba
 Step2: reverse(0,1) and reverse(2, size-1)    fe dcba → ef abcd
 */
void helper_reverse_word(string& input, int left, int right);

void shift_word(string& input, int shift){
    if(input.empty() || shift>input.size()) return;
    shift = shift % input.size();
    helper_reverse_word(input, 0, input.size()-1); // reverse the whole word
    helper_reverse_word(input, 0, shift-1);
    helper_reverse_word(input, shift, input.size()-1);
}

void helper_reverse_word(string& input, int left, int right){
    if(input.empty() || left>right) return;
    while(left <= right){
        char tmp = input[left];
        input[left++] = input[right];
        input[right--] = tmp;
    }
}
/*
int main(){
    string input = "abcdef";
    int shift = 2;
    shift_word(input, shift);
    cout << input << endl;
    return 0;
}*/