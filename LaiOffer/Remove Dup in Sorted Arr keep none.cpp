//
//  Remove Dup in Arr III.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/20/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a sorted integer array, remove duplicate elements. For each group of elements with the same value do not keep any of them. Do this in-place, using the left side of the original array and and maintain the relative order of the elements of the array. Return the length of the final array.

 Assumptions

 The given array is not null
 Examples

 {1, 2, 2, 3, 3, 3} → {1}, return 1
 */

#include <vector>
#include <iostream>
using namespace std;

vector<int> remove_dup_III(vector<int>& input) {
    if(input.size()<2) return input;
    int index = 0;
    // 指的是包括input[index]是不是重复的一部分
    bool tag = false; // indicate wether we are currently having duplication
    for(int i=1; i<input.size(); i++){
        if(input[index] == input[i]){ // if the element scanned == index element
            tag = true; // flag indicate we are currently having duplication
        }
        else if(tag == false){ // not case 1 and we don't have duplication
            input[++index] = input[i];
        }
        else{
            input[index] = input[i]; // note case 1 2
            tag = false;
        }
    }
    if(tag==false) index++;
    input.erase(input.begin()+index, input.end());
    return input;
}

int remove_dup_in_arr_III(vector<int>& input) {
    if(input.size() < 2) return input.size();
    int end = 0;
    bool flag = false;
    for(int i=1; i<input.size(); i++){
        if(input[i] == input[end])
            flag = true;
        // replace array[end] with current candidate value of array[i],
        // whether it should be retained will be determined later.
        else if(flag){
            input[end] = input[i];
            flag = false;
        }
        // if flag is not turned on, means array[end] has no duplicate
        // values and it should be retained.
        else
            input[++end] = input[i];
    }
    // if flag is turned on, means the element of array[end]
    // should be deleted.
    if(!flag) end++;
    input.erase(input.begin()+end, input.end());
    return end;
}