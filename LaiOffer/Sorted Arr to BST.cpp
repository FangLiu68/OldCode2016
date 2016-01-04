//
//  Sorted Arr to BST.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Given a sorted (increasing order) array with unique integer elements, write an algorithm to create a binary search tree with minimal height.

#include "Header.h"

// pre order visit. top to bottom. 先建立节点，再建立左子树，最后建立右子树。
BinaryTreeNode* helper_arrToBST(vector<int> input, int start, int end){
    if(start > end){ // when start==end, 只有一个元素，也要创建节点
        return NULL;
    }

    int mid = start + (end-start)/2;
    BinaryTreeNode* root = new BinaryTreeNode(input[mid]);
    root->left = helper_arrToBST(input, start, mid-1);
    root->right = helper_arrToBST(input, mid+1, end);

    return root;
}

BinaryTreeNode* arrToBST(vector<int> input){
    if(input.empty()) return NULL;
    return helper_arrToBST(input, 0, input.size()-1);
}