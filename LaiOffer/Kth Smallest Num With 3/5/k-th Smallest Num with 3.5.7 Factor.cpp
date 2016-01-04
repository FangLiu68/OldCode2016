//
//  7.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/14/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Find the Kth smallest number s such that s = 3 ^ x * 5 ^ y * 7 ^ z, x > 0 and y > 0 and z > 0, x, y, z are all integers.

 Assumptions
 K >= 1
 Examples
 the smallest is 3 * 5 * 7 = 105
 the 2nd smallest is 3 ^ 2 * 5 * 7 = 315
 the 3rd smallest is 3 * 5 ^ 2 * 7 = 525
 the 5th smallest is 3 ^ 3 * 5 * 7 = 945
 */

#include <vector>
#include <set>
#include <queue>
#include <iostream>
using namespace std;

struct comp{
    bool operator()(int a, int b){
        return a>b; // min heap
    }
};
/*
long kth(int k) {
    priority_queue<int, vector<int>, comp> min_heap;
    set<int> visited;
    min_heap.push(3*5*7);
    visited.insert(3*5*7);
    while(k > 1){
        int cur = min_heap.top();
        min_heap.pop();
        if()
    }
}*/
