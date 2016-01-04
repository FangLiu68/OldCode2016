//
//  Count Nodes in Given Range in BST.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 给BST, 和一个范围[a, b], ([2, 20]) 要求出值在这个范围内的node有多少个
 int globalcount = 0;
 public void countNode(TreeNode root, int k1, int k2,int globalcount){
 if(root==null){
 return;
 }
 if(root.key>=k1&&root.key<=k2){
 globalcount++;
 }
 if(root.key>k1){
 countNode(root.left,k1,k2,globalcount);
 }
 if(root.key<k2){
 countNode(root.right,k1,k2,globalcount);
	}
	return globalcount;
 }

 */