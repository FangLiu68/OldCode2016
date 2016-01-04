//
//  kth Elem in Sorted Matrix.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/20/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a matrix of size N x M. 
 For each row the elements are sorted in ascending order, and for each column the elements are also sorted in ascending order. Find the Kth smallest number in it.

 Assumptions
 the matrix is not null, N > 0 and M > 0
 K > 0 and K <= N * M
 Examples
 { 
 {1,  3,  5,  7},
 {2,  4,  8,  9},
 {3,  5, 11, 15},
 {6,  8, 13, 18} 
 }
 the 5th smallest number is 4
 the 8th smallest number is 6
 */

#include <queue>
#include <set>
#include <iostream>
#include <vector>
using namespace std;

// A comparator class to be used by the heap (priority_queue).
// Each element of the heap is of type: pair<int, pair<int, int> >.
// A pair stores: pair<value, pari<x-axis, y-axis> > of the element.
struct Comp {
    bool operator()(pair<int, pair<int, int> > p1, pair<int, pair<int, int> > p2) {
        return p1.first > p2.first; // min_heap
    }
};

// Start with the upper-left element. Everytime we encounter an element, we push its right
// and underneath neighbors to the heap (provided that they haven’t been inserted before).
// When we popped the “kth” element from the heap, we’ve got the kth smallest.
int kthElementInSortedMatrix(vector<vector<int>>matrix, int k) {
    //if (k > N * N - 1) return -1;
    if(k > matrix.size()*matrix[0].size()) return -1;

    // We are using a min heap.
    // Each element is of the following format: pair<element_value, pair<element_xaxis, element_yaxis> >
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, Comp> min_heap;

    // The set is used to avoid pushing duplicate element to the heap.
    set<pair<int, int> > s; // set里面可以只存x-y坐标，也可以和min_heap一样存值和坐标
    int row = 0, col = 0;
    min_heap.push(make_pair(matrix[row][col], make_pair(row, col)));
    s.insert(make_pair(row,col));
    int res = INT_MIN;

    for(int i=0; i<k; i++){ // 找Kth个数，循环一定要走到第K个，否则进不了循环得不到res
        pair<int, pair<int, int> > p = min_heap.top();
        min_heap.pop();

        res = p.first;
        row = p.second.first;
        col = p.second.second;
        if(row < matrix.size()-1 && s.find(make_pair(row+1, col)) == s.end()){
            // Only push element to heap if it hasn’t been pushed before.
            s.insert(make_pair(row+1, col));
            min_heap.push(make_pair(matrix[row+1][col], make_pair(row+1, col)));
        }
        if(col < matrix[0].size() - 1 && s.find(make_pair(row, col + 1)) == s.end()){
            s.insert(make_pair(row, col + 1));
            min_heap.push(make_pair(matrix[row][col + 1], make_pair(row, col + 1)));
        }
    }
    return res;
}


//================

/* 和上面的做法一样  只是set里面存的是值和坐标
struct comp{
    bool operator()(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2){
        return p1.first > p2.first; // min heap
    }
};
int kthSmallest(vector<vector<int>> matrix, int k) {
    int ROW = matrix.size();
    int COL = matrix[0].size();
    if(k > ROW*COL){
        return INT_MIN;
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comp> min_heap;
    set<pair<int, pair<int, int>>> s;
    int row = 0;
    int col = 0;
    min_heap.push(make_pair(matrix[row][col], make_pair(row, col)));
    s.insert(make_pair(matrix[row][col], make_pair(row, col)));
    int res = INT_MIN;
    for(int i=0; i<k; ++i){
        pair<int, pair<int, int>> p = min_heap.top();
        min_heap.pop();
        res = p.first;
        row = p.second.first;
        col = p.second.second;
        if(row+1 < ROW && s.find(make_pair(matrix[row+1][col], make_pair(row+1, col))) == s.end()){
            min_heap.push(make_pair(matrix[row+1][col], make_pair(row+1, col)));
            s.insert(make_pair(matrix[row+1][col], make_pair(row+1, col)));
        }
        if(col+1 < COL && s.find(make_pair(matrix[row][col+1], make_pair(row, col+1)))== s.end()){
            min_heap.push(make_pair(matrix[row][col+1], make_pair(row, col+1)));
            s.insert(make_pair(matrix[row][col+1], make_pair(row, col+1)));
        }
    }
    return res;
}*/

/*
int main(){
    vector<int> v1 = {1,3,5,7};
    vector<int> v2 = {2,4,8,9};
    vector<int> v3 = {3,5,11,15};
    vector<int> v4 = {6,8,13,18};
    vector<vector<int>> arr = {v1,v2,v3,v4};
    int res = kthElementInSortedMatrix(arr, 4);
    cout << res << endl;
    return 0;
}*/