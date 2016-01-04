//
//  All Paths Sum to Target in BT.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a binary tree, print all paths that can start from any node and end at any node that sum to a target number.   e.g.   target = 22  then return  (1) {22}, and (2) {12, 10}
 the value of the node can be any arbitrary integer. {negative, zero, positive}

 vector<vector<Node*>>  FindPaths(Node* root, int target, int sum, vector<Node*> prefix) {
 20   8   12    sum = 40
 root     cur
 }
 M1:  starting from each node,   perform DFS
 20      8       4    10   12  14   22
 20  (n) N
   /                    \
 8 (n/2) 22 (n/2)           N
 if the tree is balanced O(nlogn)
 if not O(n^2)
 M2:       20  8  12
 12
 8 12
        20 8 12
 method 2:
 import java.util.*;
 public class findPath {
	static ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
	public static void findPath(TreeNode m, int target) {
	ArrayList<Integer> s = new ArrayList<Integer>();
	recursion(s, m, target);
	print(result);
 }
 public static void print(ArrayList<ArrayList<Integer>> result) {
	for (ArrayList<Integer> one : result) {
 for (Integer value : one) {
 System.out.print(value);
	}
	System.out.println("");
 }
 }
 public static void recursion(ArrayList<Integer> s, TreeNode m, int target) {
 if (m.left == null && m.right == null) {
 s.add(m.val);
 calculate(new ArrayList<Integer>(s), target);
 s.remove(s.size() - 1);
 return;
 }
 if (m != null) {
 s.add(m.val);
 recursion(s, m.left, target);
 recursion(s, m.right, target);
 s.remove(s.size() - 1);
 }
 }
 public static void calculate(ArrayList<Integer> s, int target) {
 int sum = 0;
 ArrayList<Integer> temp = new ArrayList<Integer>();
 int size = s.size() - 1;
 while (size >= 0) {
 sum += s.get(size);
 temp.add(s.get(size--));
 if (sum == target) {
 result.add(new ArrayList<Integer>(temp));
 // print(result);
 }
 }
 }
 }

 */