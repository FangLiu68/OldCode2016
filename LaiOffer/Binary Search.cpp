//
//  Binary Search.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include <iostream>

// classical binary search. O(logN)
int binary_search(int arr[], int len, int target){
    if(arr==NULL || len<=0) return -1;
    int left = 0;
    int right = len-1;
    int mid;
    while(left <= right){
        mid = left + (right-left)/2;
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] < target){
            left = mid+1;
        }else{
            right = mid-1;
        }

    }
    return -1;
}



