//
//  Remove Dup in Arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/20/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;

/*
 Given a sorted integer array, remove duplicate elements. For each group of elements with the same value keep only one of them. Do this in-place, using the left side of the original array and maintain the relative order of the elements of the array. Return the length of the final array.

 Assumptions

 The array is not null
 Examples

 {1, 2, 2, 3, 3, 3} → {1, 2, 3}, return 3
 */

/*
 隔板题：
 基本思想：用两个变量，一个变量记录当前指针位置，一个变量记录隔板位置。
 性质：隔板左边是处理好的元素，当前指针右边是未处理的元素，隔板和当前指针之间的区域是无用的元素。
      每次只要分析当前元素性质是否要加入或者移动隔板就可以了。
 */

// 两个挡板。cur左边（不包括cur）都是符合条件的, runner右边（不包括runner）都是还没有探索过的
vector<int> remove_dup_I(vector<int>& input) {
    if(input.empty()) return vector<int>();
    int cur = 1;
    int runner = 1;
    while(runner < input.size()){
        if(input[cur-1] == input[runner]){
            runner++;
        }else{
            input[cur++] = input[runner++];
        }
    }
    // myvector.erase (myvector.begin()+5);  erase the 6th element
    input.erase(input.begin()+cur, input.end());
    return input;
}

// same as above
int remove_dup_in_arr_I(vector<int>& input) {
    if(input.empty()) return 0;
    int cur = 0;
    int runner = 0;
    while(runner < input.size()){
        if(input[cur] == input[runner]){
            runner++;
        }else{
            input[++cur] = input[runner++];
        }
    }
    input.erase(input.begin()+cur+1, input.end());
    return cur+1;
}


int solve_remove(vector<int> arr){
    if(arr.empty()){
        return INT_MIN;
    }
    int cur = 0;
    int runner = 0;
    while(runner < arr.size()){
        if(arr[cur] == arr[runner]){
            runner++;
        }else{
            arr[++cur] = arr[runner++];
        }
    }
    arr.erase(arr.begin()+cur+1, arr.end());
    return cur+1;
}
