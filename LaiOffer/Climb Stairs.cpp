//
//  Climb Stairs.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 A child is running up a staircase with n steps, and can hop either 1 step, 2 steps, or 3 steps at a time. 
 Implement a method to count how many possible ways the child can run up the stairs.
 */

#include "Header.h"

// use recursion. upper bound O(3^N)
long long countWays(int n){
    if(n < 0){
        return 0;
    }else if(n == 0){
        return 1;
    }else{
        return countWays(n-1) + countWays(n-2) + countWays(n-3);
    }
}

// dp 如何解决overflow的问题？？
long long countWaysI(int n){
    if(n < 0){
        return 0;
    }else if(n == 0){
        return 1;
    }else if(n == 1){
        return 1;
    }else if(n == 2){
        return 2;
    }else if(n == 3){
        return 4;
    }else{
        int res = 0;
        int first = 1;
        int second = 2;
        int third = 4;
        for(int i = 3; i <= n; ++i){
            res = first + second + third;
            first = second;
            second = third;
            third = res;
        }
        return res;
    }
}