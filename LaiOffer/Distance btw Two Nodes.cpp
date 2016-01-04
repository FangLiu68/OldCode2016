//
//  Distance btw Two Nodes.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/2/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Find distance between two given keys of a Binary Tree
 Find the distance between two nodes in a binary tree, no parent pointers are given. Distance between two nodes is the minimum number of edges to be traversed to reach one node from other.
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTreeNode* helper_getLCA(BinaryTreeNode* root, BinaryTreeNode* node1, BinaryTreeNode* node2);
int get_diff_len(BinaryTreeNode* high, BinaryTreeNode* low);
int helper_get_height1(BinaryTreeNode* node);

int min_distance(BinaryTreeNode* root, BinaryTreeNode* node1, BinaryTreeNode* node2){
    if(root == NULL || node1 == NULL || node2 == NULL){
        return -1;
    }
    BinaryTreeNode* lca = helper_getLCA(root, node1, node2);
    int hight1 = get_diff_len(lca, node1);
    int hight2 = get_diff_len(lca, node2);
    return hight1 + hight2;
}

BinaryTreeNode* helper_getLCA(BinaryTreeNode* root, BinaryTreeNode* node1, BinaryTreeNode* node2){
    if(node1 == NULL || node2 == NULL){
        return NULL;
    }
    if(root == node1 || root == node2){
        return root;
    }
    BinaryTreeNode* left = helper_getLCA(root->left, node1, node2);
    BinaryTreeNode* right = helper_getLCA(root->right, node1, node2);
    if(left && right){
        return root;
    }else{
        return left? left:right;
    }
}

int helper_get_height1(BinaryTreeNode* node){
    if(node == NULL){
        return 0;
    }
    int left = helper_get_height1(node->left);
    int right = helper_get_height1(node->right);
    return max(left, right) + 1;
}
int get_diff_len(BinaryTreeNode* high, BinaryTreeNode* low){
    if(high == NULL || low == NULL){
        return -1;
    }
    int cur_high = helper_get_height1(high);
    int cur_low = helper_get_height1(low);
    return cur_high - cur_low;
}

// get height from top to bottom
int level_node;
void get_height_topDown(BinaryTreeNode* root, BinaryTreeNode* node, int level){
    if(root == NULL){
        return;
    }
    if(root == node){
        level_node = level;
    }
    get_height_topDown(root->left, node, level+1);
    get_height_topDown(root->right, node, level+1);
}