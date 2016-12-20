
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
 
 限制只能买卖一次，则尽可能在最低点买入最高点抛出。这里的一个隐含限制是抛出的时间必须在买入的时间之后。所以找整个数组的最大最小值之差的方法未必有效。因为很可能最大值出现在最小值之前。但可以利用类似思路，在扫描数组的同时来更新一个当前最小值minPrice.这样能保证党扫描到i时，minPrices必然是i之前的最小值
 如果prices[i] < minPrice，则更新minPrice = prices[i]。并且该天不应该卖出。
 如果prices[i] >= minPrice，则该天可能是最好的卖出时间，计算prices[i] - minPrice，并与当前的单笔最大利润比较更新。
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

int maxProfitI(vector<int>& prices) {
    if(prices.empty()) return 0;
    
    int res = 0;
    int minPrice = prices[0];
    
    for(int i=1; i<prices.size(); ++i){
        if(prices[i] > minPrice){
            res = max(prices[i] - minPrice, res);
        }else{
            minPrice = prices[i];
        }
    }
    
    return res;
}

