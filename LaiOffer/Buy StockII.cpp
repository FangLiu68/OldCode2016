//
//  Buy StockII.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/13/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array of positive integers representing a stock’s price on each day. On each day you can only make one operation: either buy or sell one unit of stock, you can make as many transactions you want, but at any time you can only hold at most one unit of stock. Determine the maximum profit you can make.

 Assumptions
 The give array is not null and is length of at least 2
 Examples
 {2, 3, 2, 1, 4, 5}, the maximum profit you can make is (3 - 2) + (5 - 1) = 5
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 buy-then sell 这个过程是一个transaction
 题目的意思是，你可以买，之后卖；再买，再卖。。。多少个trasaction都行
 但你必须在一个transaction结束之后再进行下一个。比如，不能连着买好几次，再一次卖了。

 因为我们可以make unlimited transactions, the question turns to sum all the positive price difference.
 so scan from left to right, then add all positive different value.
 */

// 贪心算法。低进高出，把所有正的价格差价加起来
// time complexity O(N), space complexity O(1)
int maxProfit_2(vector<int> prices){
    if(prices.size() < 2) return 0;
    int res = 0;
    int dif;
    for(int i=1; i<prices.size(); i++){
        dif = prices[i] - prices[i-1];
        if(dif>0)   res = res+dif;
    }
    return res;
}