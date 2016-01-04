//
//  shift position.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an integer array A, A is sorted in ascending order first then shifted by an arbitrary number of positions, For Example, A = {3, 4, 5, 1, 2} (shifted left by 2 positions). Find the index of the smallest number.

 Assumptions
 There are no duplicate elements in the array
 Examples
 A = {3, 4, 5, 1, 2}, return 3
 A = {1, 2, 3, 4, 5}, return 0
 Corner Cases
 What if A is null or A is of zero length? We should return -1 in this case.
 */

#include "Header.h"

// 看下面的这两种做法，好记
// no duplicate. O(logN)
int findMin(vector<int>& nums) {
    if(nums.empty()){
        return 0;
    }
    int left = 0;
    int right = nums.size()-1;

    while(left < right-1){
        int mid = left+(right-left)/2;
        if(nums[mid]<nums[right]){ // 去掉右半部分，因为min肯定在无序的部分
            right = mid;
        }else{
            left = mid;
        }
    }

    return nums[left]<nums[right]? nums[left]:nums[right];
}

// has duplicate. O(N)
/*
 {3, 3, 3, 3, 3, 3}
 {3, 1, 3, 3, 3, 3}
 {3, 3, 3, 3, 1, 3}
 */
int findMin_dup(vector<int>& nums) {
    if(nums.empty()){
        return INT_MIN;
    }
    int left = 0;
    int right = nums.size()-1;

    while(left < right-1){
        int mid = left+(right-left)/2;
        if(nums[mid] < nums[right]){
            right = mid;
        }else if(nums[mid] > nums[right]){
            left = mid;
        }else{
            right--;
        }
    }
    
    return nums[left]<nums[right]?nums[left]:nums[right];
}








////////////////////////
/*
 中间数字把数组分成两部分，有序部分和无序部分。
 最小数字一定是在无序部分。
 同时最小数字的左右部分都是两个有序数组。而且左边有序数组的所有值都大于右边有序数组的所有值。
 用两个指针从头尾开始往中间靠拢。两个指针都分别处于两个排序数组中。
 当两个指针相遇时，左边指针指向左边有序数组的最大值，右边指针指向右边有序数组的最小值，即整个数组的最小值。
 */
int find_min_in_rotated_sorted_arr(vector<int> input) {
    if(input.empty()) return -1;
    int left = 0;
    int right = input.size()-1;
    if(input[left] <= input[right]) return left;
    while(left < right-1){
        int mid = left+(right-left)/2;
        if(input[left] <= input[mid]) { // left part is sorted(<=或者<都行)
            left = mid;
        }else{
            right = mid; // right part is sorted
        }
    }
    return right;
}

/*
 When you split the sorted, rotated array into two halves (arr[1],..,arr[mid]) and (arr[mid+1],..,arr[n]), one of them is always sorted and the other always has the min. We can directly use a modified binary search to keep searching in the unsorted half
 */
// 还是觉得这个方法好记。二分法，记住条件都弄成while(left <= right)
// NOTE：当mid大小正好在left/right中间时，表明没有rotate，直接返回最左边的值即可
// 当left right相遇时，right指向的是最小值
// time complexity O(logN) 注意这里要找的是Index
int find_min_rotated_sorted_arr(vector<int> input) {
    if(input.empty()) return -1;
    if(input.size()==1) return 0;
    int left = 0;
    int right = input.size()-1;
    int mid;
    while(left <= right){
        mid = left+(right-left)/2;

        // no rotate, then first element is result
        // 要先判断是否有序(原数组有序/ 更新后数组有序) 如 0 1
        if(input[left]<=input[mid] && input[mid]<=input[right])
            return left;

        // index left=right-1; then right is the res's index
        if(left == right-1)
            return right;

        if(input[left] < input[mid]) // left is sorted
            left = mid; // 记住每次去掉半边的时候, mid不能去掉。因为mid可能就是最小值。例如 3 1 2
        else // right is sorted
            right = mid;
    }
    return -1;
}


