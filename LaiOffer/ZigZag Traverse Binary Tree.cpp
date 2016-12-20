//
//  Get Keys in Binary Tree ZigZag Level by Level.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/3/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Get the list of keys in a given binary tree layer by layer in zig-zag order.
 Examples
        5
      /    \
    3        8
  /   \        \
 1     4        11
 the result is [5, 3, 8, 11, 4, 1]
 Corner Cases
 What if the binary tree is null? Return an empty list in this case
 */

#include "BinaryTree.h"
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

// use double ended queue
// 若当前行是right to left,就按照right to left的次序遍历：从back取节点，同时下一行节点先push_front right child,
// then push_front left child
// 若当前行是left to right, 就按照left to right次序遍历：从front取节点，同时下一行节点先push_back left child,
// then push_back right child
vector<int> zigzag_level_traverse(BinaryTreeNode* root) {
    vector<int> res;
    if(root==NULL) return res;
    bool right_to_left = true;
    deque<BinaryTreeNode*> qu;
    qu.push_back(root);

    while(!qu.empty()){
        int len = qu.size();
        
        for(int i=0; i<len; i++){
            if(right_to_left){
                BinaryTreeNode* tmp = qu.back();
                qu.pop_back();
                res.push_back(tmp->val);
                if(tmp->right) qu.push_front(tmp->right);
                if(tmp->left) qu.push_front(tmp->left);
            }
            else{
                BinaryTreeNode* tmp = qu.front();
                qu.pop_front();
                res.push_back(tmp->val);
                if(tmp->left) qu.push_back(tmp->left);
                if(tmp->right) qu.push_back(tmp->right);
            }
        }
        
        right_to_left = !right_to_left;
    }
    return res;
}

/////////////////////////////////
/*
 Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

 For example:
 Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
 /  \
 15   7
 return its zigzag level order traversal as:
 [
 [3],
 [20,9],
 [15,7]
 ]
 */

vector<vector<int> > zigzagLevelOrder(BinaryTreeNode *root) {
    vector<vector<int>> res;
    if(root == NULL){
        return res;
    }

    deque<BinaryTreeNode*> dq;
    dq.push_back(root);
    bool left_to_right = true;

    while(!dq.empty()){
        int len = dq.size();
        vector<int> tmp;

        for(int i=0; i<len; ++i){
            if(left_to_right){
                BinaryTreeNode* cur = dq.front();
                dq.pop_front();
                tmp.push_back(cur->val);
                if(cur->left){
                    dq.push_back(cur->left);
                }
                if(cur->right){
                    dq.push_back(cur->right);
                }
            }else{
                BinaryTreeNode* cur = dq.back();
                dq.pop_back();
                tmp.push_back(cur->val);
                if(cur->right){
                    dq.push_front(cur->right);
                }
                if(cur->left){
                    dq.push_front(cur->left);
                }
            }
        }

        res.push_back(tmp);
        tmp.clear();
        left_to_right = !left_to_right; // 要在上面的for循环结束后才能变化left_to_right
    }
    return res;
}
