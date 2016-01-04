//
//  Kth Smallest in BST.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/17/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// find k-th smallest node in binary search tree

#include "Header.h"

/*
 Method 1: inorder traversal, O(K) runtime
 Method 2: 假如每个node都包含一个(他有多少左孩子)的值，那么可以利用BST的性质，O(logN)runtime 得出结果
 */

TreeNode2* KthInBST(TreeNode2* root, int k){
    if(root == NULL) return NULL;

    // left nodes = k - 1, so the kth is the root
    if(root->numLeftElements == k-1){
        return root;
    }
    // left > k -1, kth is in left subtree
    else if(root->numLeftElements > k-1){
        return KthInBST(root->left, k);
    }
    // in right subtree, and we must decrease k by  NumLeft  + 1(root)
    else{
        return KthInBST(root->right, k - root->numLeftElements - 1);
    }
}

//===========================================================
// 上面做法是修改tree structer，下面是先求出左子树的节点个数，再计算

/*
 For the first approach, at any point of time we would be discarding half of the nodes, so ideally it should be O(logN). However this is not the case. We are traversing the entire left side of the tree for every node to get the number of node s in left sub tree. Considering tree as balanced tree too, we would be traversing N/2 nodes for logN times, hence complexity of this solution is NlogN 
  */
int getSizeOfTree(BinaryTreeNode* root){
    if(root == NULL) return 0;

    return getSizeOfTree(root->left) + getSizeOfTree(root->right) + 1;
}

int kthSmallest(BinaryTreeNode* root, int k) {
    if(root == NULL) return 0;

    int leftNodes = getSizeOfTree(root->left);

    if(leftNodes == k-1){
        return root->val;
    }else if(leftNodes > k-1){
        return kthSmallest(root->left, k);
    }else{
        return kthSmallest(root->right, k - leftNodes - 1);
    }
}

//========================================================
// inOrder traversal
// In second approach, we will traversing at most K nodes hence the complexity will be O(K)
void helper(BinaryTreeNode* root, int k, int& n, int& res){
    if(root == NULL) return;

    helper(root->left, k, n, res);
    n++;
    if(k == n){
        res = root->val;
        return;
    }
    helper(root->right, k, n, res);
}

int kthSmallest_inOrder(BinaryTreeNode* root, int k) {
    if(root == NULL){
        return 0;
    }
    int res = 0;
    int n = 0;
    helper(root, k, n, res);
    return res;
}

//========================================
// 和上面的做法一样  稍微差别
int helper(BinaryTreeNode* root, int k, int& n){
    if(root == NULL) return 0;

    int kthElem = helper(root->left, k, n);
    if(kthElem != 0){
        return kthElem;
    }
    
    if(++n == k){
        return root->val;
    }else{
        return helper(root->right, k, n);
    }
}

int kthSmallest_inOrderI(BinaryTreeNode* root, int k) {
    if(root == NULL){
        return 0;
    }
    int n = 0;
    return helper(root, k, n);
}

