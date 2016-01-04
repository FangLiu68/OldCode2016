//
//  Shortest Path in Gym.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/13/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a gym with k equipments, and some obstacles.  Let’s say we bought a chair and wanted to put this chair into the gym such that  the sum of the shortest path cost from the chair to the k equipments is minimal.
 */

/*
 N X N Gym   → N^2 states       O(k*   N^2 lgN)    = I need to run k times Dijskstra’s algorithm
 n^2log(n^2) 图上所有的cell全部run完dijskstra需要的时间
 一共n^2个元素，都Push到heap里，heap需要log(n^2)
 k equipments
 class Cell {
	int x;
	int y;
	vector<int> path_cost;
 }

 432 1/5/3=9e1xxxxxxx
 xxxxxxxe2xxxx
 xxxxe3xxxxxxx
 35 33xxxxxxxxxx

 Better solution: Run Dijkstra’s algorithm from each equipment  e_i,

 Worse solution:
 N^2  times of DIjstra      O(N^2  *   N^2 lgN)

 best first search is the only general algorithm to find the shortest path in any arbitrary graph.
 Special case, in 4-connected grids with edge cost all equal to one, then you can use BFS (Breath-first search) to find a shortest path (special case).
 
 

 */