//
//  Jump Game_jump to end or not.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/12/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 Each element in the array represents your maximum jump length at the position.
 Determine if you are able to reach the last index.
 
 For example
 0 1 2 3 4
 A = [2,3,1,1,4], return true.
 A = [3,2,1,0,4], return false.
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 For example:
 index  0 1 2 3 4
 A =   [2,3,1,1,4], return true.
 B =   [3,2,1,0,4], return false.

 index   0 1 2 3 4
 A=     [2,3,1,1,0],
 start	goal
 M=    [ x x x X T]
               i  j     ← direction to scan
            i + A[i]

 Base case: M[n-1] = True
 Induction rule: 
 M[i] = Case1: if( i + A[i] >= n-1)                 M[i] = true; (jump out of the scope)
        Case2: if (M[j] == T && j <= i + A[i])      M[i] = true;
                  (M[j] can reach the goal && if j can be reached from i)
 倒着从右往左走
 先设置最右边的值为true  看根据A[i]能不能走到A[0]的位置
 */

/*
 maxIndex: for current index i, the max index we can get
 in order to reach to the end, the maxIndex should >= n-1
 
 当跳到位置i后，能达到的最大距离至少是i+A[i]
 1. 能跳到位置i的条件：i <= maxIndex
 2. 一旦跳到i，则maxIndex = max(maxIndex, i+A[i])
 3. 能跳到最后一个位置n-1的条件是：maxIndex >= n-1
 
 if (maxIndex>=nums.size()-1), we could definitely reach to the end
 if (i > maxIndex), we could not get to i
 */

// time O(N), space O(1)
bool canJumpI(vector<int>& nums) {
    if(nums.empty()){
        return false;
    }
    
    int maxIndex = 0;
    for(int i=0; i<nums.size(); ++i){
        if(maxIndex >= nums.size()-1 || i > maxIndex) break;
        maxIndex = max(maxIndex, i + nums[i]);
    }
    
    return maxIndex>=nums.size()-1 ? true:false;
}

bool canJump(int input[], int len) {
    if(len==1) return true;
    bool last = true;
    bool cur = false;
    for(int i = len-2; i >= 0; --i){
        if(i+input[i] >= len-1){
            cur = true;
        }else if(last && i+input[i]>=i+1){
            cur = true;
        }else{
            cur = false;
        }
        last = cur;
    }
    return cur;
}

// same as above
bool canJump1(int arr[], int len){
    if(arr==NULL || len<=0){
        return false;
    }
    bool* table = new bool[len];
    table[len-1] = true;
    for(int i = len-2; i >= 0; --i){
        if(i+arr[i] >= len-1){ // 注意这里是>=len-1
            table[i] = true;
        }else if(table[i+1] && i+arr[i]>=i+1){
            table[i] = true;
        }else{
            table[i] = false;
        }
    }
    bool res = table[0];
    delete[] table;
    return res;
}




