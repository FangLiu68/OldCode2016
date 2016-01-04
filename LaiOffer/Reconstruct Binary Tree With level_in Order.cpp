//
//  Reconstruct Binary Tree With level_in Order.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/18/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Given inorder and level-order traversals of a binary tree (you can assume all unique numbers in the tree), construct the binary tree.

#include "BinaryTree.h"
#include <iostream>
using namespace std;

/*
 Method :   hash in-order sequence in each recursion function.
 Step1: for the 1st element in level[].  pick it up, and look for its index  x in inorder[].
        form left tree  by using inorder [0.. x-1]    [x+1,...n-1]
 Step2: iterate over the level[].  divide it into two sub-arrays,
        when scanning an element level[i], if level[i] is in inorder [0.. x-1], then insert it into left part
        Else, right part
 */