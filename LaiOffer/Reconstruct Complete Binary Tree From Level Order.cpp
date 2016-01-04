//
//  Reconstruct Complete Binary Tree From Level Order.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/14/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Reconstruct a complete binary tree with level order traversal

#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTreeNode* helper_construct(int levelOrder[], int len, int index);
BinaryTreeNode* construct_from_levelOrder(int levelOrder[], int len){
    if(levelOrder==NULL || len<=0){
        return NULL;
    }
    return helper_construct(levelOrder, len, 0);
}

BinaryTreeNode* helper_construct(int levelOrder[], int len, int index){
    if(index >= len){
        return NULL;
    }
    BinaryTreeNode* root = new BinaryTreeNode(levelOrder[index]);
    root->left = helper_construct(levelOrder, len, 2*index+1);
    root->right = helper_construct(levelOrder, len, 2*index+2);
    return root;
}