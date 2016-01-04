//
//  Roman to Integer.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/20/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/*
 Given a roman numeral, convert it to an integer.
 Input is guaranteed to be within the range from 1 to 3999.
 */

/*
 1. 相同的数字连写，所表示的数等于这些数字相加得到的数，如：Ⅲ = 3；
 2. 小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数， 如：Ⅷ = 8；Ⅻ = 12；
 3. 小的数字，（限于Ⅰ、X 和C）在大的数字的左边，所表示的数等于大数减小数得到的数，如：Ⅳ= 4；Ⅸ= 9；
 4. 正常使用时，连写的数字重复不得超过三次。（表盘上的四点钟“IIII”例外）
 5. 在一个数的上面画一条横线，表示这个数扩大1000倍。
 */

// O(n) runtime, O(1) space
int romanToInt(string s){
    if(s.empty()) return 0;

    unordered_map<char, int> mp; // all roman-int pairs put into map
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    int res = mp[s[s.size()-1]]; // initialize res to the last roman value represented in the string
    for(int i=s.size()-2; i>=0; i--){
        if(mp[s[i+1]] <= mp[s[i]])
            res = res + mp[s[i]];
        else
            res = res - mp[s[i]];
    }
    return res;
}


