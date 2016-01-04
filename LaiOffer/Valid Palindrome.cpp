//
//  valid_palindrome.cpp
//  LeetCode
//
//  Created by Fang Liu on 5/2/14.
//  Copyright (c) 2014 Fang Liu. All rights reserved.
//

/* Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 For example,
 ”A man, a plan, a canal: Panama” is a palindrome. ”race a car” is not a palindrome.
 Note: Have you consider that the string might be empty? This is a good question to ask during an interview.
 For the purpose of this problem, we define empty string as valid palindrome. */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool is_valid_num(char& x){
    if(x >= 'A' && x <= 'Z'){
        x = x+32; // convert upper case to lower case
    }else if((x >= '0' && x <= '9') || (x >= 'a' && x <= 'z')){
        return true;
    }else {
        return false;
    }
    return true;
}

bool is_palindrome(string str){
    if(str.empty()){
        return true;
    }
    int start = 0;
    int end = str.size()-1;
    while(start <= end){
        while(!is_valid_num(str[start])){
            start++;
        }
        while(!is_valid_num(str[end])){
            end--;
        }
        if(str[start] != str[end]){
            return false;
        }else{
            start++, end--;
        }
    }
    return true;
}

bool is_palindrome1(string str){
    int start = 0;
    int end = str.size() - 1;
    while(start <= end){
        if(!isalnum(str[start])) {
            start++;
            continue;
        }
        if(!isalnum(str[end])){
            end--;
            continue;
        }
        if(tolower(str[start]) != tolower(str[end]))
            return false;
        else
            start++, end--;
    }
    return true;
}

/*
 int main(){
 string str1 = "12a";
 string str2 = ",,";
 string str3 = "a++,";
 string str4 = "A maN, a plan, A canal: Panama";
 if(is_palindrome(str1)) cout << "is p" << endl;
 else cout << "not p" << endl;
 if(is_palindrome(str2)) cout << "is p" << endl;
 else cout << "not p" << endl;
 if(is_palindrome(str3)) cout << "is p" << endl;
 else cout << "not p" << endl;
 if(is_palindrome(str4)) cout << "is p" << endl;
 else cout << "not p" << endl;
 return 0;
 }*/