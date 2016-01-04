//
//  Is Cousins in BT.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Check if two nodes are cousins in a Binary Tree
 Given the binary Tree and the two nodes say ‘a’ and ‘b’, determine whether the two nodes are cousins of each other or not.
 Two nodes are cousins of each other if they are at same level and have different parents.
 Example
    6
   /   \
  3     5
 / \   / \
 7   8 1   3
 7 and 1, result is TRUE.
 3 and 5, result is FALSE.
 7 and 5, result is FALSE.
 Step1: Find the lowest common ancestor (node x),    and a and b are both children of x then return false;
 Step2: Find the levels of a and b, if then share the same level number → return true; otherwise return false;
 
 Public boolean isCousin(TreeNode root, TreeNode n1, TreeNode n2) {
    if (root == null) {
        return false;
	}
	TreeNode LCA = findLCA(root, n1, n2);
    if (LCA.left == n1 && LCA.right == n2 ||
        LCA.right == n1 && LCA.left == n2) {               //   LCA        LCA
        return false;      //  n1 n2  ||   n2 n1
	}
	int levelN1 = getHeight(root, n1, 0);
	int levelN2 = getHeight(root, n2, 0);
	if (levelN1 != levelN2) {
        return false;
	}
	return true;
 }

 private TreeNode findLCA(TreeNode root, TreeNode n1, TreeNode n2) {
    if (root == null) {
        return null;
	}
	if (root == n1 || root == n2) {
        return root;
	}
	TreeNode leftRes = findLCA(root.left, n1, n2);
	TreeNode rightRes = findLCA(root.right, n1, n2);
	if (leftRes != null && rightRes != null) {
        return root;
	}
	return leftRes == null ? rightRes : leftRes;
 }

 private int getHeight(TreeNode root, TreeNode target, int level) {
    if (root.val == target.val) {
        return level;
    } else if (root.val < target.val) {
        return getHeight(root.right, target, level + 1);
    } else {
        return getHeight(root.left, target, level + 1);
    }
 }
 

 */