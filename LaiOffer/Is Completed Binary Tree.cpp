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

/*
 逐层遍历
 用queue存储节点，从左到右一个一个判断
 对于每一个节点，如果左孩子为NULL，就不应该有右孩子；在左孩子为NULL的同时如果有右孩子，则not complete tree
 我们用bool tag标志此时的左孩子是否为NULL
 */
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
        }else if(flag){ // 在flag==true的情况下cur->left != NULL
            // see "cur" after setting flag to true, BT is not completed
            return false;
        }else{ // cur->left!=NULL && flag==false
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



