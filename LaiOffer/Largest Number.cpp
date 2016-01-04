//
//  Largest Number.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/18/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a list of non negative integers, arrange them such that they form the largest number.

 For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 Note: The result may be very large, so you need to return a string instead of an integer.
 */

#include <sstream>
#include "Header.h"

/*
 How to define the compare function?
 1. Consider two int, a and b.  e.g., 34 and 3.
 2. Actually, what we need to compare is not 34 and 3, but  34 3 and 3 34.
 3. If 343 > 334, then 34 should have higher order than 3, and vice versa.

 对于两个备选数字a和b，如果str(a) + str(b) > str(b) + str(a)，则a在b之前，否则b在a之前
 按照此原则对原数组从大到小排序即可
 时间复杂度O(nlogn)
 
 注意，int->str 常用stringstream来做
 sort(input.begin(), input.end(), compare) 这里compare可以自己定义，就是根据自己设置的规矩来sort整个数组
 记住compare写的时候要是static
 */

static bool _comp(int i, int j){
    stringstream ss;
    ss << i;
    string si = ss.str();
    ss << j;
    string sj = ss.str();
    return (si + sj) > (sj + si);
}

string largestNumber(vector<int>& input){
    string res;
    if(input.empty()){
        return res;
    }
    sort(input.begin(), input.end(), _comp);

    // 如果都是0的话，提前返回，只返回一个0
    if(input[0] == 0){
        return "0";
    }

    for(int i=0; i<input.size(); ++i){
        stringstream ss;
        ss << input[i];
        res = res + ss.str();
    }

    return res;
}
/*
int main(){
    vector<int> input = {3,30,34,5,9};
    cout << largestNumber(input) << endl;
    return 0;
}*/
