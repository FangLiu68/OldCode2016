//
//  Symmetric Binary Tree.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Check if a given binary tree is symmetric.
 Examples
        5
     /    \
    3        3
  /   \    /    \
 1     4  4      1
 is symmetric.

        5
     /    \
    3        3
  /   \    /   \
 1     4   1    4
 is not symmetric.
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

bool helper(BinaryTreeNode* left_node, BinaryTreeNode* right_node);
bool is_symmetric_BinaryTree(BinaryTreeNode* root) {
    if(root == NULL){
        return true;
    }
    return helper(root->left, root->right);
}

// O(n) runtime
bool helper(BinaryTreeNode* left_node, BinaryTreeNode* right_node){
    // base case 只比较两个Node
    if(left_node==NULL && right_node==NULL){
        return true;
    }else if(left_node==NULL || right_node==NULL){
        return false;
    }else if(left_node->val != right_node->val){
        return false;
    }

    //cout << left_node->val <<" " << right_node->val << endl;

    // what do you want from your left and right child
    bool outer = helper(left_node->left, right_node->right);
    bool insider = helper(left_node->right, right_node->left);

    cout << left_node->val <<" " << right_node->val << endl;

    // what do you want to report to your parent
    return outer && insider;
}

/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(10);
    BinaryTreeNode* left1 = new BinaryTreeNode(5);
    BinaryTreeNode* right1 = new BinaryTreeNode(5);

    BinaryTreeNode* left21 = new BinaryTreeNode(1);
    BinaryTreeNode* right21 = new BinaryTreeNode(1);
    BinaryTreeNode* left22 = new BinaryTreeNode(3);
    BinaryTreeNode* right22 = new BinaryTreeNode(3);

    BinaryTreeNode* left31 = new BinaryTreeNode(2);
    BinaryTreeNode* left32 = new BinaryTreeNode(4);
    BinaryTreeNode* left33 = new BinaryTreeNode(6);
    BinaryTreeNode* left34 = new BinaryTreeNode(8);

    BinaryTreeNode* right31 = new BinaryTreeNode(2);
    BinaryTreeNode* right32 = new BinaryTreeNode(4);
    BinaryTreeNode* right33 = new BinaryTreeNode(6);
    BinaryTreeNode* right34 = new BinaryTreeNode(8);

    root->left = left1;
    root->right = right1;

    left1->left = left21;
    left1->right = left22;
    right1->right = right21;
    right1->left = right22;

    left21->left = left31;
    left21->right = left32;
    right21->left = right32;
    right21->right = right31;
    left22->left = left33;
    left22->right = left34;
    right22->left = right34;
    right22->right = right33;
    if(is_symmetric_BinaryTree(root))  cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}*/