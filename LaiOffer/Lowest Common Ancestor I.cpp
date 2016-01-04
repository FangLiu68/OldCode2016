//
//  Lowest Common Ancestor.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/3/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given two nodes in a binary tree, find their lowest common ancestor.
 Assumptions
 There is no parent pointer for the nodes in the binary tree
 The given two nodes are guaranteed to be in the binary tree
 Examples
        5
      /   \
     9     12
   /  \      \
  2    3      14
 The lowest common ancestor of 2 and 14 is 5
 The lowest common ancestor of 2 and 9 is 9
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

/*
 Way of thinking (Tricks)
 1.  What do you expect from your lchild / rchild?
 whether there is a OR b in its left subtree, return a or b’ pointer if Yes
 whether there is a OR b in its right subtree, return a or b’s pointer if Yes
 2.  What do you want to do in the current layer?

 3.  What do you want to report to your parent? (same as Q1 == Q3)
	it is usually the return type of the Recursion function
 */

// Time Complexity: O(n), n is number of nodes in the tree
// 1) if a and b exist in the tree of ‘root’, return their LCA
// 2) if a or b (only one) exist in the tree, return a or b
// 3) return null

/*
 例如求LCA(5,2,14)
 left1 = LCA(9,2,14)  breaking point
         LCA(9,2,14), left2 = LCA(2,2,14) = 2
                      right2 = LCA(3,2,14) = NULL (因为LCA(3->left==NULL, 2, 14) = NULL, LCA(3->right==NULL, 2, 14))
         所以LCA(9,2,14)=2，即LCA(5->left, 2, 14) = 2
 right1 = LCA(12,2,14)
         同上，LCA(5->right, 2, 14) = 14
 所以LCA(5,2,14) = 5
 */
BinaryTreeNode* LCA(BinaryTreeNode* root, BinaryTreeNode* a, BinaryTreeNode* b){
    if(root == NULL){
        return NULL;
    }
    if(root == a || root == b){ // base case 找到a或者b就不用再往下找了，直接返回a or b
        return root;
    }

    // recursive rule
    // what do you expect from your left and right subtree
    BinaryTreeNode* left = LCA(root->left, a, b);
    BinaryTreeNode* right = LCA(root->right, a, b);

    // what do you want to do in the current level
    if(left!=NULL && right!=NULL){
        return root;
    }

    // what do you want to report to your parents
    return left? left:right;
}
