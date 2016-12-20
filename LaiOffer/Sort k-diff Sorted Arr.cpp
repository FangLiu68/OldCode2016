//
//  Sort k-diff Sorted Arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/1/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 k-diff sorted array (each of the element has at most k as distance to its sorted position), how to sort it efficiently? < O(nlogn)
 example:
 A = {3, 2, 1, 5, 4, 6} k = 2;
 A'= {1, 2, 3, 4, 5, 6}
 */

#include "Header.h"

// min heap
struct comp{
    bool operator()(int p1, int p2){
        return p1 >= p2;
    }
};

/*
 O(nlogk)
 
 two operations:
 popMin() - O(logn)
 insert() - O(logn)
 */
void sor_k_diff_arr(vector<int>& input, int k){
    if(input.empty() || k <= 0){
        return;
    }
    
    priority_queue<int, vector<int>, comp> min_heap;
    
    for(int i = 0; i <= k; ++i){
        min_heap.push(input[i]);
    }
    
    for(int i = 0; i < input.size(); ++i){
        input[i] = min_heap.top();
        min_heap.pop();
        if(i+k+1 < input.size()){
            min_heap.push(input[i+k+1]);
        }
    }
}