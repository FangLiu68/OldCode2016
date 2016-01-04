//
//  Find K-th Smallest Elem.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given two sorted arrays of integers, find the Kth smallest number.
 Assumptions
 The two given arrays are not null and at least one of them is not empty
 K >= 1, K <= total lengths of the two sorted arrays

 Examples
 A = {1, 4, 6}, B = {2, 3}, the 3rd smallest number is 3.
 A = {1, 2, 3, 4}, B = {}, the 2nd smallest number is 2.
 */
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/* O(logK)
 核心思想：把A[N]和前B[M]的各自前K/2比较，每次删除K/2
          A[K/2-1]和B[K/2-1]谁小就删除谁的前K/2
 */

// How to find the kth smallest element from two sorted arrays.
// a_left is the A[]’s left border to consider from
// b_left is the B[]’s left border to consider from
int helper_findKthSmall(vector<int>& a, int a_start, vector<int>& b, int b_start, int k) {
    if (k == 1)
        return min(a[a_start], b[b_start]);  // base case 1
    if(a_start >= a.size())
        return b[b_start + k - 1];   // base case2: if nothing left in a;
    if(b_start >= b.size())
        return a[a_start + k - 1];   // base case3: if nothing left in b;

    // Since index is from 0, so the k/2-the element should be = left +k/2 - 1
    // why is correct? if a.size too small, then remove elements from b first.
    int a_half_kth = a_start + k/2 - 1 < a.size() ? a[a_start + k/2 - 1] : INT_MAX;
    int b_half_kth = b_start + k/2 - 1 < b.size() ? b[b_start + k/2 - 1] : INT_MAX;

    if (a_half_kth < b_half_kth) {
        return helper_findKthSmall(a, a_start + k/2, b, b_start, k - k/2);
    } else {
        return helper_findKthSmall(a, a_start, b, b_start + k/2, k - k/2);
    }
}

int kth(vector<int> a, vector<int> b, int k) {
    if(k > a.size() + b.size()){
        return INT_MIN;
    }
    if(a.empty()){
        return b[k-1];
    }else if(b.empty()){
        return a[k-1];
    }
    return helper_findKthSmall(a, 0, b, 0, k);
}

//=========================

int findKthSmall(int a[], int lena, int a_left, int b[], int lenb, int b_left, int k) {
    if (k == 1)
        return min(a[a_left], b[b_left]);  // base case 1
    if(a_left >= lena)
        return b[b_left + k - 1];   // base case2: if nothing left in a;
    if(b_left >= lenb)
        return a[a_left + k - 1];   // base case3: if nothing left in b;

    // Since index is from 0, so the k/2-the element should be = left +k/2 - 1
    // why is correct? if a.size too small, then remove elements from b first.
    int a_half_kth = a_left + k/2 - 1 < lena ? a[a_left + k/2 - 1] : INT_MAX;
    int b_half_kth = b_left + k/2 - 1 < lenb ? b[b_left + k/2 - 1] : INT_MAX;

    if (a_half_kth < b_half_kth) {
        return findKthSmall(a, lena-k/2, a_left + k/2, b, lenb, b_left, k - k/2);
    } else {
        return findKthSmall(a, lena, a_left, b, lenb-k/2, b_left + k/2, k - k/2);
    }
}


//===========================
// use extra space to merge two sorted array. O(m+n) runtime, O(m+n) space
int find_kth_smallest1(int arr1[], int len1, int arr2[], int len2, int k){
    if(arr1==NULL || arr2==NULL || k>len1+len2) return INT_MIN;
    if(len1 == 0) return arr2[k-1];
    else if(len2 == 0) return arr1[k-1];

    int* tmp = new int[len1+len2];
    int index1 = 0;
    int index2 = 0;
    int index = 0;

    while(index1 < len1 && index2 < len2)
        tmp[index++] = (arr1[index1] < arr2[index2])? arr1[index1++]:arr2[index2++];

    while(index1 < len1)    tmp[index++] = arr1[index1++];
    while(index2 < len2)    tmp[index++] = arr2[index2++];
    int res = tmp[k-1];

    delete[] tmp;
    return res;
}







// 下面的方法不好理解  看上面的  ===================================
// use two pointers. O(K) runtime, O(1) space
int find_kth_smallest2_iter(int A[], int lenA, int B[], int lenB, int k) {
    int indexA = 0, indexB = 0;
    if (lenA + lenB < k) return INT_MIN;

    while (true) {
        if (indexA < lenA) {
            while (indexB == lenB || A[indexA] <= B[indexB]) {
                indexA++;
                if (indexA + indexB == k) return A[indexA+1];
            }
        }
        if (indexB < lenB) {
            while (indexA == lenA || A[indexA] >= B[indexB]){
                indexB++;
                if (indexA + indexB == k) return B[indexB+1];
            }
        }
    }
}

int find_kth_smallest2_rec(int A[], int lenA, int B[], int lenB, int k){
    if(k==0) return A[0] > B[0]? B[0]:A[0];
    int* a = A;
    int* b = B;
    if(A[0] < B[0])
        return find_kth_smallest2_rec(a+1, lenA-1, B, lenB, k-1);
    else
        return find_kth_smallest2_rec(a, lenA, b++, lenB-1, k-1);
}



/*
int main(){
    int arr1[] = {3,5,8,12,18};
    int arr2[] = {2,6};
    int len1 = 5;
    int len2 = 2;
    int k = 5;
    int res = findKthSmall(arr1, len1, 0, arr2, len2, 0, k);
    cout << res << endl;
    return 0;
}*/