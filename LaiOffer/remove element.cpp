//
//  remove element.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array and a value, remove all instances of that value in place and return the new length.
 The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */
#include <vector>
#include <iostream>
using namespace std;

// if the order of nodes could be changed. O(logN)
int removeElement(vector<int>& nums, int val) {
    if(nums.empty()) return 0;
    
    int left = 0;
    int right = nums.size() - 1;
    
    while(left <= right){
        if(nums[left] != val){
            left++;
        }else if(nums[right] == val){
            right--;
        }else{
            nums[left] = nums[right];
            left++, right--;
        }
    }
    
    return left;
}


// 左右两个挡板 O(N)
// cur的左边（不包括A[cur]）都是符合条件的结果。
// runner的右边（不包括A[runner]）都是还没有探索到的地方
int removeElement(int A[], int n, int elem) {
    if(A==NULL || n<=0){
        return 0;
    }
    int index = 0;
    int runner = 0;
    while(runner < n){
        if(A[runner] == elem){
            runner++;
        }else{
            A[index++] = A[runner++];
        }
    }
    return index;
}

/* 跟上面的写法一样，感觉上面写得更清楚一些
int remove_element(int arr[], int len, int target){
    if(arr==NULL || len<=0) return -1;
    int leftBound = 0;
    for(int i=0; i<len; i++){
        if(arr[i] != target)
            arr[leftBound++] = arr[i];
    }
    return leftBound;
}*/
/*
int main(){
    int arr[] = {2, 4, 3, 3, 2};
    int res = remove_element(arr, 5, 2);
    for(int i=0; i<5; i++) cout << arr[i] << " ";
    cout << endl;
    cout << res << endl;
    return 0;
}*/