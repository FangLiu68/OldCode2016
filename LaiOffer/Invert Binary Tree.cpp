//
//  Invert Binary Tree.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/18/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/* invert a binary tree
        4
      /   \
     2     7
    / \   / \
   1   3 6   9
 
 invert to 
        4
      /   \
     7     2
    / \   / \
   9   6 3   1

 从最底层向上传值，每次都把current node的左右孩子对调
 是后序遍历
*/

#include "BinaryTree.h"
#include <iostream>
#include <vector>
using namespace std;

BinaryTreeNode* invertTree(BinaryTreeNode* root) {
    if(root == NULL){
        return NULL;
    }

    // what do you want from your left and right child
    BinaryTreeNode* left = invertTree(root->left);
    BinaryTreeNode* right = invertTree(root->right);

    // what do you want to do in current level
    root->left = right;
    root->right = left;

    // what do you want to report to your parent
    return root;
}
/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(4);
    BinaryTreeNode* node2 = new BinaryTreeNode(2);
    BinaryTreeNode* node7 = new BinaryTreeNode(7);
    BinaryTreeNode* node1 = new BinaryTreeNode(1);
    BinaryTreeNode* node3 = new BinaryTreeNode(3);
    BinaryTreeNode* node6 = new BinaryTreeNode(6);
    BinaryTreeNode* node9 = new BinaryTreeNode(9);
    root->left = node2;
    root->right = node7;
    node2->left = node1;
    node2->right = node3;
    node7->left = node6;
    node7->right = node9;
    BinaryTreeNode* res = invertTree(root);
    vector<int> val = inOrder_iter(res);
    for(int i=0; i<val.size(); ++i){
        cout << val[i] << " ";
    }return 0;
}*/