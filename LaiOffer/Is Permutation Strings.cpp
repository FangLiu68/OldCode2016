//
//  Is Permutation Strings.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/1/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Given two strings, decide if one is a permutation of the other.

#include "Header.h"

// assume all chars are ASCII
// runtime O(2N)
bool permutationStr(string str1, string str2){
    if(str1.size() != str2.size()){
        return false;
    }
    int count[256];
    for(int i=0; i<256; ++i){
        count[i] = 0;
    }
    for(int i=0; i<str1.size(); ++i){
        count[str1[i]]++;
    }
    for(int i=0; i<str2.size(); ++i){
        count[str2[i]]--;
        if(count[str2[i]] < 0){
            return false;
        }
    }
    return true;
}



// O(NlogN) runtime
bool isPermutationStr(string str1, string str2){
    if(str1.size() != str2.size()){
        return false;
    }
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return (str1 == str2);
}