//
//  Is Exist i j k When a[i]<a[j]<a[k].cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/3/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given an array of integers. exists i, j, k? such that i < j < k && array[i] < array[j] < array[k].
 
 take index j as pivot
 find if there is any index i on the left side of j such that array[i] < array[j],
 find if there is any index k on the right side of j such that array[j] < array[k],
 →
 
 for each index j, min element on the left side + max element on the right side.
 
 Space Optimization: O(n) → O(1)
 
 find a increasing subsequence that size == 3.
 Longest Increasing Subsequence.
 
 {4, 2, 8, 3, 5, 9, 10, 2, 6, 8, ….}
 
 sol[i] = for all the increasing subsequence with length i, what is the minimum ending element.
 
 sol[1] = 2
 sol[2] = 3
 sol[3] = 5
 
 only need to maintain sol[1] and sol[2].
 


 */