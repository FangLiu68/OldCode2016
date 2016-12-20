//
//  Summary Ranges.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/10/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a sorted integer array without duplicates, return the summary of its ranges.
 
 For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 */

#include "Header.h"

string helper(int from, int to){
    stringstream temp;
    if(from == to){
        temp << from;
    }else{
        temp << from << "->" << to;
    }
    return temp.str();
}

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    int start = 0;
    int end = 0;
    while(end < nums.size()){
        while(end < nums.size()-1 && nums[end+1]-nums[end]==1){
            end++;
        }
        res.push_back(helper(nums[start], nums[end]));
        start = end+1;
        end = start;
    }
    return res;
}

