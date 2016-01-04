//
//  Remove Trailing Zero Nodes.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 recursively remove all the trailing zero nodes from leaves, binary tree only 0 or 1 nodes

            1
        /        \
       1          0
     /    \      /   \
    1      0    1      0
   /      /  \           \
  0      0    0            0

 */

#include "BinaryTree.h"
#include <vector>
#include <iostream>
using namespace std;

/*
 一直往下走到最下层的叶子节点，如果叶子节点的值为0，就删除，同时向上一层返回本层结果
 from bottom to top逐渐删除符合条件的节点
 */

BinaryTreeNode* removeZero(BinaryTreeNode* root){
    if(root == NULL){
        return NULL;
    }
    root->left = removeZero(root->left);
    root->right = removeZero(root->right);
    if(root->left == NULL && root->right == NULL && root->val == 0){
        return NULL;
    }else{
        return root;
    }
}