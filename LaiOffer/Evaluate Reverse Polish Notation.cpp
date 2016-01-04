//
//  Evaluate Reverse Polish Notation.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/8/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Evaluate the value of an arithmetic expression in Reverse Polish Notation.

 Valid operators are +, -, *, /. Each operand may be an integer or another expression.

 Some examples:
 ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

#include <stack>
#include <vector>
#include <iostream>
using namespace std;

/*
 use stack
 遇到是数字，就push into the stack
 遇到是符号，就pop two top elements from the stack, 做运算, then push the result into the stack, then go on
           until there is only one element left in the stack, which is the result.
 */
bool isSymbol(string s);
int evalRPN(vector<string> &tokens) {
    if(tokens.empty()) return 0;
    stack<int> stk;
    for(int i = 0; i < tokens.size(); ++i){

        if(isSymbol(tokens[i])){
            int num1 = stk.top();
            stk.pop();
            int num2 = stk.top();
            stk.pop();
            if(tokens[i] == "+"){
                stk.push(num2+num1);
            }else if(tokens[i] == "-"){
                stk.push(num2-num1);
            }else if(tokens[i] == "*"){
                stk.push(num2*num1);
            }else if(tokens[i] == "/"){
                stk.push(num2/num1);
            }
        }
        else{
            stk.push(stoi(tokens[i]));
        }
    }
    return stk.top();
}

bool isSymbol(string s){
    if(s.empty()){
        return false;
    }
    if(s=="+" || s=="-" || s=="*" || s=="/"){
        return true;
    }
    return false;
}