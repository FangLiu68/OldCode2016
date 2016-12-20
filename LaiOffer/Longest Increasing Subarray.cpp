//
//  Longest Ascending Subarray.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/12/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an unsorted array, find the length of the longest subarray in which the numbers are in ascending order.
 For example: If the input array is {7, 2, 3, 1, 5, 8, 9, 6}, 
 the subarray with the most numbers in ascending order is {1, 5, 8, 9} and the expected output is 4
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 1. Base case           M[0] = 1;
 2. Induction rule:     
 M[i]  represents the length of the LONGEST ascending subarray (including A[i]) from  A[0] to A[i]
       including A[i] itself

 M[i] = M[i-1] + 1   if (A[i] > A[i-1])
 M[i] = 1            otherwise.
 */

int Longest_Ascending_subarr(int arr[], int len){
    if(arr == NULL || len <= 0){
        return -1;
    }
    int max_len = 1;
    int cur_len = 1; // for M[0]
    for(int i = 1; i < len; ++i){
        if(arr[i] > arr[i-1]){
            cur_len++; // cur_len 代表M[i]
            max_len = max(max_len, cur_len);
        }else{
            cur_len = 1;
        }
    }
    return max_len;
}

int longest(vector<int> input) {
    if(input.empty()){
        return 0;
    }
    int res = 1;
    int* M = new int[input.size()];
    M[0] = 1;
    for(int i = 1; i < input.size(); ++i){
        int currMax = 1;
        for(int j = 0; j < i; ++j){
            if(input[j] < input[i]){
                currMax = max(currMax, M[j]+1);
            }
        }
        M[i] = currMax;
        res = max(res, currMax);
    }
    delete[] M;
    return res;
}

/*
int main(){
    int arr[] = {7, 2, 3, 1, 5, 8, 9, 6};
    cout << Longest_Ascending_subarr(arr, 8) << endl;
    return 0;
}*/