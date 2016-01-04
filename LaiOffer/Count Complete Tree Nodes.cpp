//
//  Count Complete Tree Nodes.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/19/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a complete binary tree, count the number of nodes.

 Definition of a complete binary tree from Wikipedia:
 In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

/*
 Steps to solve this problem:
 1) get the height of left-most part
 2) get the height of right-most part
 3) when they are equal, the # of nodes = 2^h -1
 4) when they are not equal, recursively get # of nodes from left&right sub-trees
 */

int getLeftHeight(BinaryTreeNode* node){
    if(node == NULL) return 0;
    int res = 0;
    while(node->left){
        res++;
        node = node->left;
    }
    return res;
}

int getRightHeight(BinaryTreeNode* node){
    if(node == NULL) return 0;
    int res = 0;
    while(node->right){
        res++;
        node = node->right;
    }
    return res;
}

int countNodes(BinaryTreeNode* root) {
    if(root == NULL){
        return 0;
    }
    int leftHeight = getLeftHeight(root) ;
    int rightHeight = getRightHeight(root) ;
    if(leftHeight == rightHeight){
        return (2<<(leftHeight)) - 1; // 2^(leftHeight)-1
    }else{
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
}

