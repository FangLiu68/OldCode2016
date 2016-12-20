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

/*
 下面的做法适用于has non-dup or dup elements.
 Find the largest smaller than the target, suppose the answer(its index) is i, then the insert position should be i+1
 we should guarantee the answer is always in [left, right]
 what are all the posible cases after while() loop is exited:
 left <= right < target
 left < target <= right
 target <= left <= right
 */
int find_insert_pos(vector<int> nums, int target){
    if(nums.empty()){
        return -1;
    }
    
    int left = 0;
    int right = nums.size() - 1;
    
    while(left+1 < right){
        int mid = left + (right-left)/2;
        if(nums[mid] < target){
            left = mid;
        }else if(nums[mid] > target){
            right = mid-1;
        }else{
            right = mid-1;
        }
    }
    
    // 包含了size()==1的情况
    if(nums[right] < target){
        return right+1;
    }else if(nums[left] >= target){
        return left;
    }else{
        return right;
    }
}

/*
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
*/
