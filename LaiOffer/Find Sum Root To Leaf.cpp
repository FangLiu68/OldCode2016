//
//  Find Sum Root To Leaf.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/13/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 
 For example:
 Given the below binary tree and sum = 22,
 5
 / \
 4   8
 /   / \
 11  13  4
 /  \    / \
 7    2  5   1
 return
 [
 [5,4,11,2],
 [5,8,4,5]
 ]
 */

#include "BinaryTree.h"
#include <iostream>
#include <vector>
using namespace std;

void helper_pathSum(BinaryTreeNode* root, int sum, vector<int> temp, vector<vector<int>>& res);

vector<vector<int>> pathSum(BinaryTreeNode* root, int sum) {
    vector<int> temp;
    vector<vector<int>> res;
    helper_pathSum(root, sum, temp, res);
    return res;
}

void helper_pathSum(BinaryTreeNode* root, int sum, vector<int> temp, vector<vector<int>>& res){
    if(root == NULL){
        return;
    }
    
    temp.push_back(root->val);
    if(root->left == NULL && root->right == NULL){
        int path_sum = 0;
        for(int i=0; i<temp.size(); ++i){
            path_sum = path_sum + temp[i];
        }
        if(path_sum == sum){
            res.push_back(temp);
        }
    }
    
    helper_pathSum(root->left, sum, temp, res);
    helper_pathSum(root->right, sum, temp, res);
    
    temp.pop_back();
}