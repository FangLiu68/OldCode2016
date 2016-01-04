//
//  Print Top View of Binary Tree.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a binary tree, print the top view of it. The output nodes can be printed in any order. Time = O(n)
 A node x is there in output if x is the topmost node at its horizontal distance. 
 Horizontal distance of a child of a node x is equal to horizontal distance of x minus 1, and that of right child is horizontal distance of x plus 1.

      1
    /     \
   2       3
  /  \       / \
 4    5     6   7

 Output 4 2 1 3 7

 Example 2
        1
      /   \
    2       3
      \
        4
          \
            5
             \
               6

 Output 2 1 3 6
*/
#include "BinaryTree.h"
#include <queue>
#include <map>
#include <iostream>
using namespace std;

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    int column;
    TreeNode(int v) : val(v), column(0), left(NULL), right(NULL){}
    TreeNode(int v, int c) : val(v), column(c), left(NULL), right(NULL){}
};

// level order traverse
// each time we when we try to push the children on next level into queue, we tag their column numbers
// and when we review the current level's value from left to right, we only print the node with available column nums
// key:node; value:位移
// key:位移；value:node
void topViewBT(TreeNode* root){
    if(root == NULL){
        return;
    }
    root->column = 0;
    queue<TreeNode*> q;
    q.push(root);
    int max_dis = -1;
    int cur_dis = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; ++i){
            TreeNode* cur = q.front();
            q.pop();
            cur_dis = abs(cur->column);
            if(cur_dis > max_dis){
                cout << cur->val << " ";
            }
            if(cur->left){
                cur->left->column = cur->column - 1;
                q.push(cur->left);
            }
            if(cur->right){
                cur->right->column = cur->column + 1;
                q.push(cur->right);
            }
        }
        // update max_dis after we finish reviewing the same level
        max_dis = max(cur_dis, max_dis);
    }
}

//  按顺序打印，用DFS
void helper_topView(BinaryTreeNode* root, map<int, pair<int, int>>& mp, int col, int level, int& left){
    if(root == NULL){
        return;
    }
    left = min(left, col);

    if(mp.find(col) == mp.end()){
        mp[col] = make_pair(level,root->val);
    }else{
        if(mp[col].first > level){
            mp[col].first = level;
            mp[col].second = root->val;
        }
    }

    helper_topView(root->left, mp, col-1, level+1, left);
    helper_topView(root->right, mp, col+1, level+1, left);
}

void topViewSequence(BinaryTreeNode* root){
    if(root == NULL){
        return;
    }
    map<int, pair<int,int>> mp;
    int left = 0;
    helper_topView(root, mp, 0, 0, left);
    while(mp.find(left) != mp.end()){
        cout << mp[left].first << " ";
        left++;
    }
}

/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(1);
    BinaryTreeNode* node2 = new BinaryTreeNode(2);
    BinaryTreeNode* node3 = new BinaryTreeNode(3);
    BinaryTreeNode* node4 = new BinaryTreeNode(4);
    BinaryTreeNode* node5 = new BinaryTreeNode(5);
    BinaryTreeNode* node6 = new BinaryTreeNode(6);
    BinaryTreeNode* node7 = new BinaryTreeNode(7);
    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    topViewSequence(root);
    return 0;
}
*/