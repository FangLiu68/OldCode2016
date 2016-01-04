//
//  Matrix Water.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an N*N matrix，each element represents the elevation (height) of the field in that position (elevation). The water can only flow from a higher position to a lower or evenly high position.   The top and left border of the matrix is pacific and the right and bottom of the matrix is atlantic.  Try to find all the elements in the matrix from which the water can arrive  both pacific and atlantic.
 xxxxx
 XXXXX
 XX3WX
 X12WX
 X1WWZ
 Naive Solution:   use BFS or DFS  and run it from each [x][y] →    N^2  * N^2 == N^4
 Better idea?
 // idea:  for each node on red border, do BFS to mark all the nodes that can flow to the border;
 for each node on blue border, do BFS to mark all nodes that can flow to the border;
 go over the nodes inner to collect those who can flow to both borders;
 2n red elements   2n * n^2
 2n blue elements  2n * n^2    → O(n^3)
 Even better idea?
 O(N^2)
 After class question: Implement it please

 */