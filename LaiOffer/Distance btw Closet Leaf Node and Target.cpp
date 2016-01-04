//
//  Distance btw Closet Leaf Node and Target.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/13/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a Binary Tree and a key ‘k’, find distance of the closest leaf from ‘k’.
 Examples:
        R
    /        \
  D           A
            /    \
           B       C = cur
                /    \
                E     F
              /         \
              G         H
            /  \        /
            I   J      K

 Closest leaf to 'H' is 'K', so distance is 1 for 'H'
 Closest leaf to 'C' is 'B', so distance is 2 for 'C'

 Solution:
 Case1: the shortest path from C to the leaf nodes belong to the subtree rooted at C
 Case2: the shortest path from C to one of its ancestors and then go to the other subtree of the ancestor that does not contain C.
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

/*
 还有另一种解法
 假设要求是节点C，在C以下的所有节点，从底往上，越靠近C距离越近(每次减一)；而在C往上的所有节点，每次离C越远，加1
 这是人字形和直上直下的结合。
 */