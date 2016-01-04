//
//  Two Nums with Same Diff to Target.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a sorted array, find a pair of elements whose difference is identical to a target number.

 1, 3, 4, 6, 7, 8               4
         i
     j
 for index in [2, j-1], we must have A[index] - A[i] < target
   -3
 1 5 7 8 8       target == 0
  i
    j
 public List<Integer> getPair(int[] a, int target) {
 List<Integer> res = new ArrayList<Integer>();
 if(a == null || a.length <= 1)
 res;
 int i = 0;
 int j = 1;
 while(i <= j && j < a.length)
 {
 if(a[j] - a[i] == target)
 {
 if(i != j)
 {
	res.add(a[i]);
	res.add(a[j]);
	return res;
 }
 else
 j++;
 }
 else if(a[j] - a[i] < target)
 j++;
 else
 i++;
 }
 return res;
 }

 */