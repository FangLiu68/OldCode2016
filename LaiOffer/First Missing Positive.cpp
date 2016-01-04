//
//  First Missing Positive.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/31/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an unsorted integer array, find the first missing positive integer.
 For example:
 Given [1,2,0] return 3
 Given [3,4,-1,1] return 2
 Your algorithm should run in O(n) time and uses constant space.
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 无序数组的题目如果要O(n)解法往往要用到hash table，但这题要求constant space。
 所以可以用数组本身作为一个"hash table"：A[0] = 1, A[1] = 2, .... A[n-1] = n。目标是尽可能将数字i放到数组第i-1个位置。

 扫描数组中每个数：
 1. 如果A[i]<1或者A[i]>n。说明A[i]一定不是first missing positive。跳过
 2. 如果A[i] = i+1，说明A[i]已经在正确的位置，跳过
 3. 如果A[i]!=i+1，且0<A[i]<=n，应当将A[i]放到A[A[i]-1]的位置，所以可以交换两数。
 这里注意，当A[i] = A[A[i]-1]时会陷入死循环。这种情况下直接跳过。
 */

int first_missing_positive(vector<int>& input){
    if(input.empty()){
        return 1;
    }
    
    for(int i=0; i<input.size(); ++i){
        while(input[i]!=i+1 && input[i]<=input.size() && input[i]>=1 && input[i]!=input[input[i]-1]){
            swap(input[i], input[input[i]-1]);
        }
    }
    
    for(int i=0; i<input.size(); ++i){
        if(input[i] != i+1){
            return i+1;
        }
    }
    return input.size()+1;
}
/*
int main(){
    vector<int> input = {3,4,-1,5};
    int res = first_missing_positive(input);
    for(int i=0; i<input.size(); ++i) cout << input[i] << " ";
    cout << endl << res << endl;
    return 0;
}*/