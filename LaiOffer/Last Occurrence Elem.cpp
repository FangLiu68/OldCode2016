//
//  Last Occurrence Elem.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Given a sorted array, return the last index of the target element. If the target couldn't be found, return -1.

#include <iostream>

int last_occur_elem(int arr[], int len, int target){
    if(arr==NULL || len<=0) return -1;
    int left = 0;
    int right = len-1;
    int mid;

    while(left < right-1){
        mid = left + (right-left)/2;
        if(arr[mid] == target)
            left = mid;
        else if (arr[mid] < target)
            left = mid+1;
        else right = mid-1;
    }
    
    if(arr[right] == target) return right;
    if(arr[left] == target) return left;
    return -1;
}