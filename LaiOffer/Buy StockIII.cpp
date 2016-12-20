//
//  Buy StockIII.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/26/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Say you have an array for which the ith element is the price of a given stock on day i.
 Design an algorithm to find the maximum profit. You may complete at most two transactions.
 
 Note:
 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 允许两次买卖，但同一时间只允许持有一支股票。也就意味着这两次买卖在时间跨度上不能有重叠（当然第一次的卖出时间和第二次的买入时间可以是同一天）。既然不能有重叠可以将整个序列以任意左边i为分割点，分割成两部分：
 prices[0:n-1] => prices[0:i] + prices[i:n-1]
 
 对于这个特定分割来说，最大收益为两段的最大收益之和。每一段的最大收益当然可以用第一题的方法来做。而III的解一定是对所有0<=i<=n-1的分割的最大收益中取一个最大值。为了增加计算效率。可以用dp来做bookkeeping.
 
 目标是对每个坐标i：
 1. 计算A[0:i]的收益最大值：用minPrice记录i左边最低价，用maxLeftProfit记录左侧最大收益
 2. 计算A[i:n-1]的收益最大值：用maxPrice记录i右边的最高价格，用maxRightProfit记录右侧最大收益
 3. 最后这两个收益之和便是以i为分割点的最大收益。将序列从左向右扫一遍可以获得1，从右向左扫一遍可以获得2.相加后取最大值即为答案。
 */

int maxProfitIII(vector<int>& prices) {
    if(prices.empty()){
        return 0;
    }
    
    int n = prices.size();
    vector<int> leftProfit(n, 0);
    
    int maxLeftProfit = 0;
    int minPrice = prices[0];
    
    for(int i=1; i<prices.size(); ++i){
        if(prices[i] < minPrice){
            minPrice = prices[i];
        }else{
            maxLeftProfit = max(maxLeftProfit, prices[i] - minPrice);
        }
        leftProfit[i] = maxLeftProfit;
    }
    
    int res = leftProfit[n-1];
    int maxPrice = prices[n-1];
    int maxRightProfit = 0;
    for(int i=n-2; i>=0; --i){
        if(prices[i] > maxPrice){
            maxPrice = prices[i];
        }else{
            maxRightProfit = max(maxRightProfit, maxPrice - prices[i]);
        }
        res = max(res, leftProfit[i] + maxRightProfit);
    }
    
    return res;
}