//
//  Has Sum Root To Leaf.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/13/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 
 For example:
 Given the below binary tree and sum = 22,
 5
 / \
 4   8
 /   / \
 11  13  4
 /  \      \
 7    2      1
 return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

void helper_hasPath(BinaryTreeNode* root, int sum, int prefix, bool& res);

bool hasPathSum(BinaryTreeNode* root, int sum) {
    if(root == NULL) return false;
    bool res = false;
    helper_hasPath(root, sum, 0, res);
    return res;
}

void helper_hasPath(BinaryTreeNode* root, int sum, int prefix, bool& res){
    if(root == NULL) return;
    
    if(root->left == NULL && root->right == NULL){
        if(prefix + root->val == sum){
            res = true;
        }
    }
    
    helper_hasPath(root->left, sum, prefix+root->val, res);
    helper_hasPath(root->right, sum, prefix+root->val, res);
}