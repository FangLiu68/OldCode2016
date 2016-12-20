//
//  Visible Nodes.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/5/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Binary tree, a node is visible only if its value is the largest one on the path from root to itself, print all the visible nodes
        2
      /   \
     7      1
    / \    /  \
   6  5    3   4
 all visible nodes: 2 7 3 4 
 pass down: the maximum value so far on the path
 */