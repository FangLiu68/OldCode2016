//
//  Height of Binary Tree.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/6/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Get height of a binary tree

// TOPIC: use recursion to return values needed in a bottom-up way in binary tree
/*
            4
      3          6
  1      2    5      7

 对待任意一个recursion的题，都首先想这么三个步骤：
 1. what do you expect from your left and right child?
 2. what do you want to do in the current layer?
 3. what do you want to report to your parent?

 1 3经常是相同的

 所有的tree，recursion的时候都是首先DFS一直向下，触底，到最后一层。这是不断压栈的过程。
 然后，再从最后一层往上反弹，不断返回，直到第一层root。
 Base case(generally)：NULL pointer under the leaf node

 我们写recursion的时候，function的第一行，都首先写的是base case
 好了，我们已经知道叶子下面的base case是什么了，然后我们就从最后一层的叶子看recursion rule的特点，看应该怎么写

 以getHeight为例。当前节点的height，就是左子树的height和右子树的height相比较后得出的最大值，再加1.
 那么对应上面所列出的每个recursion问题的三个步骤
 1. what do you expect from your left and right child?
 需要知道left subtree's height && right subtree's height
 2. what do you want to do in the current layer?
 current layer的此时的node，我们想要知道它的height，那么就要对上一步所得到的结果+1
 3. what do you want to report to your parent?
 经常表现为你写的function的最后一行的return value。我们想要return的就是当前layer的height，那么直接return上一步的结果就可以
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

// 每个点都要先找leftchild height, then right child height, then get the current node's height 是postOrder DFS
// 一共有N个node，那么recursion一直触底之后，再从底往上一步步挪，每个node都访问到了
// O(N) runtime, O(logN) space 因为不断压栈的过程
int getHeight(BinaryTreeNode* root){
    // base case
    if(root == NULL) return 0;

    // what do you want from your left and right child
    int left_height = getHeight(root->left); // breaking point.除非拿到结果（触底到最后一层），否则是不会返回的
    int right_height = getHeight(root->right);

    return max(left_height, right_height) + 1; // what do you want to report to your parent
}

// practice: how many nodes in the binary tree?
// O(N) runtime, O(logN) space
int getCountOfNodes(BinaryTreeNode* root){
    // base case
    if(root == NULL) return 0;

    int left_cost = getCountOfNodes(root->left);
    int right_cost = getCountOfNodes(root->right);

    return (left_cost + right_cost) + 1;
}
