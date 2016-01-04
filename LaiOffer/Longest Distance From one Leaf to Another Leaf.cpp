//
//  Binary Tree Diameter.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/10/15.
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

int helper(BinaryTreeNode* root, int &max_dis);

int BTDiameter(BinaryTreeNode* root){
    if(root == NULL) return 0;
    int max_dis = 0;
    helper(root, max_dis);
    return max_dis;
}

int helper(BinaryTreeNode* root, int &max_dis){
    // base case
    if(root == NULL) return 0;

    int left_cost = helper(root->left, max_dis);
    int right_cost = helper(root->right, max_dis);
    int cur_cost = left_cost + right_cost + 1;
    if(cur_cost > max_dis && root->left && root->right){
        max_dis = cur_cost;
    }

    if(root->left == NULL){
        return right_cost + 1;
    }else if(root->right == NULL){
        return left_cost + 1;
    }else{
        return max(left_cost, right_cost) + 1; // 上面的两个if可以去掉，只写这一行就行
    }
}

