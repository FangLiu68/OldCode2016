//
//  Reverse Binary Tree.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/8/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/* Given a binary tree where all the right nodes are leaf nodes, flip it upside down and turn it into a tree with left leaf nodes.

 Examples
        1
      /    \
    2        5
   /  \
 3      4

 is reversed to
        3
      /    \
    2        4
   /  \
 1      5
*/

#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTreeNode* reverseBST(BinaryTreeNode* root){
    if(root==NULL || root->left==NULL)
        return root;

    BinaryTreeNode* left_child = root->left;
    BinaryTreeNode* right_child = root->right;
    BinaryTreeNode* nodeN = reverseBST(left_child);

    left_child->right = right_child;
    left_child->left = root;
    root->left = NULL;
    root->right = NULL;

    return nodeN;
}