//
//  Interval Coverage.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/16/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a number of intervals, a total coverage length shoudl be calculated.
 
 public interface Intervals{
    // adds an interval [from, to) into an internal structure
    void addInterval(int from, int to);
 
    // returns a total length covered by teh added intervals
    // if several intervals intersect, the intersection should be counted only once.
    int getTotalCoveredLength();
 }
 
 example:
 addInterval(3, 6)
 addInterval(8, 9)
 addInterval(1, 5)
 getCoverage -> 6
 */

#include <vector>
#include <iostream>
using namespace std;
