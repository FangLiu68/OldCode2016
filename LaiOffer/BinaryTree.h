//
//  BinaryTree.h
//  LaiOffer
//
//  Created by Fang Liu on 2/22/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#ifndef LaiOffer_BinaryTree_h
#define LaiOffer_BinaryTree_h

#include <iostream>
#include <vector>
using namespace std;
/*
 Binary Tree:
 A tree data structure in which each node has at most two children.
 
 Full Binary Tree:
 A binary tree where every node other than the leaves has two children.
 
 Perfect Binary Tree:
 A full binary tree where all leaves have the same depth.
 
 Complete Binary Tree:
 A binary tree in which every level, except possibly the last level, is completely filled, and all nodes are 
 as far left as possible.
 
 Balanced binary tree:
 A binary tree in which the depth of the left and right subtrees of every node differ by 1 or less
 
 Binary Search Tree:
 A node-based binary tree data structure where each node has a comparable key (and an associated value) and satisfies the restriction that the key in any node is larger than the keys in all nodes in that node's left subtree and smaller than the keys in all nodes in that node's right sub-tree.
 - it is a binary tree.
 - left child is less than parent, which is less than right child.
 
 Balanced Binary Search Tree:
 A binary search tree that has the minimum possible maximum depth for the leaf nodes.
 
 AVL Tree (special instance of balanced BST): 
 for each node, the depth of left subtree differs the depth of the right subtree by at most 1.
 */

/*
 Traverse Tree
 Pre-order:  current node  -> left children  -> right children
 In-order:   left children -> current node   -> right children
 Post-order: left children -> right children -> current node

 */
struct BinaryTreeNode{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int v) : val(v), left(NULL), right(NULL){}
};

struct TreeNode1{
    int val;
    TreeNode1* left;
    TreeNode1* right;
    TreeNode1* parent;
    TreeNode1(int v) : left(NULL), right(NULL), parent(NULL){}
};

struct TreeNode2{
    int val;
    TreeNode2* left;
    TreeNode2* right;
    int numLeftElements;
};

vector<int> inOrder_iter(BinaryTreeNode* root);

int get_leftSubtreeNodes(TreeNode2* root);

#endif
