//
//  Shuffle Array.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/14/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array of integers (without any duplicates), shuffle the array such that all permutations are equally likely to be generated.

 Assumptions
 The given array is not null
 */

#include <iostream>
using namespace std;

void ShuffleArray(int a[], int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        int idx = rand() % (length - i);
        int temp = a[i];
        a[i] = a[i + idx];
        a[i + idx] = temp;

    }
}
/*
int main(){
    int arr[] = {1,2,3,4,5};
    int len = 5;
    ShuffleArray(arr, len);
    for(int i=0; i<len; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}*/