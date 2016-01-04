//
//  Find Node with Max Diff subtree.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/7/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Find the node with the max difference in the total number descendents in its left subtree and right subtree

/*
 从下往上返回值
 题意是：找到这样一个node，他的左子树的节点个数和右子树的节点个数的差值 最大
 定义function signature:
 return value: 你想返回给上一层什么值，就把function的return value设为什么类型的值
 arguments: 哪些值是你需要在整个过程中跟踪的，就放在arguments里，作为外部变量
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

/*
 1. what do you want from your left and right child?
    left_cost: left subtree一共有多少个node
    right_cost: right subtree一共有多少个node
 2. what do you want to do in this current layer?
    如果abs(left_cost-right_cost)>max_val，更新max_val, 同时更新pNode
    pNode一直跟踪的是最大max_val的node
 3. what do you want to report to your parent?
    left_cost+right_cost+1 (1代表当前节点，有一个)
 
 这题类似于，找二叉树有几个节点。因为找节点是从底往上加的，所以我们只用在每次找完左右子树节点之后，比较下当前root下的max_diff是否需要改变就好。
 */
// O(N) runtime
int helper_maxDiffSubtree(BinaryTreeNode* root, BinaryTreeNode* &pNode, int &max_diff);
BinaryTreeNode* find_node_with_max_diffSubtree(BinaryTreeNode* root){
    if(root == NULL){
        return NULL;
    }
    BinaryTreeNode* pNode = NULL;
    int max_diff = 0;
    helper_maxDiffSubtree(root, pNode, max_diff);
    return pNode;
}

int helper_maxDiffSubtree(BinaryTreeNode* root, BinaryTreeNode* &pNode, int &max_diff){
    // base case
    if(root == NULL) return 0;

    int left_cost = helper_maxDiffSubtree(root->left, pNode, max_diff);
    int right_cost = helper_maxDiffSubtree(root->right, pNode, max_diff);
    if(abs(left_cost - right_cost) > max_diff){
        max_diff = abs(left_cost - right_cost);
        pNode = root;
    }

    // 往上一层汇报的是 包括当前节点在内的，他的subtree的所有节点
    return left_cost + right_cost + 1;
}
