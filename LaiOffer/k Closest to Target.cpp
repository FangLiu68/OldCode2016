//
//  k Closest to Target.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/20/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a binary search tree and a target number, find k nodes that have the value closest to target number.
                8
         /           \
        4             15
     /    \          /     \
    1       7       9        20
          /         \      /   \
          5         12    17  25
 
 k = 4; target = 10
 res = 8,9,12,15
 */

#include "Header.h"

/*
 Method 1: generate top k problem. O(nlogk)
 Method 2: 在node structure里加入parent指针，借鉴sorted array找k closest to target的方法
            sorted array → k closest to target,
                    closest to target, (binary search) O(logn)
                    two pointers, merge O(k)
            O(logn + k)

              l
                    r
 [1, 4, 5, 7, 8, 9, 12, 15, 17, 20, 25]
 binary search tree → k closest to target,
        closest to target, (binary search) O(logn)
        // two pointers, merge O(k) → inorder next node.

 */

// Method 1:
