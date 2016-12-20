//
//  Find Max in Sorted Reversed Arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/28/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Given sorted int array, first increasing, then decreasing, find the maximum value
#include "Header.h"

/*
 如果mid在递增区间，left = mid;
 如果mid在递减区间，right = mid;

 {1, 3, 7, 6, 4, 2, 0}

 mid - 1    mid  mid + 1     decresing   right part ,   right = mid
 mid - 1    mid  mid + 1     incresing    left part     left = mid;
 */

int max_in_rotated_reversed_arr(vector<int> arr){
    if(arr.empty()){
        return INT_MIN;
    }
    int left = 0;
    int right = arr.size()-1;

    while(left < right-1){
        int mid = left + (right-left)/2;
        if(arr[mid-1]>arr[mid] && arr[mid]>arr[mid+1]){
            right = mid;
        }else if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1]){
            left = mid;
        }else{
            return arr[mid];
        }
    }

    return arr[left]>arr[right]? arr[left]:arr[right];
}