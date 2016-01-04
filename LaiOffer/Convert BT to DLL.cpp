//
//  Convert BT to DLL.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place

 struct DDL {
 int val;
 DDL * pre;
 DDL * next;
	DDL(int val_): val(val_), pre(NULL), next(NULL);
 }
 TreeNode * head = NULL;
 TreeNode * tail == NULL;
 void convertTree(TreeNode * root) {
 //base case
	if(!root) {
	return;
	}
	//recursive rule
	convertTree(root->left);
	if (tail == NULL) {  // this is the first time that you reference tail
	head = root;
	} else {
 tail ->right = root;
 root->left = tail;
	}
	tail = root;
	convertTree(root->right);
 }
 // my original solution
 void postOrder(TreeNode *root, TreeNode * &head, TreeNode * &tail) {
 if (!root) {
 return;
 }
 TreeNode *head_l = NULL;
 TreeNode *tail_l = NULL;
 TreeNode *head_r = NULL;
 TreeNode *tail_r = NULL;
 postOrder(root->left, head_l, tail_l);
 postOrder(root->right, head_r, tail_r);
 if (tail_l) {
 tail_l->right = root;
 head = head_l;
 } else {
 head = root;
 }
 root->left = tail_l;
 root->right = head_r;
 if (head_r) {
 head_r->left = root;
 tail = tail_r;
 } else {
 tail = root;
 }
 }

 */