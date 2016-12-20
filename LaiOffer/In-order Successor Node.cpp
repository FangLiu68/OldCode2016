//
//  InOrder Successor Node.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/17/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Given an arbitrary node in binary tree, what is the in-order successor node?

#include "BinaryTree.h"
#include <iostream>
using namespace std;

/*
 1. do you need to look at cur’s left subtree? - No. left subtree has already been traversed in in-order before cur node itself.
 2. if cur has right subtree:
 next = smallest node in cur’s right subtree.
 3. if cur does not have right subtree:
	while cur is not its parent’s left child:
 cur = cur’s parent
	next = cur’s parent
 
 is nextInOrder() O(1) time complexity? - amortized time complexity is O(1)
 amortize on single operation:
 call single time, it could be expensive.
 bunch multiple calls together and calculate the mean time complexity.
 each edge traversed once and only once.
 number of edges = number of nodes - 1

 */

/*
 inorder :
 does not need to consider cur.left
 consider cur.right ?
 cur.right != null → the left most node in cur.right
 cur.right == null ?

 */

TreeNode1* firstNode(TreeNode1* root); // find left most node in the right sub tree
TreeNode1* nextInOrder(TreeNode1* cur){
    if(cur==NULL) return NULL;
    
    // case 1: current has right subtree
    if(cur->right){
        return firstNode(cur->right);
    }
    
    // case 2: current doesn't have right subtree, then we need to track back to its parents
    while(cur->parent && cur==cur->parent->right){
        cur = cur->parent;
    }
    return cur->parent;
}

TreeNode1* firstNode(TreeNode1* root){
    if(root == NULL) return NULL;
    TreeNode1* cur = root->right;
    while(cur){
        cur = cur->left;
    }
    return cur;
}