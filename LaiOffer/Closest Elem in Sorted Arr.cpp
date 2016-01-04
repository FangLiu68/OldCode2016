//
//  closest to target.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a target integer T and an integer array A sorted in ascending order, find the index i in A such that A[i] is closest to T.

 Assumptions
 There can be duplicate elements in the array, and we can return any of the indices with same value.
 Examples

 A = {1, 2, 3}, T = 2, return 1
 A = {1, 4, 6}, T = 3, return 1
 A = {1, 4, 6}, T = 5, return 1 or 2
 A = {1, 3, 3, 4}, T = 2, return 0 or 1 or 2
 Corner Cases
 What if A is null or A is of zero length? We should return -1 in this case.
 */

#include "Header.h"

int find_closest_num(int arr[], int len, int target){
    if(arr==NULL || len<=0) return -1;
    int left = 0;
    int right = len-1;
    int mid;

    while(left < right-1){
        mid = left + (right-left)/2;
        if(arr[mid] == target) return mid;
        // left = mid+1还是left=mid，可以这么看：如果你写成mid+1，表明你就彻底舍弃arr[mid]这个值了，
        // 但我们还不知道arr[mid]是不是最close的，我们还没跟他旁边的数比较，所以不能舍去arr[mid]
        else if(arr[mid] < target) left = mid;
        else right = mid;
    }
    
    if(abs(arr[left]-target) <= abs(arr[right]-target)){
        return left;
    }else{
        return right;
    }
}