//
//  Jump Game_jump to end or not.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/12/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array. Each element in the array represents your maximum jump length at that position. Determine if you are able to reach the last index. (return T/F)
 */

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
bool canJumpI(int arr[], int len){
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




