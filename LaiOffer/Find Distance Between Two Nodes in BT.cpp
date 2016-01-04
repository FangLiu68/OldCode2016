//
//  Find Distance Between Two Nodes in BT.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Find distance between two given keys of a Binary Tree
 Find the distance between two nodes in a binary tree, no parent pointers are given. Distance between two nodes is the minimum number of edges to be traversed to reach one node from other.

 public int distance(TreeNode root, TreeNode node1, TreeNode node2) {
 }
 public TreeNode LCA(TreeNode root, TreeNode node1, TreeNode node2) {
	if (root == null) {
 return null;
	}
	if (root == node1 || root == node2) {
 return root;
	}
	TreeNode left = LCA(root.left, node1, node2);
	TreeNode right = LCA(root.right, node1, node2);
	if (left != null && right != null) {
 return root;
	}
	return left == null ? right : left;
 }

 // BFS
 public int getLevel(TreeNode root, TreeNode node2) {
	if (root == null) {
 // to think about
	}
	int level = 0;
	Queue<TreeNode> queue = new LinkedList<TreeNode>();
	queue.offer(root);
	while (!queue.isEmptry()) {
 int size = queue.size();
 level++; // the current level
 for (int i = 0; i < size; i++) {
 TreeNode current = queue.poll();
 if (current == node2) {
 return level;
 }
 if (current.left != null) 	queue.offer(current.left);
 if (current.left != null)   queue.offer(current.right);
	}
 }
	return level;
 }


 */