//
//  Get Left Subtree Nodes.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/3/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*  How to store how many nodes in each node’s left-subtree?
            4(3)
         /      \
     2(1)         5(0)
    /     \          \
  1(0)   3(0)          6(0)
*/

#include "BinaryTree.h"
#include <iostream>
using namespace std;

/*
 Way of thinking (Tricks)
 1.  What do you expect from your lchild / rchild?
	Total number of nodes in my left subtree (1)
 Total number of nodes in my right subtree (2)
 2.  What do you want to do in the current layer?
	store (1) in current->lChildNum;
 3.  What do you want to report to your parent? (same as Q1 == Q3)
	it is usually the return type of the Recursion function
 */

// 注意，我们向上传递的是包括本身节点在内的，父节点在这一方向上的所有节点
int helper_leftSubtreeNodes(TreeNode2* root){
    if(root == NULL){
        return 0;
    }
    // what do you expect from left and right child
    int left = helper_leftSubtreeNodes(root->left);
    int right = helper_leftSubtreeNodes(root->right);

    // what do you want to do in current level
    root->numLeftElements = left;

    // what do you want to report to your parents
    return left+right+1;
}

int get_leftSubtreeNodes(TreeNode2* root){
    if(root == NULL){
        return 0;
    }
    helper_leftSubtreeNodes(root);
    return root->numLeftElements;
}