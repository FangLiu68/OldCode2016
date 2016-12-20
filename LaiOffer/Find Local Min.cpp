//
//  Find Local Min.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/28/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 given an unsorted integer array, return the position of any local minimum.
 +infi {1, 3, 2, 4, 5} +infi
 
 assumptions:
 1. no duplicates
 2. a[i] < a[i+1] && a[i] < a[i-1]
 */
#include "Header.h"

/*
 认为数组的最左边和最右边都是正无限大
 local min肯定是global min，可以找出global min O（N）

 {1, 2, 3, 4, 5}, {4, 3, 2, 1}
 1). does it exist? → global minimum element has to be local minimum
 2). Naive Solution → find the global minimum. O(n)
 
 a[mid] < a[mid+1] && a[mid] < a[mid-1] => mid is the result
 a[mid] > a[mid-1] => left - (mid-1) must contain one result
 a[mid] > a[mid+1] => (mid+1) - right must contain one result
 */

int localMin(vector<int> arr){
    if(arr.empty()){
        return -1;
    }
    int left = 0;
    int right = arr.size()-1;
    while(left < right-1){
        int mid = left + (right-left)/2;
        if(arr[mid]<arr[mid+1] && arr[mid]<arr[mid-1]){
            return mid;
        }else if(arr[mid] > arr[mid-1]){
            right = mid;
        }else{
            left = mid;
        }
    }
    return arr[left]<arr[right]? left:right;
}