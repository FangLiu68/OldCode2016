//
//  Search with Empty Str.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/6/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Given a sorted array of strings which is interspersed with empty strings, write a method to find the location of a given string.

#include "Header.h"

int searchWithEmptyStr(vector<string> input, string target){
    if(input.empty()) return -1;
    int left = 0;
    int right = input.size() - 1;
    while(left <= right){
        int mid = left + (right-left)/2;

        if(input[mid].empty()){
            int smaller = mid - 1;
            int bigger = mid + 1;
            while(true){
                if(smaller < left && bigger > right){
                    return -1;
                }else if(bigger < right && !input[bigger].empty()){
                    mid = bigger;
                    break;
                }else if(smaller > left && !input[smaller].empty()){
                    mid = smaller;
                    break;
                }
                smaller--, bigger++;
            }
        }

        if(input[mid] == target){
            return mid;
        }else if(input[mid] < target){
            left = mid + 1;
        }else{
            right= mid - 1;
        }
    }

    return -1;
}

