//
//  Max Elem in Window.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/17/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an integer array A and a sliding window of size K, 
 find the maximum value of each window as it slides from left to right.

 Assumptions
 The given array is not null and is not empty
 K >= 1, K <= A.length

 Examples
 A = {1, 2, 3, 2, 4, 2, 1}, K = 3, the windows are {{1,2,3}, {2,3,2}, {3,2,4}, {2,4,2}, {4,2,1}},
 and the maximum values of each K-sized sliding window are [3, 3, 4, 4, 4]
 */

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

/*
 1 3 2 5 8 9 4 7 3,          WINDOW size k  == 3
 _____
     3
   _____
       5
    _____
        8
 array size: N, window size K

 Naive method:  for n  for k
 O(nk)    each time we ask for max_element, O(k)

 Max_Heap? if heap, how to remove the element out of window?
 O(nlog(k))  difficult to implement.

 Any better idea:
 1 3 2 5 8 9 4 7 3,
 _____
   3 2
   3 2 5
       5 8
         8 9 4 7 3

 SOME data_structure:  ⇒  Deque 双向操作元素

 trick: when we add A[i] to the window, scan from right to the left of deque and remove all elements smaller than A[i], insert A[i] to the right side of deque.
 Check the leftmost element of deque, if it is out of the size, remove it.

 Rule: the deque maintains a non-increasing sequence.
 */

vector<int> maxWindows(vector<int> array, int k) {
    vector<int> res;
    deque<int> dq;
    for(int i=0; i<array.size(); ++i){
        while(!dq.empty() && array[dq.back()]<=array[i]){
            dq.pop_back();
        }
        while(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }
        dq.push_back(i);
        if(i>=k-1){
            res.push_back(array[dq.front()]);
        }
    }
    return res;
}