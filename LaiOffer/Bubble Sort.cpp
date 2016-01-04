//
//  Bubble Sort.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/6/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//


#include "Header.h"

void bubbleSort(int arr[], int len){
    if(arr == NULL || len <= 0){
        return;
    }

    for(int i=0; i<len-1; ++i){
        for(int j=i+1; j<len; ++j){
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
}

/*
int main(){
    int arr[] = {3,2,5,4,1};
    int len = 5;
    bubbleSort(arr, len);
    for(int i=0; i<5; ++i) cout << arr[i] << " ";
    cout << endl;
    return 0;
}*/