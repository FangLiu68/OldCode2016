//
//  Median Tracker.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/3/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an unlimited flow of numbers, keep track of the median of all elements seen so far.

 You will have to implement the following two methods for the class
 read(int value) - read one value from the flow
 median() - return the median at any time, return null if there is no value read so far
 
 Examples
 read(1), median is 1
 read(2), median is 1.5
 read(3), median is 2
 read(4), median is 2.5
 ......
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 保持两个heap大小相同，如果输入一共是奇数的话，max heap多存一个，那么到时候只用返回maxheap.top()就行
// unilize a min heap and a max heap, and always maintain the size balance between the two
class Median_tracker {
public:
    struct comp{
        bool operator()(int first, int second){
            return first > second;
        }
    };

    double median() {
        int size = max_heap.size() + min_heap.size();
        if(size == 0){
            throw "no such element";
        }else if(size % 2 != 0){
            return max_heap.top();
        }else{
            return (max_heap.top()+min_heap.top())/2.0;
        }
    }

    void read(int i) {
        // if maxHeap is empty or the value can be put into max heap, put into max heap
        // otherwise put into min heap
        if(max_heap.empty() || i <= max_heap.top()){
            max_heap.push(i);
        }else{
            min_heap.push(i);
        }
        // we maintain that, either the size of max heap == the size of min heap
        // or the size of max heap == the size of min heap+1
        if(min_heap.size() > max_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }else if(max_heap.size() > min_heap.size()+1){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }

private:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, comp> min_heap;
};