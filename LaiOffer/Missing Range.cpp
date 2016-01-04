//
//  Missing Range.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/29/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

 For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
 */

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
 思路：
 arr[] = [0, 1, 3, 50, 75]
 base[] = [0 ... 99]
 需要返回一些区间，每个区间都是由这样的元素x组成：x在base[]里 && 不在arr[]里

 所以，result的第一个区间应始于: base[] lower(inclusive) --> arr[0] (exclusive)
 最后一个区间应止于:   arr[len-1](exclusive) --> base[] upper (inclusive)

 需要考虑的特殊情况：lower没有前一个元素/ upper没有后一个元素/ arr[]可能为空
 如果将base[]的上下限都各自扩充1，即base'[] = [-1 ... 100]，那么上面的特殊情况可以忽略
 base'[] lower = -1, base'[] upper = 100
 result的第一个区间应始于: base'[] lower(exclusive) --> arr[0] (exclusive)
 最后一个区间应止于:    arr[len-1](exclusive) --> base'[] upper (exclusive)

 cur代表arr[]中的每一个元素，pre代表arr[]中cur的前一个连续区间的最后一个整数.
 pre初始化为base'[] lower, end止于base'[] upper

 int转换string/ 区间上下限值不相同的话中间添加'->'
 这里最好另写一个function.
 */

string getRange(int from, int to){
    stringstream temp;
    if(from == to)
        temp << from;
    else
        temp << from << "->" << to;
    return temp.str();
}

// O(n) runtime, O(1) space
vector <string> findMissingRanges(int A[], int n, int lower, int upper) {
    vector < string > res;
    int start = lower-1;
    int end = upper+1;
    int pre = start;

    for(int i=0; i < n; i++){
        int cur = A[i];
        if(cur - pre >= 2)
            res.push_back(getRange(pre+1, cur-1));
        pre = cur;
    }

    if(end-pre >= 2)
        res.push_back(getRange(pre+1, end-1));

    return res;
}

// 将end==n的情况并入for()
vector < string > findMissingRanges1(int A[], int n, int lower, int upper){
    vector < string > res;
    int pre = lower-1;
    for(int i=0; i <= n; i++){
        int cur = (i==n)? upper+1 : A[i];
        if(cur - pre >= 2)
            res.push_back(getRange(pre+1, cur-1));
        pre = cur;
    }
    return res;
}