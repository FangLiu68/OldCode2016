//
//  pow.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// implement pow(x, n)

#include <iostream>

// O(logN) runtime, O(1) space
// recursion调用自己的时候每次都是n/2，那么n到1一共经历了logn次变化
long power(int a, int b) {
    if(b == 0){
        return 1; // base case
    }
    long half = power(a, b/2); // 要先把half这样表示出来，如果跳过这一步，下面会溢出（不知道为啥）
    
    if(b%2==0){
        return half*half;
    }else{
        return half*half*a;
    }
}

int pow(int x, int n){
    if(n == 0){
        return 1;
    }
    if(x == 0){
        return INT_MAX;
    }
    if(n < 0){
        return 1/power(x, -n);
    }else {
        return power(x, n);
    }
}