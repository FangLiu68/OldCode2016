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
 inorder :
 does not need to consider cur.left
 consider cur.right ?
 cur.right != null → the left most node in cur.right
 cur.right == null ?

 */

TreeNode1* firstNode(TreeNode1* root); // find left most node in the right sub tree
TreeNode1* nextInOrder(TreeNode1* cur){
    if(cur==NULL) return NULL;
    if(cur->right){
        return firstNode(cur->right);
    }
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