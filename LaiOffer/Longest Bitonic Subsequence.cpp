//
//  Longest Bitonic Subsequence.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Longest Bitonic Subsequence.
 Given an array A[0 … n-1]  with all positive integers,  a sub-sequence of A[] is called Bitonic if it is first in an ascending order, then in a descending order. How can you find the length of the longest bitonic subsequence.
 Corner case: A subsequence, sorted in increasing order is considered Bitonic with the decreasing part as empty. Similarly, decreasing order sequence is considered Bitonic with the increasing part as empty.
 Examples:   Input arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
                     Output: 6 (= 1, 2, 10, 4, 2, 1)
 public int longest(int[] array) {
 int result=0;
 int[] left=new int[arr.length];
 Arrays.fill(left,1);
 int[] right=new int[arr.length];
 Arrays.fill(right,1);
 for (int i=1; i<arr.length; i++) {
 for(int j=0; j<i; j++) {
 if(array[j]<array[i]) {
 left[i]=Math.max(left[i],left[j]+1);
 }
 }
 for (int i=arr.length-2; i>=0; i--) {
 for (int j=ar.length-1; j>i; j--) {
 if (array[j]<array[i]) {
 right[i]=Math.max(right[i],right[j]+1);
 for (int i=0; i<arr.length; i++) {
 left[i]=left[i]+right[i]-1;
 result=Math.max(left[i],result);
 }
 return result;
 }

 */