//
//  Sort Arr based on Occurrence.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/30/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an unsorted array, sort array according to the first occurrence index of each element.
 For example, the indices of the first occurrence of two elements x and y are i and j, respectively,
 where i<j, then x should be put to the left hand side of y after sorting.
 */

#include <iostream>
#include <map>
using namespace std;

/*
 method 1: 用map记录每个单词出现的前后顺序，然后重新排列
 O(nlogn) time, O(n) space
 
 method 2: 
 从左端开始，对每个元素，在arr的右边开始做"delete dup element"的操作（运用快慢指针）
 上一步结束后，在最左端的的元素的后面，添加和自己value相同的元素
 
 1. move every element form [i+1, n-1] that equals to A[i] to its right
 2. two pointers, slow and fast
 3. every element that is not equals to A[i] should be on the right of slow
 4. every element between fast and slow should be A[i] (inclusive)
 */


