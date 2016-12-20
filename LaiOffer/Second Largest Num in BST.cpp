//
//  Second Largest Num in BST.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/10/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Find the second largest (or the second node in in-order traversal) node in BST
 */

#include "BinaryTree.h"

/* 
 find the largest, then find the largest smaller
 inorder traversal, mark the parent node when move to next, when we find the largest node, its previous node is the second largest node
*/