//
//  Arrange to Form Biggest Num.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/3/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array of numbers in string type, arrange them in a way that yields the largest value. For example.  For example,  if the given numbers are {“54”, “546”, “648”, “88”}, the arrangement “88 648 546 54” gives the largest value.
 */

#include "Header.h"

// 同 largest number
bool compare(const string& str1, const string& str2){
    return (str1+str2) > (str2+str1);
}

vector<string> getBiggestNum(vector<string> input){
    if(input.empty()){
        return vector<string>();
    }
    sort(input.begin(), input.end(), compare);
    return input;
}

/*
int main(){
    vector<string> input = {"5", "546", "648", "88"};
    vector<string> res = getBiggestNum(input);
    for(int i=0; i<res.size(); ++i){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}*/