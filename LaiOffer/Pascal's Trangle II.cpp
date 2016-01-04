//
//  Pascal's Trangle II.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/29/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an index k, return the kth row of the Pascal's triangle.

 For example, given k = 3,
 Return [1,3,3,1].

 Note:
 Could you optimize your algorithm to use only O(k) extra space?
 */

#include <vector>
#include <iostream>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> res;
    if(rowIndex < 0){
        return res;
    }
    for(int i=0; i<=rowIndex; ++i){
        for(int j=i-1; j>0; --j){
            res[j] = res[j-1]+res[j];
        }
        res.push_back(1);
    }
    return res;
}