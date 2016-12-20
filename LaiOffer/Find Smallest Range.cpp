//
//  Find Smallest Range.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/1/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 k sorted array/list, pick one element from each of them, what is the smallest range, the range is defined as teh difference between the largest one and the smallest one?
 
 Example:
 {1,  5, 11}
 {2, 4, 20}
 {6, 15}
 
 [1, 2, 6], - 5 
 [1, 4, 15] - 14
 [4, 5, 6] is the smallest range, should return 2.
 
 {1,  5, 11}
 i
 {2, 4, 20}
 j
 {6, 15}
 k
 
 [1, 2, 6] → from the other array, we need to know the smallest value >= 1.
 [2, 5, 6]
 [4, 5, 6]
 [5, 6, 20]
 [6, 11, 20]
 [11, 15, 20]
 ….
 */

#include "Header.h"

/*
 size k min heap containing the smallest unprocessed elements in each of the k arrays.
 the range is [min value of the minheap,   max value of the minheap]
 poll the smallest element from the minheap, and the newly offered element is guaranteed to be >= polled element.  
 we can use a global variable to record the max value in the minheap.
 */

// min heap. pair<pair<x, y>, matrix[x][y]>
struct comp{
    bool operator()(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2){
        return p1.second >= p2.second;
    }
};

/*
 Example:
 {1,  5, 11}
 {2, 4, 20}
 {6, 15}
 */
int get_smallest_range(vector<vector<int>> input){
    if(input.empty()){
        return INT_MIN;
    }
    
    int smallest_range = INT_MAX;
    
    // pair<pair<x, y>, matrix[x][y]>
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, comp> min_heap;
    
    int cur_max = INT_MIN;
    
    // push first k elements into min heap
    for(int i = 0; i < input.size(); ++i){
        min_heap.push(make_pair(make_pair(i, 0), input[i][0]));
        cur_max = max(cur_max, input[i][0]);
    }
    
    while(min_heap.size() == input.size()){
        pair<pair<int, int>, int> cur_min = min_heap.top();
        min_heap.pop();
        smallest_range = min(smallest_range, cur_max - cur_min.second);
        
        if(cur_min.first.second+1 < input[cur_min.first.first].size()){
            pair<pair<int, int>, int> new_push = make_pair(make_pair(cur_min.first.first, cur_min.first.second+1), input[cur_min.first.first][cur_min.first.second+1]);
            min_heap.push(new_push);
            cur_max = max(cur_max, new_push.second);
        }
    }
    
    return smallest_range;
}

