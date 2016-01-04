//
//  K-th Smallest Sum in Two Sorted Arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/30/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given two sorted arrays A and B, of sizes m and n respectively. Define s = a + b, where a is one element from A and b is one element from B. Find the Kth smallest s out of all possible s'.

 Assumptions

 A is not null and A is not of zero length, so as B
 K > 0 and K <= m + n
 Examples

 A = {1, 3, 5}, B = {4, 8}

 1st smallest s is 1 + 4 = 5
 2nd smallest s is 3 + 4 = 7
 3rd, 4th smallest s are 9 (1 + 8, 4 + 5)
 5th smallest s is 3 + 8 = 11
 */

#include <queue>
#include <iostream>
#include "assert.h"
#include <set>
using namespace std;

/*
 A = {1, 3, 6}
 B = {2, 7, 8}
 M[i][j] = A[i] + B[j]

 M = 3 * 3 Young’s Matrix:
      0    1    2
 0    3    8    9
 1    5   10   11
 2    8   13   14

 M[i][j] = A[i] + B[j]

 把two sorted arr的每个元素从左到右递增相加得到的和放入index对应的matrix里，可以看出这是一个young's matrix
 young's matrix的特点：
 the matrix sorted by each row, and the matrix sorted by each column
 1). if you start looking at the matrix from the top left corner, it is a heap.
 2). if you start looking at the matrix from the top right corner, it is a binary search tree.
 3). it is natural to think of a divide & conquer solution for problems on Young’s Matrix.
 
 所以，把matrix从左上角到右下角开始遍历，这是一个小根堆。
 维护一个size为K的小根堆，heap里存放的是 pair<value, pair<x-index, y-index>>，
 indexA 和 indexB 分别从有序数组A/B的最左边往右iterate，
 cur_sum 或者是(A[indexA+1]+B[indexB]), 或者是(A[indexA]+B[indexB+1])
 push cur_sum to heap, 同时用set去重复
 因为heap每次pop出的都是最小的，所以当pop (k-1)次之后，heap.top()就是k-th smallest one

 本质就是"k-th smallest number in sorted matrix"
 
 每个元素都要push进heap(logK)，再pop出heap(logK),一共有K个元素
 so runtime O(K(logK+logK)) = KlogK
 */


struct comp{
    bool operator()(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2){
        return p1.first > p2.first; // min heap
    }
};

int Kth_smallest_Sum_from_TwoSortedArr(vector<int> arr1, vector<int> arr2, int k){
    if(arr1.empty() || arr2.empty() || k<0){
        return INT_MIN;
    }
    int index1 = 0;
    int index2 = 0;
    set<pair<int, int>> s;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comp> minHeap;
    minHeap.push(make_pair(arr1[index1]+arr2[index2], make_pair(index1, index2)));
    s.insert(make_pair(index1, index2));
    int res = INT_MIN;
    for(int i=0; i<k; ++i){
        pair<int, pair<int, int>> p = minHeap.top();
        minHeap.pop();
        res = p.first;
        int cur_x = p.second.first;
        int cur_y = p.second.second;
        if(cur_x+1 < arr1.size() && s.find(make_pair(cur_x+1, cur_y)) == s.end()){
            minHeap.push(make_pair(arr1[cur_x+1]+arr2[cur_y], make_pair(cur_x+1, cur_y)));
            s.insert(make_pair(cur_x+1, cur_y));
        }
        if(cur_y+1 < arr2.size() && s.find(make_pair(cur_x, cur_y+1)) == s.end()){
            minHeap.push(make_pair(arr1[cur_x]+arr2[cur_y+1], make_pair(cur_x, cur_y+1)));
            s.insert(make_pair(cur_x+1, cur_y));
        }
    }
    return res;
}




// 看上面的算法，忽略下面的
int kthSum(vector<int> a, vector<int> b, int k) {
    assert(!a.empty() && !b.empty());
    assert(k>0 && k<=a.size()*b.size());
    int indexa = 0;
    int indexb = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comp> min_heap;
    set<pair<int, int>> s;
    min_heap.push(make_pair(a[0]+b[0], make_pair(0, 0)));
    s.insert(make_pair(0, 0));

    // 这里也可以循环 i [0,k)
    for(int i=0; i<k; ++i){
        pair<int, pair<int, int>> cur = min_heap.top();
        min_heap.pop();
        int val = cur.first;
        indexa = cur.second.first;
        indexb = cur.second.second;
        // 不确定终止条件的i的值时，可以这么想：假设k==1，那么i==0就应该直接返回，所以终止条件应该是i==k-1
        if(i == k-1){
            return val;
        }
        if(indexa<a.size()-1 && s.find(make_pair(indexa+1, indexb)) == s.end()){
            min_heap.push(make_pair(a[indexa+1]+b[indexb], make_pair(indexa+1, indexb)));
            s.insert(make_pair(indexa+1, indexb));
        }
        if(indexb<b.size()-1 && s.find(make_pair(indexa, indexb+1)) == s.end()){
            min_heap.push(make_pair(a[indexa]+b[indexb+1], make_pair(indexa, indexb+1)));
            s.insert(make_pair(indexa, indexb+1));
        }
    }
    return -1;
}


//=================
// O(n^2+n^2logK)
int kth_smallest_Sum_twoSortedArr_queue(vector<int> a, vector<int> b, int k) {
    int lenA = a.size();
    int lenB = b.size();
    priority_queue<int> pq;
    for(int i=0; i<lenA; i++){
        for(int j=0; j<lenB; j++){
            int sum = a[i] + b[j];
            pq.push(sum);
            if(pq.size() > k) pq.pop();
        }
    }
    return pq.top();
}
