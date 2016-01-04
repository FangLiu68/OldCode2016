//
//  Smallest Num Larger in BST.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include "Header.h"

/*
 In a binary search tree, find the node containing the smallest number larger than the given target number.
 Examples
      5
    /    \
    2      11
        /    \
        6     14
 smallest number larger than 14 is null
 smallest number larger than 10 is 11
 smallest number larger than 5 is 6
 */

// 和上一题类似。找较targe大的值，那么当root值较小时不用记录
int smallestLarger(BinaryTreeNode* root, int target){
    if(root == NULL){
        return INT_MAX;
    }
    BinaryTreeNode* res = NULL;
    while(root){
        if(root->val <= target){
            root = root->right;
        }else{
            res = root;
            root = root->left;
        }
    }
    if(res){
        return res->val;
    }else{
        return INT_MAX;
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
    int res = smallestLarger(root, 5);
    cout << res << endl;
    return 0;
}
*/
