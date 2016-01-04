//
//  Insert Interval.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/19/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

 You may assume that the intervals were initially sorted according to their start times.

 Example 1:
 Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

 Example 2:
 Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

 This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */

#include <vector>
#include <iostream>
using namespace std;

struct Interval{
    int start;
    int end;
    Interval() : start(0), end(0){}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> res;
    res.push_back(newInterval);
    for(int i=0; i<intervals.size(); i++){
        Interval newInt = res.back();
        res.pop_back();
        Interval* cur = &intervals[i];
        if(cur->end < newInt.start){
            res.push_back(*cur);
            res.push_back(newInt);
        }
        else if(cur->start > newInt.end){
            res.push_back(newInt);
            res.push_back(*cur);
        }
        else{
            newInt.start = min(cur->start, newInt.start);
            newInt.end = max(cur->end, newInt.end);
            res.push_back(newInt);
        }
    }
    return res;
}