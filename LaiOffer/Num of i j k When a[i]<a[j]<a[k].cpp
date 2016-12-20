//
//  Num of i j k When a[i]<a[j]<a[k].cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/3/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 3.2. Given an array of integers. how many (i, j, k) triples? such that i < j < k && array[i] < array[j] < array[k]
 
 Naive Solution:
 a[i] = number of elements < array[i] on the left side.  O(n^2) → O(nlogn)
 b[i] = number of element > array[i] on the right side. O(n^2) → O(nlogn)
 
 */