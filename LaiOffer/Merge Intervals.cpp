//
//  Merge Intervals.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/27/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//


/*
 Given a collection of intervals, merge all overlapping intervals.
 
 For example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18].
 */

#include <vector>
#include <iostream>
using namespace std;

struct Interval{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct compInterval{
    bool operator()(const Interval &a, const Interval &b){
        return a.start < b.start;
    }
};

vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> res;
    if(intervals.empty()) return res;
    
    sort(intervals.begin(), intervals.end(), compInterval());
    
    for(int i=0; i<intervals.size(); ++i){
        if(res.empty() || res.back().end < intervals[i].start){
            res.push_back(intervals[i]);
        }else{
            res.back().end = max(res.back().end, intervals[i].end);
        }
    }
    
    return res;
}