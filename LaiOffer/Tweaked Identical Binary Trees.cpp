//
//  Tweaked Identical Binary Trees.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Determine whether two given binary trees are identical assuming any number of ‘tweak’s are allowed. A tweak is defined as a swap of the children of one node in the tree.

 Examples
    5
  /    \
  3      8
 /   \
 1     4

 and

    5
  /    \
 8      3
      /   \
     1     4
 the two binary trees are tweaked identical.
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

/*
 预备知识：
 1. 假设一共有N个节点
 以此N个节点构成的二叉树的最后一层叶节点的个数为2^(log_2(n))
 以此N个节点构成的四叉树的最后一层叶节点的个数为4^(log_2(n))
 if binary tree, the number of leaf node == 2^(log_2(n)) = O(n)    nodes
 if four-branch tree, the number of leaf node == 4^(log_2(n))
 2. 所有前面的node的个数的总和，都没有最后一层node的个数多，因此我们分析tree的time complexity，往往只看最后一层node的个数。

 本题 time complexity:
 Assume that we have total level == log_2(n)
 Total number of recursion function called (= nodes in the recursion tree)
 O(4^(log_2(n))) =  O(2^(2log_2(n))) = O(2^(log_2(n^2))) = O(n^2).
 对树中的每个节点，我们都call了自身方程四次，那么类似于我们组建了一个四叉树（每个节点下面有四个分支）
 那么整个算法的时间复杂度就是这个四叉树的所有节点个数
 而当我们求树的所有节点个数时，对于bigO我们只用考虑树的最后一层节点个数即可(O(所有节点个数) == O(最后一层节点个数))
 所以，bigO = O(4^(log_2(n))) = O(n^2) 
 
 original tree有多少层，四叉树就有多少层，一共有log_2(n)
 */

bool tweaked_identical_BT(BinaryTreeNode* r1, BinaryTreeNode* r2) {
    // base case
    if(r1==NULL && r2==NULL){
        return true;
    }else if(r1==NULL || r2==NULL){
        return false;
    }else if(r1->val != r2->val){
        return false;
    }

    // outer and insider are same
    bool part1 = tweaked_identical_BT(r1->left, r2->right) && tweaked_identical_BT(r1->right, r2->left);
    // outer or insider are same
    bool part2 = tweaked_identical_BT(r1->left, r2->left) && tweaked_identical_BT(r1->right, r2->right);
    return part1 || part2;
}