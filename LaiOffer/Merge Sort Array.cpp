//
//  merge sort.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/3/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Merge sort     Time= O(nlogn)    Space = O(n)
 
 a[n] = 1,3,5,7,9,8,6,4,2,0
 1,3,5,7,9, 8,6,4,2,0     a[10] -> a[0]...a[4]  MERGE a[5]...a[9]
              /                    \
	     n/2       13579                86420       O(1) <O(n)
                           /       \                       /      \
              n/4  135        79              864     20                       O(2)<O(n)
                     /   \                             /   \
            n/8 13   →   5        79        86   4     2 0       O( 4)
	   /           \
              1  --> 3   5        79            86   4     20    this level time complexity == O(n)
 ====================================================================
                 13   5        79             86   4     20    this level time complexity == O(n)
                     \  /                           \  /
                     135     79                   468     02   this level time complexity == O(n)
                           \    /                           \    /
                            13579                     02468    this level time complexity == O(n)
                                     \                   /
                                       0123456789
 O(log(n)) layers, for each layer, the maximum elements is O(n/2)
 Space complexity:  O(n)
 // main function that calls merge_sort
 // left:  the left index of the sub vector
 // right: the right index of the sub vector                     0                                   9
 00 vector<int> mergesort(vector<int>& a, int left//index, int right) {
 01 vector<int> solution;              // store the final solution
 02 if (left > right) return solution; // sanity check
 03 if (left == right) {               // base case
 04 solution.push_back(array[left]);
 05 return solution;
 06 }
 07 int mid = left + (right - left) / 2; // mid is == 4
 08 vector<int> solu_left = mergeSort(a, left, mid); //left:0 mid:4
 breaking point….
 09 vector<int> solu_right = mergeSort(a, mid + 1, right);//5   9
 10 solution = combine(solu_left=1, solu_right=3);
 11 return solution;
 12 }
 */

#include "Header.h"


// low和high分别代表初始位置和终点位置，函数里面如果有需要初始化位置的地方都要用low和high来代替，这样merge()被调用的时候才不会有错误
// [low, mid], [mid+1, high]
void merge(int arr[], int helper[], int low, int mid, int high){
    if(arr==NULL || helper==NULL)	return;

    // copy both halves into helper array
    for(int i = low; i <= high; i++){ // 注意index取值 [low, high]
        helper[i] = arr[i];
    }

    int cur_left = low;
    int cur_right = mid+1;
    int index = low; // 注意这里cur的初始位置应该是low而不是0.

    while(cur_left <= mid && cur_right <= high){
        if(helper[cur_left] <= helper[cur_right])
            arr[index++] = helper[cur_left++];
        else
            arr[index++] = helper[cur_right++];
    }

    // 当右边数组已经用完，左边还有剩下的时候，直接把左边剩下的所有元素copy到结果数组中
    // 如果左边已经用完，而右边数组还有剩下，那么我们不用管，因为右边本来就在结果数组的最右边位置上。
    int remaining = mid - cur_left;
    for(int i = 0; i <= remaining; i++) // here should be i<=remaining
        arr[index+i] = helper[cur_left+i];
}

// 先分成两半，recursion; 然后再对两个有序的两半进行Merge
void mergeSort(int arr[], int helper[], int low, int high){
    if(low < high){
        int mid = low+(high-low)/2;
        mergeSort(arr, helper, low, mid);	// sort left half
        mergeSort(arr, helper, mid+1, high);// sort right half
        merge(arr, helper, low, mid, high); // merge them
    }
}

void mergeSort(int arr[], int len){
    if(arr==NULL || len<0)	return;
    int* helper = new int[len]; // helper[]在这里就已经建成了
    mergeSort(arr, helper, 0, len-1);
    delete[] helper;
}

/* 如果返回vector<int>，则中间需要的helper function里传入的是vector<int> &a, 但最终传入的vector<int> a的数值顺序不变，
 vector<int> solve(vector<int> a) {
    if(a.empty()) return vector<int>();
    int* helper = new int[a.size()];
    mergeSort(a, helper, 0, a.size()-1);
    return vector<int>(a.begin(), a.end());
 }

 void mergeSort(vector<int> &a, int helper[], int low, int high);

 void merge(vector<int> &a, int helper[], int low, int mid, int high);
 */


/*
 int main() {
	// your code goes here
     int arr[5] = {8,4,5,3,1};
     mergeSort(arr,5);
	for(int i=0; i<5; i++) cout << arr[i] << " ";
	cout << endl;
	return 0;
 }*/