//
//  selection sort.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/3/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array of integers, sort the elements in the array in ascending order. The selection sort algorithm should be used to solve this problem.

 Examples
 {1} is sorted to {1}
 {1, 2, 3} is sorted to {1, 2, 3}
 {3, 2, 1} is sorted to {1, 2, 3}
 {4, 2, -3, 6, 1} is sorted to {-3, 1, 2, 4, 6}
 Corner Cases
 What if the given array is null? In this case, we do not need to do anything.
 What if the given array is of length zero? In this case, we do not need to do anything
 */

#include "Header.h"

// O(N^2) runtime, O(1) space
void selectionSort(int arr[], int len){
    if(arr == NULL || len <= 0){
        return;
    }

    for(int i = 0; i < len-1; ++i){
        int min_index = i;

        for(int j = i+1; j < len; ++j){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }

        swap(arr[i], arr[min_index]);
    }
}

// 传入&a,则改变原vector序列
void selection_sort2(vector<int>& a) {
    if(a.size()<=1) return;
    int global;
    for(int i=0; i<a.size(); i++){
        global = i;
        for(int j=i+1; j<a.size(); j++){
            if(a[j] < a[global])
                global = j;
        }
        swap(a[i], a[global]);
    }
}

// 传入a，则在此function内部改变a的序列，但结束function后a仍旧不变，是未排序过的
vector<int> selection_sort3(vector<int> a) {
    if(a.empty()) return vector<int>();
    int global;
    for(int i=0; i<a.size()-1; i++){
        global = i;
        for(int j = i+1; j < a.size(); j++){
            if(a[j] < a[global]){
                global = j;
            }
        }
        swap(a[i], a[global]);
    }
    return vector<int>(a.begin(), a.end());
}

/*
int main(){
    int arr[] = {3, 5, -9, 2, 1, 8};
    selectionSort(arr, 6);
    for(int i=0; i<6; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
*/