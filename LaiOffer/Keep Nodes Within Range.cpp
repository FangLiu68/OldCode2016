//
//  Get Keys in BST in Given Range.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/9/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/* Get the list of keys in a given binary search tree in a given range [min, max] in ascending order, both min and max are inclusive.

 Examples
         5
      /    \
    3        8
  /   \        \
 1     4        11
 get the keys in [2, 5] in ascending order, result is  [3, 4, 5]

 Corner Cases
 What if there are no keys in the given range? Return an empty list in this case.
*/

#include "Header.h"

/*
 所有的tree recursion问题，大多数情况下，base case都是leaf node下面的NULL
 所以，tree recursion问题的high level过程分为两步：
 1. 从root一直往下压栈，一直压到base case: root==NULL的情况（绝大多数）
 2. 从最下面开始往上反弹，根据
    (1) what do you want to get from your left/right child?
    (2) what do you have to do in your current layer?
    (3) what do you have to report to your parent?
    这三个方向来定义recursion rule, 从而完成题意。
    绝大部分的题都只考虑这第二步的过程，第一步的压栈过程recursion方程本身会自己完成，我们不用做什么事情。

 对于Binary Search Tree类型的题，有一点不同。第一步的压栈过程，我们也要考虑。
 由于对于BST的任意一个节点，他的所有左孩子的值都小于他自身的值，并且他自身的值大于他所有右孩子的值。
 所以对于BST的题写recursion rule的时候，前面要加一些限制条件，例如  根据已给值的关系判断什么时候访问左孩子（第一步压栈左孩子）
 */

/* 注意，这里的逻辑关系
    我们按照in order顺序遍历，首先push到res中的肯定是可选择区域里值最小
    注意，都是if, 没有else if
 */
void helper(BinaryTreeNode* root, int min, int max, vector<int> &res){
    // base case
    if(root == NULL) return;

    if(root->val > min){
        helper(root->left, min, max, res);
    }

    if(root->val >= min && root->val <= max){
        res.push_back(root->val);
    }

    if(root->val < max){
        helper(root->right, min, max, res);
    }
}

vector<int> keepNodes_within_range(BinaryTreeNode* root, int min, int max){
    vector<int> res;
    if(root == NULL) return res;
    helper(root, min, max, res);
    return res;
}

/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(5);
    BinaryTreeNode* left1 = new BinaryTreeNode(1);
    BinaryTreeNode* right1 = new BinaryTreeNode(9);
    BinaryTreeNode* left12 = new BinaryTreeNode(3);
    BinaryTreeNode* right11 = new BinaryTreeNode(8);
    BinaryTreeNode* right12 = new BinaryTreeNode(11);
    root->left = left1;
    root->right = right1;
    left1->right = left12;
    right1->left = right11;
    right1->right = right12;
    printRange(root, 2, 8);
    return 0;
}*/