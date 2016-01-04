//
//  Partition Arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/30/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Partition Array

 Given an int array of integers and an int k, Partition\ the array:
 All the elements >= k are on the right side of all the elements < k
 Return the partitioning Index.

 Example: int[] array = {1, 3, 2, 4, 1} →  {1, 1, 2, 3, 4} for k = 2, return 2.
 */

#include "Header.h"

int partition_arr(int arr[], int len, int k){
    if(arr==NULL || len<=0){
        return -1;
    }
    int left = 0;
    int right = len-1;
    while(left <= right){
        if(arr[left] < k){
            left++;
        }else if(arr[right] >= k){
            right--;
        }else{
            swap(arr[left], arr[right]);
        }
    }
    return left; // left左边 不包括arr[left]都是符合条件的(比k小的数)
}



/*
int main(){
    int arr[] = {1,8,3,9,5,6,6};
    int k = 6;
    cout << partition_arr(arr, 7, k) << endl;
    for(int i=0; i<7; ++i) cout << arr[i] << " "; cout << endl;
    return 0;
}*/