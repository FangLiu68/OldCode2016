//
//  2Sum 2 Arrays.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given two arrays A and B, determine whether or not there exists a pair of elements, one drawn from each array, that sums to the given target number.

 Assumptions
 The two given arrays are not null and have length of at least 1
 Examples
 A = {3, 1, 5}, B = {2, 8}, target = 7, return true (pick 5 from A and pick 2 from B)
 A = {1, 3, 5}, B = {2, 8}, target = 6, return false
 */

#include <iostream>
#include <vector>
using namespace std;

bool existSum(vector<int> a, vector<int> b, int target) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ai = 0;
    int bi = b.size() - 1;
    while (ai < a.size() && bi >= 0) {
        if (a[ai] + b[bi] == target) {
            return true;
        } else if (a[ai] + b[bi] < target) {
            ai++;
        } else {
            bi--;
        }
    }
    return false;
}