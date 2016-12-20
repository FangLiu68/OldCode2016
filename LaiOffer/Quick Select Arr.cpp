//
//  Quick Select Arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/17/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// quick select -- from Quick Sort
// find the K-th smallest element in array

/*
 QuickSelect - Time Complexity: average O(n), worst O()
 average: T(n) = T(n / 2) + O(n) = O(n)
 n + n/2 + n/4 + n/8 + n/16 + …. = n / (1 - 1/2) = 2n - n/1 * n = 2 * n -1
 worst: T(n) = T(n - 1) + O(n) = O(n * n)
 
 find k-th smallest element, then when this element in sorted sequence its index should be (k-1)
 
 complexity:
 everage O(n), worst case O(n^2)
 -----------k-----------
 之前每次取pivot都在K之前，然后每次取pivot都在k之后，那么就一共取了N次pivot，而每次取了pivot之后排序都是需要O(N)，所以最差情况是O(N^2)
 */

#include <iostream>
using namespace std;

int helper_partition_QS(int arr[], int left, int right){
    int pivotPosition = left + (right-left)/2;
    int pivot = arr[pivotPosition];
    swap(arr[pivotPosition], arr[right]);
    int l = left;
    int r = right-1;
    while(l <= r){
        if(arr[l] < pivot){
            l++;
        }else if(arr[r] > pivot){
            r--;
        }else{
            swap(arr[l++], arr[r--]);
        }
    }
    swap(arr[l], arr[right]);
    return l; // l 所指向的元素放在他本来应该存在的位置上
}

int helper_sort(int arr[], int left, int right, int k){
    if(left > right){ // left==right时不能返回-1，因为如果只有一个元素的话left肯定等于right
        return -1;
    }
    int correct_index = helper_partition_QS(arr, left, right);
    if(correct_index == k-1){
        return arr[correct_index];
    }else if(k-1 > correct_index){
        return helper_sort(arr, correct_index+1, right, k);
    }else{
        return helper_sort(arr, left, correct_index-1, k);
    }
}

int quickSelect(int arr[], int len, int k){
    if(arr == NULL){
        return INT_MIN;
    }
    int left = 0;
    int right = len-1;
    return helper_sort(arr, left, right, k);
}

/*
int main(){
    int arr[] = {12, 3, 1, 9, 20, 5, 25};
    int len = sizeof(arr) / sizeof(int);
    cout << quickSelect(arr, len, 6) << endl;
    return 0;
}*/