//
//  Merge Two Sorted Arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/28/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given two sorted integer arrays A and B, merge B into A as one sorted array.

 Note:
 You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
 */
#include <vector>
#include <iostream>
using namespace std;

void merge_two_sorted_arr(int A[], int m, int B[], int n) {
    if(A == NULL || B == NULL || m<0 || n<0) return;
    int indexA = m-1;
    int indexB = n-1;
    int indexRes = m+n-1;
    while(indexA >=0 && indexB >=0){
        if(A[indexA] > B[indexB]){
            A[indexRes--] = A[indexA--];
        }else{
            A[indexRes--] = B[indexB--];
        }
    }
    while(indexB>=0){ // >=
        A[indexRes--] = B[indexB--];
    }
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    if(nums1.empty() || nums2.empty() || m<=0 || n<=0){
        return;
    }
    
    int last_merge_index = m+n-1;
    int last1 = m-1;
    int last2 = n-1;
    
    while(last1>=0 && last2>=0){
        nums1[last_merge_index--] = (nums1[last1]>=nums2[last2])? nums1[last1--] : nums2[last2--];
    }
    
    while(last2 >= 0){
        nums1[last_merge_index--] = nums2[last2--];
    }
}