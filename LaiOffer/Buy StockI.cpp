
//
//  Buy stockI.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/13/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array of positive integers representing a stock’s price on each day. On each day you can only make one operation: either buy or sell one unit of stock and you can make at most 1 transaction. Determine the maximum profit you can make.

 Assumptions
 The given array is not null and is length of at least 2.
 Examples
 {2, 3, 2, 1, 4, 5}, the maximum profit you can make is 5 - 1 = 4
 
 
 same question: 
 Given an unsorted array A[N], find a pair of i and j such that i < j and A[j]-A[i] is maximized.
 */

#include <iostream>
#include <vector>
using namespace std;


/*
 Scan from left to right, and keep track the minimal price in left.
 Each step, only calculate the difference(profit) between current price and minimal price.
 If the current profit is larger than previous profit, replace it.
 */

// 贪心算法。分别找到价格最低和最高的一天，低进高出。注意最低的一天要在最高的一天之前。
// time complexity O(N), space complexity O(1)
int maxProfit(vector<int> input){
    if(input.size() < 2) return 0;
    int max_diff = 0; // 差价，即利润
    int cur_min = input[0]; // 当前最小
    for(int i=1; i<input.size(); i++){// 从i=1开始
        max_diff = max(max_diff, input[i]-cur_min);
        cur_min = min(cur_min, input[i]);
    }
    return max_diff;
}

