//
//  Check Has Triangle.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/30/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array of integers, determine whether there exists three elements (a,b,c), such that a^2 + b^2 = c^2.
 Example:
 input: arr[] = {3,-1,4,6,5};
 output: True
 <a,b,c> = (3,4,5)
 */

#include "Header.h"

/*
 step1: calculate the square value for the element
 step2: sort the array
 step3: 2 sum for n-2 times at most
 */

bool helper_twoSum(const vector<int>& arr, int value, int right, int left);
bool has_rightTriangle(vector<int> arr){
    if(arr.empty()){
        return false;
    }
    for(int i=0; i<arr.size(); ++i){
        arr[i] = arr[i]*arr[i];
    }
    for(int i=arr.size()-1; i>=0; i--){
        if(helper_twoSum(arr, arr[i], i-1, 0)){
            return true;
        }
    }
    return false;
}

bool helper_twoSum(const vector<int>& arr, int value, int right, int left){
    while(left < right){
        if(arr[left] + arr[right] == value){
            return true;
        }else if(arr[left] + arr[right] < value){
            left++;
        }else{
            right--;
        }
    }
    return false;
}
/*
int main(){
    vector<int> arr = {3,-1,4,6};
    if(has_rightTriangle(arr)){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}*/