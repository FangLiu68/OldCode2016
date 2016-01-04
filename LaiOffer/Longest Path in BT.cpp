//
//  Longest Path in BT.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/7/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a binary tree in which each node contains an integer number. The diameter is defined as the longest distance from one leaf node to another leaf node. The distance is the number of nodes on the path.
 If there does not exist any such paths, return 0.

 Examples
        5
     /    \
    2      11
  /    \
 6     14
 The diameter of this tree is 4 (2 → 5 → 11 → 14)
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

int helper_longestPath(BinaryTreeNode* root, int& res);
int longest_path_in_BT(BinaryTreeNode* root){
    if(root == NULL){
        return 0;
    }
    int res = 0;
    helper_longestPath(root, res);
    return res;
}

int helper_longestPath(BinaryTreeNode* root, int& res){
    if(root == NULL){
        return 0;
    }
    int left = helper_longestPath(root->left, res);
    int right = helper_longestPath(root->right, res);
    int cur = left + right + 1;
    if(cur > res && root->left && root->right){
        res = cur;
    }
    return max(left, right) + 1;
}

