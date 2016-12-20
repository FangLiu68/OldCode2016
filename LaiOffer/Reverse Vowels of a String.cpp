//
//  Reverse Vowels of a String.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/11/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Write a function that takes a string as input and reverse only the vowels of a string.
 
 Example 1:
 Given s = "hello", return "holle".
 
 Example 2:
 Given s = "leetcode", return "leotcede".
 */

#include "Header.h"

bool isVowels(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return true;
    }
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
        return true;
    }
    return false;
}

string reverseVowels(string s) {
    if(s.empty()) return "";
    
    int left = 0;
    int right = s.size() - 1;
    
    while(left <= right){
        if(!isVowels(s[left])) left++;
        else if(!isVowels(s[right])) right--;
        else{
            swap(s[left], s[right]);
            left++, right--;
        }
    }
    
    return s;
}

