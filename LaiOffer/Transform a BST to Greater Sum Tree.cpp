//
//  Transform a BST to Greater Sum Tree.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a BST, change each node’s value, such that its value is equal to the sum of all nodes greater than itself.


 based on the BST, to do the sum based on descending array.
 void updateBST(TreeNode* root, int& sum) {
 if (root == NULL) {
 return;
 }
            updateBST(root -> rchild, sum);
 sum+=root->value;
 root->value = sum - root->value;
 updateBST(root-> lchild, sum);
 }

 */