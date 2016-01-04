//
//  Delete Node with Cost larger than K.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a binary tree, the path cost from the root node to each leaf node is defined to be the number of levels that the leaf is on.  For example, the node 5 has its path cost to be 3, and node 8 has its path cost to be 4.   Try to delete all nodes in the tree that have no paths whose cost is >= k that go through it.
 Input:    k = 4
              1 (level =1)
           /      \
         2          3
      /     \         \
    4         5        6
  /  \                  /
 7   8               9

 Output:
              1
           /      \
         2          3
      /     \         \
    4         5        6
  /  \                 /
 7   8               9


 public TreeNode delete(TreeNode root)
 {
	int height = deleteHelper(current, 1, k);
	return height < k ? null : root;
 }
 private int deleteHelper(TreeNode current, int height, int k)
 {
 if(current == null)
 return height;
	int leftHeight = deleteHelper(current.left, height + 1, k);
	int rightHeight = deleteHepler(current.right, height + 1, k);
	if(leftHeight < k)
	current.left == null;
	if(rightHeight < k)
	current.right = null;
 return Math.max(leftHeight, rightHeight);
 }


 00 int DeleteNode(Node* root, int level) {
 01 if (root == NULL) {
 02 return level;
 03 }
 04 int height = max(DeleteNode(root->left, level+1),
                       DeleteNode(root->right, level+1));
 05 if (height < k) {
 06 delete root;
 07 root = NULL;
 08 }
 09 return height;
 10 }

 */