//
//  count_and_say.cpp
//  LeetCode
//
//  Created by Fang Liu on 9/20/14.
//  Copyright (c) 2014 Fang Liu. All rights reserved.
//

/*
 The count-and-say sequence is the sequence of integers beginning as follows:
 1, 11, 21, 1211, 111221, ...

 1 is read off as "one 1" or 11.
 11 is read off as "two 1s" or 21.
 21 is read off as "one 2, then one 1" or 1211.
 Given an integer n, generate the nth sequence.

 Note: The sequence of integers will be represented as a string.
 */

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

/*
 思路：
 第N个结果由第N-1个结果得来。从第一个序列1开始，逐步往后计算，直到得到结果Nth。
 需要辅助方程string getNext()
 从第二个序列开始，每个序列的长度都是偶数。从最高位开始每两位都是由count和value组成。
 count是前一个序列从最高位开始的相同数值的个数
 value是前一个序列从最高位开始的相同值的值
 */

string getNext(string s);

// O(N^2) runtime, O(N) space
string countAndSay(int n) {
    string res;
    if(n==0) return res;
    for(int i=0; i<n; i++)
        res = getNext(res);
    return res;
}

string getNext(string s){
    if(s.empty()) return "1";
    string res = "";
    for(int i=0; i<s.size(); i++){
        int cnt = 1; // 计算连续出现的字符个数
        while(i+1<s.size() && s[i]==s[i+1]){
            i++; // 一旦有连续相同的字符，则i++
            cnt++;
        } // 跳出循环时，i仍旧指向最后一个连续相同的数字
        res.push_back(cnt+'0');
        res.push_back(s[i]);
        /* 也可以用下面的方法做，但上面的做法更简单
         stringstream ss;
         ss << cnt;
         res = res + ss.str();
         res = res + s[i];*/
    }
    return res;
}
