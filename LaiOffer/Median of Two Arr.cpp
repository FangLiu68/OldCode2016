//
//  Median of Two Arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/9/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given two arrays of integers, find the median value.

 Assumptions

 The two given array are not null and at least one of them is not empty
 The two given array are not guranteed to be sorted
 Examples

 A = {4, 1, 6}, B = {2, 3}, median is 3
 A = {1, 4}, B = {3, 2}, median is 2.5
 */

#include <vector>
#include <iostream>
using namespace std;

double helper_median(vector<int>& a, int a_start, vector<int>& b, int b_start, int k);
double median(vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(a.empty() && b.empty()){
        return INT_MIN;
    }else if(a.size()==1 && b.size()==1){
        return (a[0]+b[0])/2.0;
    }

    if(a.empty()){
        if(b.size() % 2 != 0){
            return b[b.size() / 2];
        }else{
            return (b[b.size()/2 - 1] + b[b.size()/2]) / 2.0;
        }
    }else if(b.empty()){
        if(a.size() % 2 != 0){
            return a[a.size() / 2];
        }else{
            return (a[a.size()/2 - 1] + a[a.size()/2]) / 2.0;
        }
    }else{
        int totalSize = a.size() + b.size();
        if(totalSize % 2 != 0){
            return helper_median(a, 0, b, 0, totalSize/2 + 1);
        }else{
            double left = helper_median(a, 0, b, 0, totalSize/2);
            double right = helper_median(a, 0, b, 0, totalSize/2 + 1);
            return (left + right) / 2;
        }
    }
}

// runtime KlogK
double helper_median(vector<int>& a, int a_start, vector<int>& b, int b_start, int k){
    if(k == 1){
        return min(a[a_start], b[b_start]);
    }
    if(a_start >= a.size()){
        return b[b_start + k - 1];
    }else if(b_start >= b.size()){
        return a[a_start + k - 1];
    }

    double a_val = (a_start + k/2 - 1) < a.size() ? a[a_start + k/2 - 1] : INT_MAX;
    double b_val = (b_start + k/2 - 1) < b.size() ? b[b_start + k/2 - 1] : INT_MAX;
    if(a_val < b_val){
        return helper_median(a, a_start + k/2, b, b_start, k - k/2);
    }else{
        return helper_median(a, a_start, b, b_start + k/2, k - k/2);
    }
}

double median2(vector<int> a, vector<int> b) {
    // a, b not null, not all empty.
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int al = 0;
    int bl = 0;
    int ll = (a.size() + b.size()) / 2;
    int med = INT_MIN;
    while (ll > 0) {
        if (bl >= b.size() || (al < a.size() && b[bl] >= a[al])) {
            med = a[al++];
        } else {
            med = b[bl++];
        }
        ll--;
    }
    int med2 = bl >= b.size() || (al < a.size() && b[bl] >= a[al]) ? a[al] : b[bl];
    if ((a.size() + b.size()) % 2 == 0) {
        return (med + med2) / 2.0;
    } else {
        return med2;
    }
}


/*
int main(){
    vector<int> a = {1};
    vector<int> b = {4};
    cout << median(a, b) << endl;
    return 0;
}*/