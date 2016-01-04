//
//  Merge K Sorted Arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Merge K sorted array into one big sorted array in ascending order.
 Assumptions
 The input arrayOfArrays is not null, none of the arrays is null either.
 
 1 3 5 7 9
 2 4 8 19
 */

#include <vector>
#include <queue>
#include <iostream>
using namespace std;
/*
struct comp{
    bool operator()(int first, int second){
        return first > second; // min heap
    }
};

vector<int> merge_k_sorted_arr(vector<vector<int>> arr){
    vector<int> res;
    if(arr.empty()) return res;
    if(arr.size() <= 1) return res;
    priority_queue<int, vector<int>, comp> min_heap;
    for(int i=0; i<arr.size(); i++){
        vector<int> cur = arr[i];
        min_heap.push(cur[0]);
    }
    while(!min_heap.empty()){
        int top = min_heap.top();
        res.push_back(top);
        min_heap.pop();

    }
    return res;
}*/
/*
struct Entry{
    int x; // vector index in the arr
    int y; // value index in the vector
    int val;
    Entry(int _x, int _y, int _val):x(_x), y(_y), val(_val){}
};

struct comp{
    // index of the vector <--> value
    bool operator()(Entry val1, Entry val2){
        return val1.val > val2.val; // min heap
    }
};

vector<int> merge_k_sorted_arr(vector<vector<int>> arr){
    vector<int> res;
    if(arr.empty() || arr.size()<=1) return res;
    priority_queue<Entry, vector<Entry>, comp> min_heap;
    for(int i=0; i<arr.size(); ++i){
        vector<int> cur = arr[i];
        Entry* new_elem = new Entry(i, 0, cur[0]);
        min_heap.push(*new_elem);
    }
    while(!min_heap.empty()){
        Entry top = min_heap.top();
        min_heap.pop();
        res.push_back(top.val);
        if(top.x < arr.size() && top.y < arr[top.x].size()){
            Entry* next_elem = new Entry(top.x, top.y+1, arr[top.x][top.y+1]);
            min_heap.push(*next_elem);
        }else if(top.x < arr.size()-1 && top.y == arr[top.x].size()){
            Entry* next_elem = new Entry(top.x+1, 0, arr[top.x+1][0]);
            min_heap.push(*next_elem);
        }
    }
    return res;
}


int main(){
    vector<int> arr1 = {1,3,8};
    vector<int> arr2 = {2,4,10};
    vector<int> arr3 = {5,6,9};
    vector<vector<int>> arr = {arr1, arr2, arr3};
    vector<int> res = merge_k_sorted_arr(arr);
    for(int i=0; i<res.size(); i++) cout << res[i] << " ";
    cout << endl;
    return 0;
}*/

/*
// Comp functor for a min heap.
class kWayMergeComp {
public:
    bool operator()(pair<int, pair<int, int> > p1, pair<int, pair<int, int> > p2) {
        return p1.first > p2.first;
    }
};

// Find 1st element's index whose element is bigger than val
int findNextIdx(vector<int> v, int left, int right, int val) {
    if (left > right) return -1;
    if (left == right) {
        if (v[left] <= val) return left;
        else return -1;
    }
    int mid = left + (right - left) / 2;
    if (v[mid] <= val && v[mid + 1] > val) return mid;
    else if (v[mid] > val) return findNextIdx(v, left, mid - 1, val);
    else if (v[mid + 1] <= val) return findNextIdx(v, mid + 1, right, val);
}

vector<int> kWayMerge(vector<int> v[], int size) {
    // Each element is
    // pair<value, pair<which_vector (row), vector_index (column)>>
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, kWayMergeComp> pq;
    for (int i = 0; i < size; i++) {
        pq.push(make_pair(v[i][0], make_pair(i, 0)));
    }
    pair<int, pair<int, int> > p;
    vector<int> res;
    while (!pq.empty()) {
        p = pq.top();
        pq.pop();
        int val = p.first;
        res.push_back(val);
        int next = pq.top().first;
        // This is an optimization, such that for the candidate vector, all values that are less
        // than the current pq.top's value should be all moved to the result vector.
        int idx = findNextIdx(v[p.second.first], p.second.second + 1, v[p.second.first].size() - 1, next);
        if (idx == -1) {
            if (p.second.second < v[p.second.first].size() - 1)  // boundary condition
                pq.push(make_pair(v[p.second.first][p.second.second + 1], make_pair(p.second.first, p.second.second + 1)));
            continue;
        }
        for (int i = p.second.second + 1; i <= idx; i++) {
            res.push_back(v[p.second.first][i]);
        }
        if (idx < v[p.second.first].size() - 1)   // boundary condition
            pq.push(make_pair(v[p.second.first][idx + 1], make_pair(p.second.first, idx + 1)));
    }
    return res;
}*/