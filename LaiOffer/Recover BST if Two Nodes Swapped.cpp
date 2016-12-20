//
//  Recover BST if Two Nodes Swapped.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/10/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Recover Binary Search Tree, two nodes are swapped - in sorted array?
 
              8
        /           \
       4              15
     /     \         /     \
    1       11     9         20
            /      /  \     /   \
           5     8.5   7    17  25
 [1, 4, 5, 7, 8, 8.5, 9, 11, 15, 17, 20, 25]
 [1, 4, 5,11, 8, 8.5, 9, 7, 15, 17, 20, 25]
 
 find 11:  > its right element.
 find 7:   < its left element.
 
 step 1: find the two nodes:
	do inorder traversal, record the previous node in the inorder sequence.
 step 2: swap the value of the two nodes.
 */