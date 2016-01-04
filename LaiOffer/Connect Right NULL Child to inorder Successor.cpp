//
//  Connect Right NULL Child to inorder Successor.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Connect the node whose right child is NULL to the successor node in in-order sequence.

 Solution is here:
 class Sol {
 TreeNode pre, curr;
 void connect(TreeNode root) {
 curr = root;
 pre = null;
 helper(root);
	}
	void helper(TreeNode root) {
	if (root == null) return;
	helper(root.left)
	if (pre != null && pre.right ==null) {
	pre.right = root;
 }
 pre = root;
	helper(root.right);
	}
 }

 */