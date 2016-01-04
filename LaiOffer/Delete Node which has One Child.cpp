//
//  Delete Node which has One Child.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/8/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/* Delete all nodes that only have one child node in a binary tree.
                            10 (root)
                  5                      12
              6	     Null       Null        14
 input	   2	  8		               Null	      19
 ----------------------------------------------------------------------------------------------
 output						10 (root)
                     6		           19
                 2       8
*/

#include "BinaryTree.h"
#include <iostream>
using namespace std;

/*
 利用post order traversal，从下往上传值，把只有一个孩子的节点删掉，同时把他从下一层收到的结果设为当前层root，
 再往上传给他的父节点
 */

void print_node(BinaryTreeNode* root){
    if(root == NULL){
        return;
    }
    print_node(root->left);
    print_node(root->right);
    cout << root->val << " ";
}

BinaryTreeNode* removeHalfNodes(BinaryTreeNode* root){
    if(root == NULL){
        return NULL;
    }

    root->left = removeHalfNodes(root->left);
    root->right = removeHalfNodes(root->right);

    if(root->left == NULL && root->right == NULL){
        return root;
    }else if(root->left == NULL){
        BinaryTreeNode* new_root = root->right;
        delete root;
        root = NULL;
        return new_root;
    }else if(root->right == NULL){
        BinaryTreeNode* new_root = root->left;
        delete root;
        root = NULL;
        return new_root;
    }else{ // root->left!=NULL && root->right!=NULL
        return root;
    }
}

/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(10);
    BinaryTreeNode* level11 = new BinaryTreeNode(5);
    BinaryTreeNode* level12 = new BinaryTreeNode(12);
    BinaryTreeNode* level21 = new BinaryTreeNode(6);
    BinaryTreeNode* level22 = new BinaryTreeNode(14);
    BinaryTreeNode* level31 = new BinaryTreeNode(2);
    BinaryTreeNode* level32 = new BinaryTreeNode(8);
    BinaryTreeNode* level33 = new BinaryTreeNode(19);
    root->left = level11;
    root->right = level12;
    level11->left = level21;
    level12->right= level22;
    level21->left = level31;
    level21->right = level32;
    level22->right = level33;
    print_node(root);
    cout << endl;

    BinaryTreeNode* new_root = removeHalfNodes(root);
    print_node(new_root);
    cout << endl;

    return 0;
}*/