//
//  Max Path Cost.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/10/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Find the maximum path cost for all paths from leaf to root in a Binary Tree
 Given a Binary Tree, find the maximum sum path from a leaf to root. For example, in the following tree, there are three leaf to root paths 8->-2->10, -4->-2->10 and 7->10. The sums of these three paths are 16, 4 and 17 respectively. The maximum of them is 17 and the path for maximum is 7->10.
        10
     /      \
	-2        7
   /   \
  8     -4
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;


void helper_maxSum_rootToLeaf(BinaryTreeNode* root, int prefix, int& res){
    if(root == NULL){ // base case
        return;
    }
    // 指定从root到leaf就直接在base case判断当root是叶子节点的时候，此时的最大长度是多少就可以。
    if(root->left==NULL && root->right==NULL){ // base case when go to leaf node
        res = max(res, root->val + prefix);
        return;
    }

    helper_maxSum_rootToLeaf(root->left, prefix + root->val, res);
    helper_maxSum_rootToLeaf(root->right, prefix + root->val, res);
}

int maxSum_rootToLeaf(BinaryTreeNode* root){
    if(root == NULL){
        return INT_MIN;
    }
    int res = INT_MIN;
    helper_maxSum_rootToLeaf(root, 0, res);
    return res;
}