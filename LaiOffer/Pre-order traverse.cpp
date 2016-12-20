//
//  pre_order traverse.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Implement an iterative, pre-order traversal of a given binary tree, return the list of keys of each node in the tree as it is pre-order traversed.
 Examples
      5
    /    \
   3        8
  /   \        \
 1      4        11

 Pre-order traversal is [5, 3, 1, 4, 8, 11]
 Corner Cases
 What if the given binary tree is null? Return an empty list in this case.
 */

#include "Header.h"

/*
                1
            /       \
        2                 3
     /     \           /     \
   4         5        6       7

 nth Loop			stack content (top->bottom)		print
 0					1
 1					2 3                             1
 2					4 5 3                           2
 3					5 3                             4
 4					3                               5
 5					6 7                             3
 6					7                               6
 7                                                  7
 */

vector<int> pre_order_iter(BinaryTreeNode* root) {
    vector<int> res;
    if(root == NULL) return res;
    stack<BinaryTreeNode*> stk;
    stk.push(root);

    while(!stk.empty()){
        BinaryTreeNode* top = stk.top();
        stk.pop();
        res.push_back(top->val);
        
        if(top->right) stk.push(top->right);
        if(top->left) stk.push(top->left);
    }

    return res;
}

//==============================================================
void helper_pre(BinaryTreeNode* root, vector<int> &res);
vector<int> pre_order_recur(BinaryTreeNode* root) {
    vector<int> res;
    if(root == NULL) return res;
    helper_pre(root, res);
    return res;
}
void helper_pre(BinaryTreeNode* root, vector<int> &res){
    if(root == NULL) return;

    res.push_back(root->val);
    helper_pre(root->left, res);
    helper_pre(root->right, res);
}