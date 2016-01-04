//
//  Reconstruct Bianry Tree With pre_in Order.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/18/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// How to reconstruct a binary tree with pre-order and in-order sequences of all nodes.

#include "BinaryTree.h"
#include <iostream>
using namespace std;

/*
 Get the first element from pre-order(=10), and find the index of 10 in in-order sequence.
 Assume its inorder index = mid;
 we divide the whole problem into two parts, inorder's left part = [0, mid], right part = [mid+1, right]
 */