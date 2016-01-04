//
//  3Sum Less.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a sorted array A[N],    how many tuples  of  x, y, z such that  x+y+z < result.
    xxxxxxxxxxxxxxxxxxxxxx
    ijj’    k’k       A[j] + A[k]  < target
 for this particular i and j , we find the k     , counter +=  k - j
 when j increments by 1,  k can only move to the left → k can only decrease
 i <= j <= k
 For each i,       y+z     < k - A[i]  →  A[j] + A[k] < result - A[i] = target
 initially,  k = N - 1
 j = i + 1;
	For each j, find the largest k, such that     A[j] + A[k] < target
 enum a[i] ,   y+z < result - A[i]
 enum a[j] = y, find the largest a[k] = z, then counter += k - j;
 a[j] + a[k] < target                       fun 1  k
 a[j ‘]  +  a[k’] < target                  fun 2  k’
  inc      dec
 int 3SumLess(vector<int> A, int target) {
 if (A.size() < 3) {
 return 0;
 }
 int counter = 0;
 for (int i = 0; i < A.size() - 2; i++) {
 k = A.size() - 1;
 for (j = i + 1; j < A.size() - 1; j++) {
 while (A[i] + A[j] + A[k] >= target) {
 k--;
 }
	if (j >= k) {
 break;
 }
 counter += k - j;
 }
 if (A[i] + A[i + 1] + A[i + 2] >= target) {
 break;
 }
 }
 return counter;
 }

 */