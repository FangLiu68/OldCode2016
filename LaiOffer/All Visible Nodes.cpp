//
//  All Visible Nodes.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/17/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// if the node is the largest one on the path from root to the node, then the node is visible
/*
            2
        7       1
     6    5   3     4
 */
#include "BinaryTree.h"
#include <vector>
#include <iostream>
using namespace std;

/*
 先序遍历。先更改到这个节点为止curMax的值，再往下一层走
 所以在同一层的不同节点上，到这个节点之前的最大值仍是这个节点的父节点的那一层的最大值
 例如7之前的最大值是2，到7更新为7
 1之前的最大值是2，到1不更新，到3才更新最大值为3
 */
void helper_visibleNode(BinaryTreeNode* root, int curMax, vector<BinaryTreeNode*>& res){
    if(root == NULL){
        return;
    }
    if(root->val >= curMax){
        res.push_back(root);
        curMax = root->val;
    }
    helper_visibleNode(root->left, curMax, res);
    helper_visibleNode(root->right, curMax, res);
}

vector<BinaryTreeNode*> all_visibleNodes(BinaryTreeNode* root){
    vector<BinaryTreeNode*> res;
    if(root == NULL) return res;
    helper_visibleNode(root, INT_MIN, res);
    return res;
}
/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(2);
    BinaryTreeNode* node7 = new BinaryTreeNode(7);
    BinaryTreeNode* node1 = new BinaryTreeNode(1);
    BinaryTreeNode* node6 = new BinaryTreeNode(6);
    BinaryTreeNode* node5 = new BinaryTreeNode(5);
    BinaryTreeNode* node3 = new BinaryTreeNode(3);
    BinaryTreeNode* node4 = new BinaryTreeNode(4);
    root->left = node7;
    root->right = node1;
    node7->left = node6;
    node7->right = node5;
    node1->left = node3;
    node1->right = node4;
    vector<BinaryTreeNode*> res = all_visibleNodes(root);
    for(int i=0; i<res.size(); ++i){
        cout << res[i]->val << " ";
    }return 0;
}*/