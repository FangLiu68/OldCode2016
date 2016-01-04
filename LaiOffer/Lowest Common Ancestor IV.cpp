//
//  Lowest Common Ancestor IV.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/3/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given two nodes in a binary tree, find their lowest common ancestor (the given two nodes are not guaranteed to be in the binary tree).
 Return null If any of the nodes is not in the tree.
 Assumptions
 There is no parent pointer for the nodes in the binary tree
 The given two nodes are not guaranteed to be in the binary tree
 Examples
 5
 /   \
 9     12
 /  \      \
 2    3      14
 The lowest common ancestor of 2 and 14 is 5
 The lowest common ancestor of 2 and 9 is 9
 The lowest common ancestor of 2 and 8 is null (8 is not in the tree)
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

// 需要先check node是否在树里

bool check(BinaryTreeNode* root, BinaryTreeNode* node);
BinaryTreeNode* helper(BinaryTreeNode* root, BinaryTreeNode* one, BinaryTreeNode* two);
BinaryTreeNode* solve(BinaryTreeNode* root, BinaryTreeNode* one, BinaryTreeNode* two) {
    if(!check(root, one) || !check(root, two)) return NULL;
    return helper(root, one, two);
}

BinaryTreeNode* helper(BinaryTreeNode* root, BinaryTreeNode* one, BinaryTreeNode* two){
    if(root==NULL) return NULL;
    if(root==one || root==two) return root;
    BinaryTreeNode* left = helper(root->left, one, two);
    BinaryTreeNode* right = helper(root->right, one, two);
    if(left && right) return root;
    else return left?left:right;
}

bool check(BinaryTreeNode* root, BinaryTreeNode* node){
    if(root==NULL) return false;
    if(root==node) return true;
    return check(root->left, node) || check(root->right, node);
}