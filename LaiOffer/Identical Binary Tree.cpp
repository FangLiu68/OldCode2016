//
//  Identical Binary Tree.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Check if two given binary trees are identical. Identical means the equal valued keys are at the same position in the two binary trees.
 Examples
    5
  /    \
 3        8
 and
    5
  /    \
 3        8
 are identical trees.
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

bool identical_binary_tree(BinaryTreeNode* r1, BinaryTreeNode* r2) {
    // base case
    if(r1==NULL && r2==NULL) return true;
    if(r1==NULL || r2==NULL) return false;
    if(r1->val != r2->val) return false;

    bool left_is_same = identical_binary_tree(r1->left, r2->left);
    bool right_is_same = identical_binary_tree(r1->right, r2->right);
    return left_is_same && right_is_same;
}