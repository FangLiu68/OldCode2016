//
//  Insert Node in BST.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/6/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include "Header.h"

// 新node只可能放在叶子节点的下面
void insert_node_in_BST_iter(BinaryTreeNode*& root, int add_value){
    BinaryTreeNode* add_node = new BinaryTreeNode(add_value);
    if(root == NULL){
        root = add_node;
        return;
    }
    BinaryTreeNode* cur = root;
    BinaryTreeNode* parent = NULL;
    while(cur){
        if(cur->val < add_value){
            parent = cur;
            cur = cur->right;
        }
        else{
            parent = cur;
            cur = cur->left;
        }
    }
    if(parent->val > add_value){
        parent->left = add_node;
    }else{
        parent->right = add_node;
    }
}


BinaryTreeNode* insert_BST_recur(BinaryTreeNode* root, int value) {
    // base case
    if(root == NULL)
        return new BinaryTreeNode(value);
    else if(root->val > value)
        root->left = insert_BST_recur(root->left, value);
    else if(root->val < value)
        root->right = insert_BST_recur(root->right, value);

    return root;
}


