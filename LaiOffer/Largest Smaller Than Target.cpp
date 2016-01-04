//
//  Largest Smaller Than Target.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/28/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// find an element whose value is largest smaller than target in a sorted array

#include "Header.h"

int largest_smaller_than(vector<int> arr, int target){
    if(arr.empty()){
        return INT_MIN;
    }
    if(arr[0] >= target){
        return INT_MIN;
    }else if(arr[arr.size()-1] < target){
        return arr[arr.size()-1];
    }
    int left = 0;
    int right = arr.size()-1;

    while(left < right-1){
        int mid = left + (right-left)/2;
        if(arr[mid] == target){
            return arr[mid-1];
        }else if(arr[mid] < target){
            left = mid;
        }else{
            right = mid;
        }
    }
    
    return arr[left];
}