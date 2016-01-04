//
//  Has Subarr Sums to Target.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
  Given an array with all positive integers, determine whether there exists a contiguous sub-array in the array, which sums to a target number x.
 boolean isExist (int[] num, int target, int start) {
 for (int i = start; i < num.length; i++) {
 if (num[i] == taraget) {
 return true;
 } else if (num[i] < target) {
 isExist(num, target - num[i]      ), i + 1);
 } else {
 isExist(num, target, i + 1);
 }
 }
 }
 if the target = 12
 index = 0 1 2 3 4 5 6 7 8
            1 3 5 2 5 7 …
                  i      j
              slow  fast
   for (int i = 0; i < num.length; i ++ ) {
 sum = num[i];
 while (j < num.length) {
 if (sum == target) {
 return true;
 } else if (sum < target) {
 sum = sum + num[j++];
 } else  {
 sum = sum - num[i;
 }
 }
   }
  return false;
 }
 public boolean get (int[] a, int target)  {
 if (a == null || a.length == 0)
 return false;
 int sum = 0;
 int start = 0;
 for (int i = 0; i < a.length; i++)   // i is the fast index
 {
 sum += a[i];
 while (sum > target)
 {
 sum -= a[start];    // start is the slow index
 start ++;
 }
 if (sum == target)
 return true;
 }
 return false;
 }
 

 */