//
//  valid_parentheses.cpp
//  LeetCode
//
//  Created by Fang Liu on 9/20/14.
//  Copyright (c) 2014 Fang Liu. All rights reserved.
//

/*
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

#include <stack>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// use vector/stack to store all left parentheses
// time complexity O(N), space complexity O(N)
bool isValid(string s) {
    if(s.empty()){
        return false;
    }
    stack<char> stk;
    for(int i=0; i<s.size(); ++i){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            stk.push(s[i]);
            continue;
        }
        if(stk.empty()){
            return false; // 例如第一个元素就是右括号
        }
        if(stk.top()=='(' && s[i]!=')'){
            return false;
        }else if(stk.top()=='[' && s[i]!=']'){
            return false;
        }else if(stk.top()=='{' && s[i]!='}'){
            return false;
        }
        stk.pop();
    }
    return stk.empty();
}

///////////////////
bool matchChar(char a, char b);
// O(N) runtime, O(N) space
bool isValid1(string s) {
    if(s.empty()) return false;
    stack<char> stk;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            stk.push(s[i]);
            continue;
        }
        if(stk.empty()) return false; // i没循环完毕，string还有剩下char没比较，skt已经为空，返回false
        if(!matchChar(stk.top(), s[i])){
            return false;
        }else{
            stk.pop();
        }
    }
    return stk.empty();
}
// a b的顺序不能变
bool matchChar(char a, char b){
    if((a=='(' && b==')') || (a=='[' && b==']' )|| (a=='{' && b=='}')) return true;
    return false;
}
