//
//  Lowest Common Ancestor in K nary Tree.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/2/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Find the lowest common ancestor in k-nary tree
 
 k-nary tree: For each node, it has at most k children node.
 */

#include <vector>
#include <iostream>
using namespace std;

/*
struct KnaryTreeNode{
    vector<KnaryTreeNode*> children;
    int val;
    KnaryTreeNode node(int value) : 
};*/

/*
 1. Binary Tree
    a. if the current node == a or b, then we return a or b
    b. if we find both a and bo from my left/right subtree, then we return c=current node
 
 2. k-nary tree
    a. if the current node = a or b or c or d ... then we return current node (either a or b or c ...)
    b. if we find more than 1 node among the list of k nodes from the subtrees of the current node, then we return the current node
 */


