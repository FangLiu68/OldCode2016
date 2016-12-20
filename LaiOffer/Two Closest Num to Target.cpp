//
//  2 Closest Num to Target.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/10/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Find the two closest node to target
                 8
            /           \
           4             15
        /     \         /     \
        1       7     9        20
               /     /  \      /   \
              5   8.5  11.2    17  25
 Target = 10.
 c = 9.
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

/*
 1. find the closest node to target, as TreeNode c
 2. the 2nd closest node is either:
    largest smaller than c
    smallest larger than c
    assuming balanced, O(logn) + O(logn) + O(logn) = O(logn)
 */