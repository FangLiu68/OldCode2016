//
//  array shuffle.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// 	Given an array with integers, move all “0s” to the right-end of the array.

#include "Header.h"

/*
 1 2 0 0 4 0 3 8
 i             j
 */

/*
 挡板的题目:
 1. 要非常明确定义的挡板的意义是什么
    挡板的位置是包含还是不包含? 不包含
    挡板之间的数保证是什么样的? 没有检查过的 不知道是什么数
 2. 每一步, 如何移动挡板
 3. 截止的条件是什么

 */

// 两个挡板，三个区间，相向而行

// 注意：如果传入int arr[]，则实际传入的是指针，在function内部任何对arr的操作都是对指针的操作，都会改变原arr内部的序列
// 而如果传入vector的话，只有传入vector的引用&，才能改变原vector中的序列，否则在function内部任何对vector的操作都只在function内部有效，并不改变原vector的值
void remove_zero_to_right_end_of_arr(int arr[], int len){
    if(arr==NULL || len<=1) return;
    int leftBound = 0; // leftBound的左边所有值都是非零（不包括arr[leftBound]本身）
    int rightBound = len-1; // rightBound的右边所有值都是0
    while(leftBound <= rightBound){
        if(arr[leftBound] == 0)
            swap(arr[leftBound], arr[rightBound--]);
        else
            leftBound++; // 跳出循环后leftBound的左边仍然全部是非零，不包括arr[leftBound]
    }
}

// 比上一种方法稍快一些
int remove_zero_to_right_quicker(int arr[], int len){
    if(arr==NULL || len<=0) return -1;
    int left = 0;
    int right = len-1;
    while(left <= right){
        if(arr[left] != 0){
            left++;
        }else if(arr[right] == 0){
            right--;
        }else{
            swap(arr[left++], arr[right--]);
        }
    }
    return left;
}

// 如果要保持非0元素的相对顺序
int moveKeepOrder(vector<int>& input){
    if(input.empty()) return INT_MIN;
    int slow = 0;
    int fast = 0;
    while(fast < input.size()){
        if(input[fast] != 0){
            input[slow++] = input[fast++];
        }else{
            fast++;
        }
    }
    int res = slow;
    while(slow < input.size()){
        input[slow++] = 0;
    }
    return res; // 返回的res的左边所有数字都是非零（不包括input[res]）
}


/*
int main(){
    vector<int> input = {1, 0, 2, 0, -4};
    cout << moveKeepOrder(input) << endl;
    for(int i=0; i<input.size(); ++i){
        cout << input[i] << " ";
    }return 0;
}
*/