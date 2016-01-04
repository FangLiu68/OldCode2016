//
//  Nums of Combination of Coins.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/9/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 We have coins value as {1, 2, 5, 10, 25} cents. Given a target number of coins(for example, 99 cents), how many ways of combination of coins we can have such that the sum of the coins is the target number, suppose there is no limit for choosing any kind of the given coins.
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 k →
 x x x x x x x       row
 1 1 1 1 2 2 2       i -1
 x 3 x x 4 x x       i
 x x x x x x x
 x x x x x x x

 for each row(smallest to largest):
    for each column(smallest to largest):

 填的时候每行从左到右填
        每列从上到下填
 
 怎么把二维DP转换成一维DP：
 对于位置4来说，我们需要的是（4上面正对着的2这个位置的值） 和 （4这一行中，4前面的某个值）
 假设4这一行是i，上面那一行是i-1
 那么我们每次只用存i-1那一行的值，当我们想计算第i行的值的话，就从左到右改写i-1行的值
 例如，此时在4的位置，我需要3位置的值和4头顶上2的值，那么位置3的值已经被改写到1那个区间了，而第一个位置2的值是即将被改写的值，那么想要位置4的值的话，我就只用把（位置2的值）+（区间1中相对于位置3的改写的那个值）就得到了
 */

/*
     99
0   1   2     3

dp[i][k] = how many ways to conduct k cents using the coins with largest value of coins[i](we can have some coins[i] or we do not use any coins[i])

dp[4][99] = dp[3][99] + dp[3][74] + dp[3][49] + dp[3][24]

Method 1:
dp[i][k] = sum(dp[i - 1][k - x * coins[i]]) for x = [0, k / coins[i]]

i * k * x

Method 2:
dp[i][k] = dp[i - 1][k] + dp[i][k - coins[i]]
i * k * 2

for (int i = 0; i < coins.length; i++) {
    dp[i][0] = 1;
    for (int k = coins[i]; k <= target; k++) {
        dp[i][k] = dp[i][k - coins[i]];
        if (i > 0) {
            dp[i][k] +=dp[i - 1][k];
        }
    }
}
return dp[coins.length - 1][target];


int[] dp = new int[target + 1];
dp[0] = 1;
for (int i = 0; i < coins.length; i++) {
    for (int k = coins[i]; k <= target; k++) {
        dp[k] += dp[k - coins[i]]; // dp[i - 1][k] + dp[i][k - coins[i]];
    }
}
return dp[target];
*/