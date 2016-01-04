//
//  rainbow sort.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include "Header.h"

// Rainbow sort (abcccabbcbbacaa → aaaaa bbbbb ccccc)
// three bounds: 三个挡板，四个区间，相同+相向而行
// 1. the left side of boundZero is 0.
// 2. the right side of boundTwo is 2.
// 3. the part between boundZero and boundOne is 1.
// 4. the part between boundOne and boundTwo is to be discovered.

/*
 aaaaaa bbbbbb XXXXXXXXC ccccccc
  i            j     unknown  k

 initialization:
 i = 0;      all letters to the left-hand side of i are all “a”s
 j = 0;   (j is actually the current index)    all letters in  [i  j)  are all “b”s ,
 k = n-1  (all letters to the right-hand side of k are all “c”s).
 unknown area is [j...k]
 */

/*
 [0, bound_0)       0
 [bound_0, bound_1) 1
 (bound_2, end]     2
 bound_0的左边（不包括arr[bound_0]都是0）
 bound_0到bound_1之间（包括arr[bound_0]不包括arr[bound_1]都是1）
 bound_2的右边（不包括arr[bound_2]都是2）
 所以，任何bound的左边都是你想放的数的值，但注意这并不包括arr[bound]本身
 */
void rainbow_sort(int arr[], int len){
    if(arr==NULL || len<=0) return ;
    int bound_0 = 0;
    int bound_1 = 0;
    int bound_2 = len-1;
    while(bound_1 <= bound_2){
        // 包括arr[bound_0]在内的[bound_0, bound_1)之间都是1，所以如果arr[bound_1]==0, 和arr[bound_0]swap之后，bound_1必须+1
        // bound_0和bound_1初始值相同都从0开始，bound_1先走，遇到的任何2都替换到bound_2右边了，遇到的任何
        if(arr[bound_1] == 0)
            swap(arr[bound_0++], arr[bound_1++]);
        else if(arr[bound_1] == 1)
            bound_1++;
        else
            swap(arr[bound_1], arr[bound_2--]);
    }
}
/*
int main(){
    int arr[] = {2, 1, 1, 2, 0, 0, 1};
    int len = 7;
    rainbow_sort(arr, len);
    for(int i=0; i<len; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}*/