//
//  Is Completed Binary Tree.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/8/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Check if a given binary tree is completed. A complete binary tree is one in which every level of the binary tree is completely filled except possibly the last level. Furthermore, all nodes are as far left as possible.

 Examples

        5
     /    \
    3      8
  /   \
 1      4
 is completed.

        5
     /    \
    3       8
  /   \       \
 1      4      11
 is not completed.

 Corner Cases
 What if the binary tree is null? Return true in this case.
 How is the binary tree represented?

 We use the level order traversal sequence with a special symbol "#" denoting the null node.

 For Example:
 The sequence [1, 2, 3, #, #, 4] represents the following binary tree:
        1
      /   \
     2     3
          /
        4
 */

#include "BinaryTree.h"
#include <iostream>
#include <queue>
using namespace std;

bool is_completed_BT(BinaryTreeNode* root){
    if(root == NULL){
        return true;
    }
    queue<BinaryTreeNode*> q;
    bool flag = false;
    q.push(root);

    // run BFS
    // if the flag is true, there should not be any child nodes afterwords
    while(!q.empty()){
        BinaryTreeNode* cur = q.front();
        q.pop();
        if(cur->left == NULL){
            // if there is no left child, then set flag = true
            // we should not see nodes later
            flag = true;
        }else if(flag){
            // see "cur" after setting flag to true, BT is not completed
            return false;
        }else{
            q.push(cur->left);
        }
        
        if(cur->right == NULL){
            // if there is no right child, then set flag = true
            // we should not see nodes later
            flag = true;
        }else if(flag){
            return false;
        }else{
            q.push(cur->right);
        }
    }
    return true;
}



