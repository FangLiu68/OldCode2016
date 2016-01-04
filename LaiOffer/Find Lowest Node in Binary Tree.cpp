//
//  Find Lowest Node in Binary Tree.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 给一个binary tree, 要求找出最底的node(就是树的最大高度的那个点)
 10
 5 15
 2 7 12  20
       1       11
       10.1
 public static int maxval =0;
 public static TreeNode res = null;
 public TreeNode lowest(TreeNode root){
	int curval =1;
 lowestNode(root,curval);
 return res;
 }
 public void lowestNode(TreeNode root, int curval){
 if(root==null){
 return;
 }
 if(curval>maxval){
 maxval = curval;
 res = root;
 }
 lowestNode(root.left,curval+1);
 lowestNode(root.right,curval+1);
 }
 

 */