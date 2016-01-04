//
//  K-th Closest.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/13/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given three arrays with numbers in ascending order. Pull one number from each array to form a coordinate <x,y,z> in a 3D space. (1) How to find the coordinates of the points that is k-th closest to <0,0,0>?

 A1[m] = { 1, 3, 5, 7, 9, ,... }    -> X
 i
 A2[n] = {  2, 3, 4, 6, 8, ….}   -> Y
 j
 A3[L] = { 1, 3, 4, 5, 6, ...}    -> Z
 k
 */

/*
 1.Initial state:  <0, 0, 0>
 2.Expansion/Generation rule:   <i, j, k > → <i+1, j k>  <i, j+1, k> <i, j , k+1>
 3.Termination condition:  when the k-th state is popped out of the p_queue, then terminate and return the state.

 4.Deduplication (for the same state when generated)
 we need to be careful.  Maintain a hash_map to store all the states that have been generated. (Avoid inserting the same state into the p_queue for the 2nd time.)


 */