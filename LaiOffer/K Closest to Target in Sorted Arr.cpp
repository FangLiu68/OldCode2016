//
//  K Closest to Target in Sorted Arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/10/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Find k closest to target in a sorted arr
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 1. find the closest element in the sorted arr
 2. left, right. move the closest one among these two. O(1) per move
    O(logn + k)
 
                8
         /           \
        4             15
     /     \         /     \
    1       7       9       20
           /      /  \      /   \
           5   8.5 11.2     17  25

 TreeNode l = 9, find the largest smaller node to l ⇒ find the previous node in its inorder traversal.
 TreeNode r = 11.2, find the smallest larger node to r ⇒ find the next node in its inorder traversal.

 */