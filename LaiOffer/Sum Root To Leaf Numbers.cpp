//
//  Sum Root To Leaf Numbers.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/11/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 
 An example is the root-to-leaf path 1->2->3 which represents the number 123.
 
 Find the total sum of all root-to-leaf numbers.
 
 For example,
 
 1
 / \
 2   3
 The root-to-leaf path 1->2 represents the number 12.
 The root-to-leaf path 1->3 represents the number 13.
 
 Return the sum = 12 + 13 = 25.
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

void helper_sumNumbers(BinaryTreeNode* root, int cur_sum, int& sum);

int sumNumbers(BinaryTreeNode* root) {
    if(root == NULL) return 0;
    int sum = 0;
    helper_sumNumbers(root, 0, sum);
    return sum;
}

void helper_sumNumbers(BinaryTreeNode* root, int cur_sum, int& sum){
    if(root == NULL){
        return;
    }
    
    cur_sum = cur_sum * 10 + root->val;
    
    if(root->left == NULL && root->right == NULL){
        sum = sum + cur_sum;
    }
    
    helper_sumNumbers(root->left, cur_sum, sum);
    helper_sumNumbers(root->right, cur_sum, sum);
}