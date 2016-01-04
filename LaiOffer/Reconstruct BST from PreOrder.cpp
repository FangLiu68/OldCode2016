//
//  Reconstruct BST from PreOrder.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given preorder traversal of a BST,  re-construct the BST
    10
   /   \
  5     15
 /  \      \
 1    7    20
 index               0    1   2   3          4    5
 Pre-order    10  5  1  7  |  15 20           O(n^2)

 TreeNode* Reconstruct(vector<TreeNode*> v){
 return Helper(v, 0, INT_MIN, INT_MAX);
 }
 TreeNode* Helper(vector<TreeNode*> v, int idx, int min, int max){
 TreeNode* root = v[idx];
 if (idx+1 < v.size() && v[idx+1]->val < root->val && v[idx+1] > min) {
 root->left = Helper(v, idx+1, min, root->val);
	}
	if (idx+1 < v.size() && v[idx+1]->val > root->val && v[idx+1] < max) {
	root->right = Helper(v, idx+1, root->val, max);
	}
 }
 =====================================================================
 Node* constructTreeHelper(int pre[], int& preIndex, int key,
                          int min, int max, int size ) {
    if (preIndex >= size)   // Base case
        return NULL;
    Node* root = NULL;
    // If current element of pre[] is in range
    if (key > min && key < max) {
        root = newNode(key);
        preIndex = preIndex + 1;
        if (preIndex < size) {
            root->left = constructTreeHelper(pre, preIndex, pre[preIndex],
                                           min, key, size );
            root->right = constructTreeHelper(pre, preIndex, pre[preIndex],
                                            key, max, size );
        }
    }
    return root;
 }
 Node *constructTree (int pre[], int size) {
    int preIndex = 0;
    return constructTreeUtil(pre, &preIndex, pre[0], INT_MIN, INT_MAX, size);
 }
 

 */