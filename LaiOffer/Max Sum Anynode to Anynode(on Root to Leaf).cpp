//
//  Max Sum Anynode to Anynode(on Root to Leaf).cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/2/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Q2.3 (laicode.com Class 20)  Maximum Path Sum Binary Tree III
 Given a binary tree in which each node contains an integer number. Find the maximum possible sum from any node to any node (the two nodes can be the same node and they can only be on the path from root to one of the leaf nodes).

 Assumptions
 The root of given binary tree is not null

 Examples
            -5
         /    \
        2      11
     /    \
    6     14

 The maximum path sum is 11 + 14 = 25
 Solution1:
 直上直下 path prefix
 Solution2:
 从下往上传值 is also ok.
 
 在root到leaf这一条路径上传递的时候，如果是任意节点到任意节点，我们需要用一个vector来存储当前访问的路径，每次将当前节点push到这个路径中之后，都要判断到此节点为止的current path sum是不是最大值(跟global max比较)，如果是，就更新global max，不是就继续访问下个节点。
 注意，每次Push进vector之后，在访问left child和right child完毕后，必须pop back出当前Node
 push -5，2，6
 pop  6
 push 14
 pop 14
 pop 2
 push 11
 pop 11
 pop -5
 */

#include "BinaryTree.h"
#include <vector>
#include <iostream>
using namespace std;

void helper(BinaryTreeNode* root, vector<int> &res, int &max);
int max_path_sum(BinaryTreeNode* root){
    if(root == NULL) return INT_MIN;
    int max_sum = INT_MIN;
    vector<int> path;
    helper(root, path, max_sum);
    return max_sum;
}

void helper(BinaryTreeNode* root, vector<int> &res, int &max_sum){
    // base case
    if(root == NULL) return;

    res.push_back(root->val);
    int sub_sum = 0;
    for(int i=res.size()-1; i>=0; i--){
        sub_sum += res[i];
        if(sub_sum > max_sum) max_sum = sub_sum;
    }
    helper(root->left, res, max_sum);
    helper(root->right, res, max_sum);

    res.pop_back();
}
