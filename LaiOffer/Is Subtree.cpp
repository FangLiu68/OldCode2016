//
//  Is Subtree.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include "Header.h"

/*
 Given two binary trees (with unique letters), check if the first tree is subtree of the second one. A subtree of a tree T is a tree S consisting of a node in T and all of its descendants in T.
    Tree1
          x
        /    \
      a       b
       \
        c

        Tree2
              z
            /   \
          x      e
        /    \     \
      a       b      k
       \
        c
 */

// Method 1
// 判断两个tree是否完全相同
bool IsSame(BinaryTreeNode* r1, BinaryTreeNode* r2) {
    if (r1 == NULL && r2 == NULL) {
        return true;
    }
    if (r1 == NULL || r2 == NULL) {
        return false;
    }
    return r1->val == r2->val && IsSame(r1->left, r2->left) && IsSame(r1->right, r2->right) ;
}

// 在root的tree中找到指向target的节点，否则返回NULL
BinaryTreeNode* Find(BinaryTreeNode* root, BinaryTreeNode* target) {
    if (root == NULL) {
        return NULL;
    }
    if (root == target) {
        return root;
    }
    BinaryTreeNode* left = Find(root->left, target);
    BinaryTreeNode* right = Find(root->right, target);
    return left ? left : right ;
}

bool IsSubTree(BinaryTreeNode* root, BinaryTreeNode* target) {
    if(root == NULL){
        return false;
    }else if(target == NULL){
        return true;
    }
    BinaryTreeNode* root2 = Find(root, target);
    if (root2 == NULL) {
        return false;
    }
    return IsSame(root, root2);
}


//==============================
// Method 2
bool isSameTree(BinaryTreeNode* root1, BinaryTreeNode* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }else if(root1 == NULL || root2 == NULL){
        return false;
    }

    if(root1->val != root2->val){
        return false;
    }

    bool left = isSameTree(root1->left, root2->left);
    bool right = isSameTree(root1->right, root2->right);

    return left && right;
}

bool Subtree(BinaryTreeNode* big, BinaryTreeNode* small){
    if(big == NULL){
        return false; // big tree empty and subtree still not found
    }

    if(big->val == small->val){
        if(isSameTree(big, small)){
            return true;
        }
    }

    bool left = Subtree(big->left, small);
    bool right = Subtree(big->right, small);

    return left || right;
}

bool isSubtree(BinaryTreeNode* root1, BinaryTreeNode* root2){
    if(root2 == NULL){
        return true;
    }
    return Subtree(root1, root2);
}

