//
//  Inversion Pair.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/25/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include <iostream>
using namespace std;

// low和high分别代表初始位置和终点位置，函数里面如果有需要初始化位置的地方都要用low和high来代替，这样merge()被调用的时候才不会有错误
int helper_merge(int arr[], int helper[], int low, int mid, int high){
    if(arr==NULL || helper==NULL)	return 0;
    // copy both halves into helper array
    for(int i=low; i<=high; i++)	helper[i] = arr[i];
    int helperLeft = low;
    int helperRight = mid+1;
    int cur = low; // 注意这里cur的初始位置应该是low而不是0.

    int inversion_pair = 0;

    while(helperLeft<=mid && helperRight<=high){
        if(helper[helperLeft]<=helper[helperRight])
            arr[cur++] = helper[helperLeft++];
        else{
            arr[cur++] = helper[helperRight++];

            inversion_pair = inversion_pair+(mid-helperLeft+1);
        }
    }
    // 当右边数组已经用完，左边还有剩下的时候，直接把左边剩下的所有元素copy到结果数组中
    // 如果左边已经用完，而右边数组还有剩下，那么我们不用管，因为右边本来就在结果数组的最右边位置上。
    /*int remaining = mid-helperLeft;
    for(int i=0; i<=remaining; i++) // here should be i<=remaining
        arr[cur+i] = helper[helperLeft+i];*/
    return inversion_pair;
}

// 先分成两半，recursion; 然后再对两个有序的两半进行Merge
int recursion(int arr[], int helper[], int low, int high){
    if(low < high){
        int mid = low+(high-low)/2;
        int left = recursion(arr, helper, low, mid);	// sort left half
        int right = recursion(arr, helper, mid+1, high);// sort right half
        int cross = helper_merge(arr, helper, low, mid, high); // merge them
        return left + right + cross;
    }
    else return 0;
}

int get_inversion(int arr[], int len){
    if(arr==NULL || len<0)	return 0 ;
    int* helper = new int[len]; // helper[]在这里就已经建成了
    return recursion(arr, helper, 0, len-1);
}
/*
int main(){
    int arr[] = {3,2,1,4};
    int res = get_inversion(arr, 4);
    cout << res << endl;
    return 0;
}*/