//
//  add_binary.cpp
//  LeetCode
//
//  Created by Fang Liu on 5/2/14.
//  Copyright (c) 2014 Fang Liu. All rights reserved.
//

/* Given two binary strings, return their sum (also a binary string).
 For example, a = "11" b = "1" Return ”100”. */

#include <string>
#include <iostream>
using namespace std;

// time complexity O(N), space complexity O(1)
string addBinary(string a, string b){
    string res = (a.size() > b.size())? a : b;
    int indexRes = res.size() -1;
    int indexA = a.size() - 1;
    int indexB = b.size() - 1;
    int carry = 0;
    while(indexA >= 0 || indexB >= 0){ // 注意这里是 ||
        int valueA = (indexA >= 0)?(a[indexA--]-'0'):0;
        int valueB = (indexB >= 0)?(a[indexB--]-'0'):0;
        int sum = valueA + valueB + carry; // 要用一个sum来记录总的和
        res[indexRes--] = sum%2 + '0'; // 当前位置上的数用模余数表示
        carry = sum/2; // 进位用商表示
    }
    if(carry>0) res.insert(res.begin(), '1');
    return res;
}
