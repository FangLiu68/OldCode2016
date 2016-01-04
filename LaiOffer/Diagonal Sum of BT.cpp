//
//  Diagonal Sum of BT.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Consider lines of slope -1 passing between nodes (dotted lines in below diagram). Diagonal sum in a binary tree is sum of all node’s data lying through these lines. Given a Binary Tree, print all diagonal sums. For the following input tree, output should be 11, 14, 5.
 height, go to left, + 1
 go to right
 List<Integer> result = new ArrayList<>();
 for (each node)
 {
	if height > result.size();
	add it
	else result.set(height, result. get(height) + current);
 }
 return result;

 public List<Integer> sum(TreeNode root){
 List<Integer> result = new ArrayList<>();
 if(root == null)
 return result;
 sumHelper(root, result, 1);
 return result;
 }
 public void sumHelper(TreeNode current, List<Integer> result, int height) {
	if(height > result.size())
	result.add(current.value);

	else
 result.set(height, result.get(height) + current.value);
 sumHelper(current.left, result, height + 1);
 sumHelper(current.right, result, height);
 }

 */