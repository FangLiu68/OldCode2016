//
//  Wether Edges could Form a Tree.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 There are n nodes numbered from 0 to n-1 and a set of edges (undirected).
 Determine whether the edges form a valid tree (no cycles and fully connected).
 For example:
	1. n = 5, edge set = {{0,1}, {0,2}, {2,3}, {2,4}} Output: true
	2. n = 3, edge set = {{0,1}, {1,2}, {0,2}} Result: false
 <key= startNode , value =endNode  which is a  ArrayList<Node>>;
 0
      1          2← start
                3    4
 Example 1:  table:  4 edges  → 8 key value pair to be inserted into the hash_table.
 <0,  <1 2>>
 <1, <0>>
 start → <2, <0,3,4>>
 <3, <2>>
 <4, <2>>
 DFS:
	1. expande 2, generate 0 (0’s parent is 2) → expand 0,generate 1 (1’s parent is 0)
	2.                   generate 3 (3’ parent is 2)  → expand 3, generate nothing.
	3.                   generate 4 (4’ parent is 2) → expand 4 , generate nothing.


 Solution:
 Step1: Use a hashmap to use a node as key and all nodes it connects as value;
 Step2: Use DFS to expand a  node, and mark as visited; if we find a node that is to be expanded but marked as visited, then we find a cycle, false;
 expand 2  generate 1 and 4, but when you expand 1 you may generate 2??????
 Note:
 when you generate 1, be careful, we need to mark 2 as 1’s parent node, which generated 1 before. So that, when expanding 1, we will avoid generating 2, which is 1’s parent node.

 class Pair {
 int a, b;
 Pair(int x, int y) {a = x; b = y;}
 }
 Class Solution {
 int cnt; //expanded nodes
 boolean hasCycle;
 boolean isTree(List<Pair> edges, int n) {
 HashMap<Integer, ArrayList<Integer>> map = new HashMap<Integer, ArrayList<Integer>>();
 for (Pair p : edges) {
 if (!map.containsKey(p.a))
 map.put(p.a, new ArrayList<Integer>());
 map.get(p.a).add(p.b);
 if (!map.containskey(p.b))
 map.put(p.b, new ArrayLis<Integer>());
 map.get(p.b).add(p.a);
 }
 int start = edges.get(0).a;
 HashSet<Integer> visited = new HashSet<Integer>();
 dfs(start, null, visited, map);
 if (hasCycle || cnt < n) return false;
 return true;
	}
	void dfs(Integer curr, Integer parent, HashSet<Integer> visited, HashMap<Integer, ArrayList<Integer>> map) {
	if (visited.contains(curr))
	return;
	cnt++;
	visited.add(curr);
 for (Integer next : map.get(curr)) {
 if (next != parent) {
 if (visisted.contains(next)) {
 hasCycle = true;
 return;
 }
 dfs(next, curr, visited, map);
 }
 }
	}
 }

 */