//
//  K-th Smallest Num in Function.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/13/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// How to find the k-th smallest number in the f(x, y, z) = 3^x * 5^y * 7^z (int x>0, y>0, z>0)

/*
 1.Initial state  <x=1, y=1, z=1>
 2.Expansion/Generation rule:   <i, j, k > → <i+1, j k>  <i, j+1, k> <i, j , k+1>
 3.Termination condition:  when the k-th state is popped out of the p_queue, then terminate and return the state.

 4.Deduplication (for the same state when generated)
 we need to be careful.  Maintain a hash_map to store all the states that have been generated. (Avoid inserting the same state into the p_queue for the 2nd time.)
 
 */