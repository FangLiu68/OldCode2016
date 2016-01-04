//
//  Valid UTF-8.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/8/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Determine if an byte array is valid UTF-8 string
 http://en.wikipedia.org/wiki/UTF-8#Description
 
 java里下面的type都是byte，这里用int代表对吗？
 */

#include <iostream>
using namespace std;


int get_len(int value);
bool isUTF8(int arr[], int size){
    for(int i=0; i<size; ){
        int first = arr[i];
        int len = get_len(first);
        if(len<0 || i+len>=size){
            return false;
        }
        for(int j=0; j<len; ++j){
            if(arr[i+j] & (0b11000000 != 0b10000000)){
                return false;
            }
            i = i+j+1;
        }
    }
    return true;
}

// return length of consecutive bytes
int get_len(int value){
    return 0;
}