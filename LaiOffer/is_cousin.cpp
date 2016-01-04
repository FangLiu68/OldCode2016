//
//  is_cousin.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include "BinaryTree.h"
#include <iostream>
#include "assert.h"
using namespace std;

/*
 Check if two nodes are cousins in a Binary Tree
 Given the binary Tree and the two nodes say ‘a’ and ‘b’, determine whether the two nodes are cousins of each other or not.
 Two nodes are cousins of each other if they are at same level and have different parents.
 Example
        6
      /   \
     3     5
    / \   / \
   7   8 1   3
 7 and 1, result is TRUE.
 3 and 5, result is FALSE.
 7 and 5, result is FALSE.
 */

/*
 1. find height for each node;
 2. find lowest common ancestor for each node;
 3. if both have diff height, return false
    if both have same height, 
        return true if bother have diff LCA
 */

int helper_get_height(BinaryTreeNode* node){
    if(node == NULL){
        return 0;
    }
    int left = helper_get_height(node->left);
    int right = helper_get_height(node->right);
    return max(left, right) + 1;
}

BinaryTreeNode* helper_LCA(BinaryTreeNode* root, BinaryTreeNode* node1, BinaryTreeNode* node2){
    if(root == NULL){
        return NULL;
    }
    if(root == node1 || root == node2){
        return root;
    }

    BinaryTreeNode* left = helper_LCA(root->left, node1, node2);
    BinaryTreeNode* right = helper_LCA(root->right, node1, node2);

    if(left && right){
        return root;
    }else{
        return left ? left : right;
    }
}

bool is_cousin(BinaryTreeNode* root, BinaryTreeNode* node1, BinaryTreeNode* node2){
    if(root == NULL){
        return false;
    }
    if(helper_get_height(node1) != helper_get_height(node2)){
        return false;
    }else{
        BinaryTreeNode* cur_LCA = helper_LCA(root, node1, node2);
        if((cur_LCA->left == node1 && cur_LCA->right == node2) || (cur_LCA->right == node1 && cur_LCA->left == node2)){
            return false;
        }else{
            return true;
        }
    }
}
/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(6);
    BinaryTreeNode* node1 = new BinaryTreeNode(3);
    BinaryTreeNode* node2 = new BinaryTreeNode(5);
    BinaryTreeNode* node3 = new BinaryTreeNode(7);
    BinaryTreeNode* node4 = new BinaryTreeNode(8);
    BinaryTreeNode* node5 = new BinaryTreeNode(1);
    BinaryTreeNode* node6 = new BinaryTreeNode(3);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;
    assert(is_cousin(root, node1, node2) == false);
    assert(is_cousin(root, node1, node5) == false);
    assert(is_cousin(root, node3, node5) == true);
    return 0;
}*/