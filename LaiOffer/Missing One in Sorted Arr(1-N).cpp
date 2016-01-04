//
//  Missing One in Sorted Arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/9/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/* [1-N], missing one number but array is sorted
    example: {1,3,4,5}, return 2.
 
 M1: bucket sort. O(N) time, O(1) space
 M2: binary search. find the first index, such that a[i] == i+2. O(logN) time.
*/

#include <vector>
#include <iostream>
using namespace std;

// bucket sort
int missing_in_sortedArr1(vector<int> input){
    if(input.empty()){
        return 1;
    }
    for(int i=0; i<input.size(); ++i){
        if(input[i] != i+1){
            return i+1;
        }
    }
    return input.size()+1;
}


// binary search
int missing_in_sortedArr(vector<int> input){
    if(input.empty()){
        return 1;
    }
    int left = 0;
    int right = input.size()-1;
    while(left < right-1){
        int mid = left + (right-left)/2;
        if(input[mid] == mid+2){
            right = mid;
        }else if(input[mid] < mid+2){
            left = mid;
        }
    }
    if(input[left] == left+2){
        return left+1;
    }else if(input[right] == right+2){
        return right+1;
    }
    return input.size()+1;
}
/*
int main(){
    vector<int> input = {1,2,4,5,6};
    cout << missing_in_sortedArr(input) << endl;
    return 0;
}*/