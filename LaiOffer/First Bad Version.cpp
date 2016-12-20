//
//  First Bad Version.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/2/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.
 
 Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
 
 You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
 */

#include "Header.h"

bool isBadVersion(int n);

int firstBadVersion(int n) {
    if(n <= 0){
        return -1;
    }
    
    int left = 0;
    int right = n;
    
    while(left < right - 1){
        int mid = left + (right - left)/2;
        if(isBadVersion(mid)){
            right = mid;
        }else{
            left = mid;
        }
    }
    
    return isBadVersion(left)? left : right;
}