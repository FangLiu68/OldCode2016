//
//  is BST.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Determine if a given binary tree is binary search tree.

 Assumptions
 There are no duplicate keys in binary search tree.
 Corner Cases
 What if the binary tree is null? Return true in this case.
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

bool helper(BinaryTreeNode* root, int min, int max);
bool isBST(BinaryTreeNode* root) {
    if(root == NULL)  return true;
    return helper(root, INT_MIN, INT_MAX);
}

bool helper(BinaryTreeNode* root, int min, int max){
    // base case
    if(root == NULL) return true;

    if(root->val<=min || root->val>max)
        return false;

    //cout << root->val << endl;

    // report to parent
    bool left_is_bst = helper(root->left, min, root->val);
    bool right_is_bst = helper(root->right, root->val, max);

    return left_is_bst && right_is_bst;

}
/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(10);
    BinaryTreeNode* left1 = new BinaryTreeNode(5);
    BinaryTreeNode* right1 = new BinaryTreeNode(15);
    BinaryTreeNode* left21 = new BinaryTreeNode(2);
    BinaryTreeNode* left22 = new BinaryTreeNode(7);
    BinaryTreeNode* right21 = new BinaryTreeNode(12);
    BinaryTreeNode* right22 = new BinaryTreeNode(20);
    root->left = left1;
    root->right = right1;
    left1->left = left21;
    left1->right = left22;
    right1->left = right21;
    right1->right = right22;
    if(isBST(root)) cout << "yes" << endl;
    else cout << "no" << endl;
}*/