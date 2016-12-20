//
//  Num of Path Sum from Root to Leaf.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/3/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Given a binary tree, find its number of paths that sum to target k from root to leaf.

#include "BinaryTree.h"
#include <iostream>
#include <vector>
using namespace std;

void helper_numOfPaths(BinaryTreeNode* root, int k, vector<vector<int>>& res, vector<int>& path){
    if(root == NULL) return;

    path.push_back(root->val);

    // 注意：要在path将root->val push进入path之后再计算路径和。否则就会漏掉将最后一个叶节点放入和中
    // if里的条件保证了我们只有在最后一层叶节点的时候才计算路径上的所有节点和是否等于k
    if(root->left == NULL && root->right == NULL){
        int cur_sum = 0;
        for(int i = path.size()-1; i>=0; --i){
            cur_sum = cur_sum + path[i];
        }
        if(cur_sum == k){
            res.push_back(path);
            // return; 这里不能return，因为我们在root==NULL的时候return，就正好return到上一层，而此时pop_back，就正好把上一条路径的最后一个节点pop出，再重新试探下一个节点
        }
    }

    helper_numOfPaths(root->left, k, res, path);
    helper_numOfPaths(root->right, k, res, path);
    path.pop_back();
}

vector<vector<int>> num_of_paths(BinaryTreeNode* root, int k){
    vector<vector<int>> res;
    if(root == NULL){
        return res;
    }
    vector<int> path;
    helper_numOfPaths(root, k, res, path);
    return res;
}

/*
int main(){

    BinaryTreeNode* root = new BinaryTreeNode(15);
    BinaryTreeNode* left1 = new BinaryTreeNode(-5);
    BinaryTreeNode* right1 = new BinaryTreeNode(2);
    BinaryTreeNode* left2 = new BinaryTreeNode(-7);
    BinaryTreeNode* right2 = new BinaryTreeNode(3);
    root->left = left1;
    root->right = right1;
    right1->left = left2;
    right1->right = right2;


    vector<vector<int>> res = num_of_paths(root, 10);
    if(res.empty()) cout << "empty" << endl;
    for(int i=0; i<res.size(); ++i){
        vector<int> cur = res[i];
        for(int j=0; j<cur.size(); ++j){
            cout << cur[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
*/