//
//  Combinations Of Coins.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a number of different denominations of coins (e.g., 1 cent, 5 cents, 10 cents, 25 cents), get all the possible ways to pay a target number of cents.

 Arguments
 coins - an array of positive integers representing the different denominations of coins, there are no duplicate numbers and the numbers are sorted by descending order, eg. {25, 10, 5, 2, 1}
 target - a positive integer representing the target number of cents, eg. 99

 Assumptions
 coins is not null and is not empty, all the numbers in coins are positive
 target >= 0
 You have infinite number of coins for each of the denominations, you can pick any number of the coins.
 
 Return
 a list of ways of combinations of coins to sum up to be target.
 each way of combinatoins is represented by list of integer, the number at each index means the number of coins used for the denomination at corresponding index.
 
 Examples
 coins = {2, 1}, target = 4, the return should be

 [
 [0, 4],   (4 cents can be conducted by 0 * 2 cents + 4 * 1 cents)
 [1, 2],   (4 cents can be conducted by 1 * 2 cents + 2 * 1 cents)
 [2, 0]    (4 cents can be conducted by 2 * 2 cents + 0 * 1 cents)
 ]
 */

#include "Header.h"

/*
 1. what does it store on each level? (每层代表什么意义？一般来讲解题之前就知道DFS要recurse多少层)
	4 levels, and for each level, we put one kind of coins on it.
 2. How many different states should we try to put on this level? （每层有多少个状态/case 需要try？）
	how many coins with the same value that sum up (or less than) money_remaining.

                                            99 cents
                                 /                |                     |             \
 level 1:  25 cents  0 x 25 (99 remain)      1 x 25 (74 rem)     2 x 25 (49 rem)    3 x 25 (24 rem)
                        /|| \  ???????\             /||||\
 level 2: 10 cents    0x10,1x10….9x10(9)     0 x 10, 1x10 (64 remain) ... 7 x10
                                                        /||||\
 level 3: 5 cents  0 x 5			 	   0x5 ,1x5...total 13 states under this path
                   /||\
 level 4: 1 cents

 e.g. int [] input = {25, 10, 5, 1}
            result = {0,  9,  0, 9}
 
 
                                                            remaining=4
                                    /                             |                 \
 level 1: 2 cents           0*2(4 remain)                   1*2(2 remain)       2*2(0 remain)
                      /      /    |     \      \               /  |     \               |
 level 2: 1 cents  0*1(4) 1*1(3) 2*1(2) 3*1(1) 4*1(0)     0*1(2) 1*1(1) 2*1(0)         0*1(0)
 
 由上图可知，有几个cent(coins有多大，就有几层)
 每层的状态是，上一层结束后剩下多少，这一层可以放多少个相同面值的硬币
 base case:只有走到最后一层，即比较完coins里面不同面值的硬币，发现此时remaining面额为零时，才将这一路走下来尝试的结果放入result中
 
 下面的helper function中，index表示coins中每个元素的下标，index每次+1，index就表示的层数。
 我们把每层try的结果放在tmp里面，如果走完coins(index==coins.size()-1)时发现剩余target为零，
 就把这一路上try的所有结果(即tmp里面存的值放入result中)
 */
void helper_combinations(int target, vector<int> coins, vector<int> tmp, vector<vector<int>>& res, int index);

vector<vector<int> > combinations(int target, vector<int> coins){
    vector<vector<int>> res;
    if(coins.empty()) return res;
    vector<int> tmp(coins.size()); // 初始化的时候一定要指明他的大小，否则使用tmp[i]=t的时候会出问题
    helper_combinations(target, coins, tmp, res, 0);
    return res;
}

// index表示一共有几层，index只可能取0或者1
// 对于不同的index，count的取值范围随着remaining的不同而不同
// NOTE: 用for()来调用DFS，用for()来控制可以岔出几个茬
void helper_combinations(int target, vector<int> coins, vector<int> tmp, vector<vector<int>>& res, int index){
    if(index == coins.size()-1){
        // early termination, the remainder of target divided by the smallest coin must be 0 for a valid solutioin
        if(target % coins[index] == 0){
            tmp[index] = target / coins[index];
            res.push_back(tmp);
        }
        return;
    }

    // in each level, get how many states we should try
    int maxStates = target / coins[index];
    for(int count = 0; count <= maxStates; ++count){ // count值域[0,maxNum]. 因为可以取0个coins[index]
        tmp[index] = count;
        // get remaining after we put so many(number of count) coins[index] value to result
        int remain = target - count*coins[index];
        helper_combinations(remain, coins, tmp, res, index+1);
    }
}

/*
int main(){
    vector<int> coins = {2, 1};
    int target = 4;
    vector<vector<int>> res = combinations(target, coins);
    for(int i=0; i<res.size(); i++){
        vector<int> tmp = res[i];
        for(int j=0; j<tmp.size(); ++j)
            cout << tmp[j] << " ";
        cout << endl;
    }
    return 0;
}*/