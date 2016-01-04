//
//  Common Elem in 3 Sorted Arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/10/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// print common elements in three sorted array

#include <iostream>
using namespace std;

void print_common_in_three_sorted_arr(int arr1[], int len1, int arr2[], int len2, int arr3[], int len3){
    if(arr1==NULL || arr2==NULL || arr3==NULL){
        return ;
    }
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;
    while(index1<len1 && index2<len2 && index3<len3){
        if(arr1[index1]==arr2[index2] && arr1[index1]==arr3[index3]){
            cout << arr1[index1] << " ";
            index1++, index2++, index3++;
        }else if(arr1[index1]<arr2[index2] && arr1[index1]<arr3[index3]){
            index1++;
        }else if(arr2[index2]<arr1[index1] && arr2[index2]<arr3[index3]){
            index2++;
        }else{
            index3++;
        }
    }
}