//
//  Path Sum to Target.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/10/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a binary tree in which each node contains an integer number. Determine if there exists a path from any node to any node (the two nodes can be the same node and they can only be on the path from root to one of the leaf nodes), the sum of the numbers on the path is the given target number.

 Examples

        5
     /    \
    2      11
         /    \
        6     14
 If target = 17, There exists a path 11 + 6, the sum of the path is target,
 If target = 10, There does not exist any paths sum of which is target.
 */

#include "BinaryTree.h"
#include <vector>
#include <iostream>
using namespace std;

void helper_Has_sum_on_rootToLeaf(BinaryTreeNode* root, vector<int>& path, int target, bool& match);
bool Has_sum_on_rootToLeaf(BinaryTreeNode* root, int target) {
    if(root == NULL){
        return false;
    }

    vector<int> path;
    bool match = false;
    helper_Has_sum_on_rootToLeaf(root, path, target, match);
    return match;
}

// 这个做法和has path sum的一样  好记
void helper_Has_sum_on_rootToLeaf(BinaryTreeNode* root, vector<int>& path, int target, bool& match){
    if(root == NULL || match){
        return;
    }

    path.push_back(root->val);
    int cur_sum = 0;
    for(int i=path.size()-1; i>=0; --i){
        cur_sum = cur_sum + path[i];
        if(cur_sum == target){
            match = true;
            return;
        }
    }

    helper_Has_sum_on_rootToLeaf(root->left, path, target, match);
    helper_Has_sum_on_rootToLeaf(root->right, path, target, match);
    path.pop_back();
}


// 第二种方法
bool helper(BinaryTreeNode* root, vector<int> &path, int target);
bool path_sum_to_target(BinaryTreeNode* root, int target){
    if(root == NULL) return false;
    vector<int> path;
    return helper(root, path, target);
}

bool helper(BinaryTreeNode* root, vector<int> &path, int target){
    // base case
    if(root == NULL) return false;

    path.push_back(root->val);
    int sub_sum = 0;
    for(int i=path.size()-1; i>=0; i--){
        sub_sum += path[i];
        if(sub_sum == target)
            return true;
    }

    bool left_part = helper(root->left, path, target);
    bool right_part = helper(root->right, path, target);
    path.pop_back();
    return left_part || right_part;
}