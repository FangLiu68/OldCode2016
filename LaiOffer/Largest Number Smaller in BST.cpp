//
//  Largest Number Smaller in BST.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 In a binary search tree, find the node containing the largest number smaller than the given target number.
 Examples
    5
  /    \
 2      11
      /    \
     6     14
 largest number smaller than 1 is null
 largest number smaller than 10 is 6
 largest number smaller than 6 is 5
 */

#include "Header.h"

// 题目找比target小的数，所以当root值较大时，是不用记录root当前值的，只用访问左孩子就行
// 只有当root值较targe小时，root可能是潜在结果，这时候就需要记录root值
int largestSmaller(BinaryTreeNode* root, int target){
    if(root == NULL){
        return INT_MIN;
    }
    BinaryTreeNode* res = NULL;
    while(root){
        if(root->val >= target){
            root = root->left;
        }else{
            res = root;
            root = root->right;
        }
    }
    if(res == NULL){
        return INT_MIN;
    }else{
        return res->val;
    }
}

/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(5);
    BinaryTreeNode* node1 = new BinaryTreeNode(2);
    BinaryTreeNode* node2 = new BinaryTreeNode(11);
    BinaryTreeNode* node3 = new BinaryTreeNode(6);
    BinaryTreeNode* node4 = new BinaryTreeNode(14);

    root->left = node1;
    root->right = node2;
    node2->left = node3;
    node2->right = node4;
    int res = largestSmaller(root, 10);
    if(res==INT_MIN) cout << "NULL" << endl;
    else cout << res << endl;
    return 0;
}*/