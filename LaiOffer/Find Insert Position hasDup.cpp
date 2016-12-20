//
//  Find Insert Position hasDup.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/2/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Same as previous one. 
 Find the inserting position in a sorted array for a target number
 {1, 2, 3, 3, 3, 6}, insert 3 -> @index 2
                     insert 4 -> @index 5
 */

#include "Header.h"

int find_insert_pos(vector<int> input, int target){
    // corner case
    if(input.size() == 0){
        return 0;
    }
    if(input.size() == 1){
        return input[0] >= target? 0 : 1;
    }
    
    int left = 0;
    int right = input.size() - 1;
    
    while(left < right){ // jump out when left == right
        int mid = left + (right - left)/2;
        if(input[mid] >= target){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    
    return left;
}

int find_insert_pos2(vector<int> input, int target){
    // corner case
    if(input.size() == 0){
        return 0;
    }
    if(input.size() == 1){
        return input[0] >= target? 0 : 1;
    }
    int left = 0;
    int right = input.size()-1;
    
    while(left < right-1){
        int mid = left + (right-left)/2;
        if(input[mid] >= target){
            right = mid;
        }else{
            left = mid;
        }
    }
    if(input[left] >= target){
        return left;
    }
    return input[right] >= target? right:right+1;
}