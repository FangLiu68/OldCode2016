//
//  Heapify Complete Binary Tree.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 heapify a complete binary tree

            10
        /       \
       4         8
    /     \     /    \
   5      2    3     7
  /   \
 1     6

 */

#include "BinaryTree.h"
#include <vector>
#include <iostream>
using namespace std;

void heapify_completeBT(BinaryTreeNode* root){
    if(root->left==NULL && root->right==NULL){
        return;
    }
    if(root->left){
        heapify_completeBT(root->left);
    }
    if(root->right){
        heapify_completeBT(root->right);
    }
    // percolateDown(root);
}