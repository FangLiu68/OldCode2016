//
//  Rotate Array.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/28/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Rotate an array of n elements to the right by k steps.

 For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 Note:
 Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 */

#include <iostream>
using namespace std;

/*
 先整个数组reverse
 再分段各自reverse
 */
void helper_swap(int nums[], int left, int right);
void rotate(int nums[], int n, int k) {
    if(nums == NULL || n<=0){
        return;
    }
    k = k % n; // 注意这里。因为K可能大于N
    helper_swap(nums, 0, n-1);
    helper_swap(nums, 0, k-1);
    helper_swap(nums, k, n-1);
}

void helper_swap(int nums[], int left, int right){
    if(nums==NULL || left<0 || right<0 || left==right){
        return;
    }
    while(left < right){
        int tmp = nums[left];
        nums[left++] = nums[right];
        nums[right--] = tmp;
    }
}