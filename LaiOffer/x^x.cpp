//
//  x^x.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/3/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Given a helper function pow(a,b) that can compute a^b, how to calculate x^x^x^x^x…^x (total number of x == n,  n >0)

#include <iostream>
using namespace std;

/*
 Base case:  n ==1
 Recursive rule:

 2^2^       2^2   == 4^4            half_result  →  return pow(half_result, half_result);
 */

int pow(int a, int b);
int calculate(int x, int n){
    // base case
    if(n == 1){
        return x;
    }
    int half_res = calculate(x, n/2);
    if(n % 2 == 0){ // n is even
        return pow(half_res, half_res);
    }else{
        return pow(x, pow(half_res, half_res));
    }
}