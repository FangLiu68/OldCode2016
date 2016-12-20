//
//  K Smallest in Unsorted Array.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/29/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Find the K smallest numbers in an unsorted integer array A. The returned numbers should be in ascending order.

 Assumptions
 A is not null
 K is >= 0 and smaller than or equal to size of A
 Return
 an array with size K containing the K smallest numbers in ascending order
 Examples
 A = {3, 4, 1, 2, 5}, K = 3, the 3 smallest numbers are {1, 2, 3}
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 1. sort array and then return the left K elements. O(NlogN)
 2. heapify the array to make a new MIN_HEAP    O(N)
    pop out k times, then done.                 O(KlogN)
    total O(N+KlogK)
    space O(N)
 3. build a MAX_HEAP of size k with the first k elements.   O(K)
    interate over from k+1 elements all the way to the nth elements, and for each ith element, if ith element is smaller than the top element, then remove top and insert ith element.    2(n-k)logk
    total O(K+2(N-K)logK)=> O(NlogK)
    space O(K)
 所以当K较小的时候，取最大K个值就用min_heap，取最小K个值就用max_heap
 */

// Use a max heap of size k. We always maintain a heap of size k so that the smallest k
// elements are always there.
vector<int> k_smallest_in_unsorted_arr(vector<int> input, int k){
    vector<int> res;
    if(input.empty() || k<=0) return res; // pay attention when k<=0
    
    priority_queue<int> maxHeap;
    for(int i=0; i<input.size(); ++i){
        if(i < k){
            maxHeap.push(input[i]); // O(K)
        }else if(input[i] < maxHeap.top()){
            maxHeap.pop(); // O((N-K)logK)
            maxHeap.push(input[i]); // O((N-K)logK)
        }
    }
    while(!maxHeap.empty()){
        res.push_back(maxHeap.top());
        maxHeap.pop(); // KlogK
    }
    sort(res.begin(), res.end());
    return res;
}

// 看上面的做法
vector<int> k_smallest_in_unsorted_arrII(vector<int> input, int k) {
    vector<int> res;
    if(input.empty()) return res;
    priority_queue<int> max_heap;
    for(int i=0; i<input.size(); i++){
        max_heap.push(input[i]);
        if(max_heap.size() > k) max_heap.pop();
    }
    while(!max_heap.empty()){
        res.push_back(max_heap.top());
        max_heap.pop();
    }
    sort(res.begin(), res.end());
    return res;
}


/*
int main(){
    vector<int> arr(5);
    arr[0] = 3;
    arr[1] = 4;
    arr[2] = 1;
    arr[3] = 2;
    arr[4] = 5;
    vector<int> res = better_than_above(arr, 3);
    for(int i=0; i<res.size(); i++) cout << res[i] << " ";
    cout << endl;
    return 0;
}*/