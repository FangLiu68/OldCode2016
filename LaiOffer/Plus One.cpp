//
//  Plus One.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/29/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Given a number represented as an array of digits, plus one to the number.

#include <iostream>
#include <vector>
using namespace std;

/*
 1 特定法，稍微优化点，因为只是加1，所以，如果当前数字小于9的时候就直接加1就可以返回结果了。
 三种情况：125+1；199+1；9+1
 2 通用法，可以适用于+1到9数字的
 */

// time complexity O(N), space complexity O(1)
vector<int> plusOne2(vector<int> &digits){
    int i = 0;
    for (i = digits.size()-1; i >= 0; i--){
        if (digits[i] == 9) digits[i] = 0;
        else{
            digits[i]++;
            return digits;
        }
    }
    if (i < 0) digits.insert(digits.begin(), 1);
    return digits;
}

// time complexity O(N), space complexity O(1)
vector<int> plusOne1(vector<int> &digits){
    if (digits.empty()) return digits;
    int carry = 1;
    for (int i = digits.size()-1; i >= 0; i--){
        int sum = digits[i] + carry;
        carry = sum / 10;
        digits[i] = sum % 10;
    }
    if (carry == 1) digits.insert(digits.begin(), 1);
    return digits;
}

