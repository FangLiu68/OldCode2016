//
//  Interleave Positive Negative Num.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/30/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Interleaving Positive and Negative Numbers
 Given an int array, how do you interleave the positive and negative numbers?
 Example,
 {1, 2, -2, -3, 4, -1, 3} → {1, -2, 2, -3, 3, -1, 4}
 */

#include <iostream>
using namespace std;

void interleave(int arr[], int len){
    if (arr == NULL || len == 0){
        return;
    }
    int left = 0;
    int right = 1;
    while(left < len && right < len){ // terminate condition
        if (arr[left] > 0) {
            left = left + 2;
        } else if (arr[right] < 0) {
            right = right + 2;
        } else {
            swap(arr[left], arr[right]);
            right = right + 2;
            left = left + 2;
        }
    }
}
/*
int main(){
    int arr[] = {1, 2, -2, -3, 4};
    int len = sizeof(arr) / sizeof(int);
    interleave(arr, len);
    for(int i=0; i<len; ++i){
        cout << arr[i] << ", ";
    }return 0;
}*/