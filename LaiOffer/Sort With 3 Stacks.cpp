//
//  Sort With 3 Stacks.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/7/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 The numbers are in s1 originally, after sorting, the numbers should be in s1 as well and from top to bottom the numbers are sorted in ascending order
 */

#include <stack>
#include <iostream>
using namespace std;

/*
 什么问题要往Stack 上考虑？
 Anwser: 从左到右linear scan 一个array/string时, 如果要不断回头看左边最新的元素时，往往要用到stack
 */

/*
 Sorting with 3 stacks. Given that all numbers are initially stored in one stack.   Requirements :O(1) space.
 bottom  3    1     5    2   7
 top
 size =4
 s1 = “3  ”
 s2 =
 s3 =   1 2 5 7 3
 stack   1   (org)
            2  (temp)
            3  (sorted)     7    2
 M1: (selection sort)
	1. S1 → S2 (all elements) to find the global min
	2. S2 → S1 (all elements but the global min), push global min to S3
 M2: (merge sort)
 */

// routine such that the top "size" elements of s1 will be sorted after routine
// finishes. To sort it, break down so that half will be handled as the top of
// s2, whereas the other half numbers will be handled as the top of s3.
void sortOneStackWithTwoOtherStacksHelper(stack<int>& s1, stack<int>& s2, stack<int>& s3, int size) {
    if (size <= 1) return;
    int mid = size / 2;
    int rest = size - mid;
    for (int i = 0; i < mid; ++i) {
        s2.push(s1.top());
        s1.pop();
    }
    sortOneStackWithTwoOtherStacksHelper(s2, s3, s1, mid);
    sortOneStackWithTwoOtherStacksHelper(s1, s3, s2, rest);
    // simple routine to merge two sorted stacks s1, s2 (local variables) into s3.
    int i = 0;
    int j = 0;
    while (i < mid && j < rest) {
        if (s2.top() < s1.top()) {
            s3.push(s2.top());
            s2.pop();
            i++;
        } else {
            s3.push(s1.top());
            s1.pop();
            j++;
        }
    }
    while (i < mid) {
        s3.push(s2.top());
        s2.pop();
        i++;
    }
    while (j < rest) {
        s3.push(s1.top());
        s1.pop();
        j++;
    }
    // Push the sorted numbers from s3 back to s1. s3 is now in descending order
    // from top to bottom.
    for (int index = 0; index < size; index++) {
        s1.push(s3.top());
        s3.pop();
    }
}

void sortOneStackWithTwoOtherStacks(stack<int>& s1) {
    stack<int> s2, s3;
    sortOneStackWithTwoOtherStacksHelper(s1, s2, s3, s1.size());
}
