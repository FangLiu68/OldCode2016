//
//  Reconstruct BST with Pre Order Traversal.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/14/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given the preorder traversal sequence of a binary search tree, reconstruct the original tree.

 Assumptions
 The given sequence is not null
 There are no duplicate keys in the binary search tree
 
 Examples
 preorder traversal = {5, 3, 1, 4, 8, 11}
 The corresponding binary search tree is
        5
     /    \
    3        8
  /   \        \
 1      4       11

 How is the binary tree represented?
 We use the pre order traversal sequence with a special symbol "#" denoting the null node.
 For Example:
 The sequence [1, 2, #, 3, 4, #, #, #] represents the following binary tree:
        1
     /   \
    2     3
         /
        4
 */

#include "Header.h"

BinaryTreeNode* helper(vector<int> pre, int left, int right);
int findMid(vector<int> pre, int left, int right, int target);
BinaryTreeNode* reconstruct(vector<int> pre) {
    if(pre.empty()){
        return NULL;
    }
    return helper(pre, 0, pre.size()-1);
}

BinaryTreeNode* helper(vector<int> pre, int left, int right){
    if(left > right){
        return NULL;
    }
    if(left == right){
        return new BinaryTreeNode(pre[left]);
    }
    BinaryTreeNode* root = new BinaryTreeNode(pre[left]);
    int mid = findMid(pre, left+1, right, pre[left]);
    root->left = helper(pre, left+1, mid);
    root->right = helper(pre, mid+1, right);
    return root;
}

int findMid(vector<int> pre, int left, int right, int target){
    while(left <= right){
        int mid = left+(right-left)/2;
        if(pre[mid] > target){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return right;
}
