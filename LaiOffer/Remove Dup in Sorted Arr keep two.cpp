//
//  Remove Dup in Arr II.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/20/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a sorted integer array, remove duplicate elements. For each group of elements with the same value keep at most two of them. Do this in-place, using the left side of the original array and maintain the relative order of the elements of the array. Return the length of the final array.

 Assumptions

 The given array is not null
 Examples

 {1, 2, 2, 3, 3, 3} → {1, 2, 2, 3, 3}, return 5
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> remove_dup_in_arr_II(vector<int>& input) {
    if(input.size()<=2) return vector<int>();

    int index = 2;
    int runner = 2;
    while(runner < input.size()){
        if(input[index-2] == input[runner]){
            runner++;
        }else{
            input[index++] = input[runner++];
        }
    }
    input.erase(input.begin()+index, input.end());
    return input;
}