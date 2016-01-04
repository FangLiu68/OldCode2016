//
//  Lowest Common Ancestor III.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/3/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given K nodes in a binary tree, find their lowest common ancestor.
 Assumptions
 K >= 2
 There is no parent pointer for the nodes in the binary tree
 The given two nodes are guaranteed to be in the binary tree
 Examples
 5
 /   \
 9     12
 /  \      \
 2    3      14
 The lowest common ancestor of 2, 3, 14 is 5
 The lowest common ancestor of 2, 3, 9 is 9
 */

#include "BinaryTree.h"
#include <vector>
#include <iostream>
using namespace std;

BinaryTreeNode* solve(BinaryTreeNode* root, vector<BinaryTreeNode*> nodes) {
    if(root == NULL || nodes.size() < 2) return NULL;

    for(int i=0; i<nodes.size(); i++){
        if(root == nodes[i])
            return root;
    }

    BinaryTreeNode* left = solve(root->left, nodes);
    BinaryTreeNode* right = solve(root->right, nodes);

    if(left && right){
        return root;
    }
    return left?left:right;
}