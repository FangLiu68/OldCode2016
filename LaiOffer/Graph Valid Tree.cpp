//
//  Graph Valid Tree.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/30/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
 
 For Example
 Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true
 Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false;
 */

#include <vector>
#include <iostream>
using namespace std;


/*
 判断一个图是不是一棵树：
 1. 有N-1条边
 2. 边没有形成环
 
 每个节点的初始父节点都为-1，出现新edge（A，B），则统一将A的父节点设为B；若从B出发又有新edge（B, C），则更新A的父节点为C
 遍历题中所给的所有的edges，同时更新所有节点的父节点 （如果是TREE，则所有节点的最终父节点为同一个值）
      0
   /   |  \
  1    2   3
 /
 4
 
 0 1 2 3 4
 1 2 3 4 -1
 */

/*
 Union-Find Algorithm can be used to check whether an undirected graph contains cycle or not. Note that we have discussed an algorithm to detect cycle. This is another method based on Union-Find. This method assumes that graph doesn’t contain any self-loops.
 We can keeps track of the subsets in a 1D array, lets call it parent[].
 
 Let us consider the following graph:
 0
 |  \
 |    \
 1-----2
 For each edge, make subsets using both the vertices of the edge. If both the vertices are in the same subset, a cycle is found.
 
 Initially, all slots of parent array are initialized to -1 (means there is only one item in every subset).
 0   1   2
 -1 -1  -1
 Now process all edges one by one.
 
 Edge 0-1: Find the subsets in which vertices 0 and 1 are. Since they are in different subsets, we take the union of them. For taking the union, either make node 0 as parent of node 1 or vice-versa.
 
 0   1   2    <----- 1 is made parent of 0 (1 is now representative of subset {0, 1})
 1  -1  -1
 Edge 1-2: 1 is in subset 1 and 2 is in subset 2. So, take union.
 
 0   1   2    <----- 2 is made parent of 1 (2 is now representative of subset {0, 1, 2})
 1   2  -1
 Edge 0-2: 0 is in subset 2 and 2 is also in subset 2. Hence, including this edge forms a cycle.
 
 How subset of 0 is same as 2?
 0->1->2 // 1 is parent of 0 and 2 is parent of 1
 */

int find_father(vector<int> nums, int i){
    if(nums[i] == -1){
        return i;
    }
    
    // 反复寻找父节点
    return find_father(nums, nums[i]);
}

bool validTree(int n, vector<vector<int>> edges){
    vector<int> nums(n, -1);
    
    // perform union find
    for(int i = 0; i < edges.size(); ++i){
        int x = find_father(nums, edges[i][0]);
        int y = find_father(nums, edges[i][1]);
        
        // if two vertices happen to be in the same set
        // then there is a cycle
        if(x == y){
            return false;
        }
        
        // union
        nums[x] = y;
    }
    
    return edges.size() == n-1;
}