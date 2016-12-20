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
     1
  2     3
 做2的幂时不要用Math.pow，这样会超时。用1<<height这个方法来得到2的幂
 */

int left_height(BinaryTreeNode* root){
    int res = 0;
    while(root){
        res++;
        root = root->left;
    }
    return res;
}

int right_height(BinaryTreeNode* root){
    int res = 0;
    while(root){
        res++;
        root = root->right;
    }
    return res;
}

int countNodes(BinaryTreeNode* root) {
    if(root == NULL) return 0;
    
    int left = left_height(root);
    int right = right_height(root);
    
    if(left == right){
        return (1 << left) - 1; // 如果两个深度一样，返回2^h-1
    }else{
        return countNodes(root->left) + countNodes(root->right) + 1; // 否则返回左子树右子树节点和加1
    }
}

