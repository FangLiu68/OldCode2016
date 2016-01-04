//
//  LCA in BST.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/13/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Find lowest commen ancestor in binary search tree

#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTreeNode* LCA_BST(BinaryTreeNode* root, BinaryTreeNode* a, BinaryTreeNode* b){
    if(root == NULL) return NULL;
    if(root == a || root == b) return root;

    if(max(a->val, b->val) < root->val){
        return LCA_BST(root->left, a, b);
    }else if(min(a->val, b->val) > root->val){
        return LCA_BST(root->right, a, b);
    }else{
        return root;
    }
}

/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(4);
    BinaryTreeNode* node2 = new BinaryTreeNode(2);
    BinaryTreeNode* node6 = new BinaryTreeNode(6);
    BinaryTreeNode* node1 = new BinaryTreeNode(1);
    BinaryTreeNode* node3 = new BinaryTreeNode(3);
    BinaryTreeNode* node5 = new BinaryTreeNode(5);
    BinaryTreeNode* node7 = new BinaryTreeNode(7);
    root->left = node2;
    root->right = node6;
    node2->left = node1;
    node2->right = node3;
    node6->left = node5;
    node6->right = node7;

    BinaryTreeNode* res = LCA_BST(root, node7, node5);
    cout << res->val << endl;
    return 0;
}*/
