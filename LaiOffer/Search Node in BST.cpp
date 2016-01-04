//
//  Search Node in BST.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
    5
  /    \
 2      11
       /   \
      6    14
 */
#include "Header.h"


BinaryTreeNode* search_in_BSTI(BinaryTreeNode* root, int target){
    if(root == NULL){
        return NULL;
    }
    BinaryTreeNode* cur = root;
    while(cur){
        if(cur->val < target){
            cur = cur->right;
        }else if(cur->val > target){
            cur = cur->left;
        }else{
            return cur;
        }
    }
    return NULL;
}

// search a node in BST
BinaryTreeNode* search_in_BSTII(BinaryTreeNode* root, int target){
    if(root == NULL) return NULL;
    if(root->val == target)
        return root;
    if(target < root->val)
        return search_in_BSTII(root->left, target);
    else
        return search_in_BSTII(root->right, target);
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
    BinaryTreeNode* res = search_in_BST(root, 9);
    if(res==NULL) cout << "NULL" << endl;
    else cout << res->val << endl;
    return 0;
}*/