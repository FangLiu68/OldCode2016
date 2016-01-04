//
//  sqrt.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/29/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 mplement int sqrt(int x).
 Compute and return the square root of x.
 */

/*
 用二分的方法，在一个区间中，每次拿中间数的平方来试验，如果大了，就再试左区间的中间数；如果小了，就再拿右区间的中间数来试。比如求sqrt(16)的结果，你先试（0+16）/2=8，8*8=64，64比16大，然后就向左移，试（0+8）/2=4，4*4=16刚好，你得到了正确的结果sqrt(16)=4。
 */
// time compleixty O(logN), space complexity O(1)
#include <iostream>
using namespace std;

int mySqrt(int x) {
    if(x<2) return x;
    int left = 1;
    int right = x;
    while(left < right-1){
        int mid = left+(right-left)/2;
        if(x/mid == mid){
            return mid;
        }else if(x/mid < mid){
            right = mid;
        }else{
            left = mid;
        }
    }
    if(x/right > right){ // 向下取整
        return right;
    }else{
        return left;
    }
}

int sqrt1(int x) {
    int left = 1;
    int right = x/2; // right=x也行
    int last_mid = 0; //记录最近一次mid
    if(x < 2) return x;
    while(left <= right){
        int mid = (left+right)/2;
        if(x/mid > mid){ // 不要用 x>mid*mid,会溢出
            left = mid+1;
            last_mid = mid;
        }
        else if(x/mid < mid)          right = mid-1;
        else    return mid;
    }
    return last_mid;
}
