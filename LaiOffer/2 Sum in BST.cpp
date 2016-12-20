//
//  2 Sum in BST.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/10/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Looking at the sorted sequence provided by the BST...
 Comparing BST with Sorted Array
 inorder traversal of BST is a sorted sequence(array)
 find in BST with binary search
 insert will be different
 
 Remember to utilize the Iterator or parent pointer for ease of generating the sequenced view(get the next node in inorder sequence) - If you think maintaining the parent pointer will it easy, ask for it. In real world, when we use the tree, usually we will store the parent pointer.
 
 k largest numbers smaller than target
 k smallest numbers larger than target
 */

//======================================================
// two sum problem in Binary Search Tree

#include "BinaryTree.h"
#include <iostream>
using namespace std;

/*
 Naive Solution:
 for each node n in the tree:
 find (target - n) in the tree
 O(nlogn)
 
 ===========================================
 Suppose we have the parent pointer:
 
 TreeNode l = smallest(root);
 TreeNode r = largest(root);
 while (l < r) {
	if (l + r == target)  return true;
	else if (l + r < target) {
 l = nextInroder(l);
 } else {
	r = previousInorder(r);
 }
 }
 return false;
 O(n)
 =============================================
 Suppose we don’t have the parent pointer:
 
 Method 1: we need the parent pointer. → we can traverse the tree and record each node’s parent node in a HashMap<TreeNode, TreeNode> → extra space.
 
 Method 2:
 Question’: How to implement an inorder iterator of a binary tree, the TreeNode class does not record the parent pointer.
 Question’’: How to do inorder traversal without recursion.
 assuming balanced binary search tree, space = O(logn)
 */



