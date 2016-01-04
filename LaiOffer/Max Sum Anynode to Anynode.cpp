//
//  Max Sum Anynode to Anynode.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/1/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include "BinaryTree.h"
#include <iostream>
using namespace std;

/*
 Given a binary tree in which each node contains an integer number. Find the maximum possible sum from any node to any node (the start node and the end node can be the same).

 Assumptions
 ​The root of the given binary tree is not null
 Examples
 -1

 /    \

 2      11

 /    \

 6    -14

 one example of paths could be -14 -> 11 -> -1 -> 2

 another example could be the node 11 itself

 The maximum path sum in the above binary tree is 6 + 11 + (-1) + 2 = 18

 How is the binary tree represented?

 We use the level order traversal sequence with a special symbol "#" denoting the null node.

 For Example:

 The sequence [1, 2, 3, #, #, 4] represents the following binary tree:

 1

 /   \

 2     3

 /
 
 4
 */

/*
 Given a binary tree, find the maximum path sum. The path may start and end at any node in the tree

 上面一题的路径必须从叶子到叶子，这一题的路径可以从任意节点出发，任意节点结束
 */

/*
 1. what do you expect from your left and right child?
 max path cost from left subtree (1)
 max path cost from right subtree (2)

 2. what do you want to do in the current layer?
 算出从下往上走到current layer的当前节点的cur_path_sum是多少
 只有当(1)>0，才将(1)的结果添加到cur_path_sum中，
 同样，只有当(2)>0，才将(2)的结果添加到cur_path_sum中
 而且，由于我们所要的最终的path可以从任意节点开始，任意节点结束，那么只要cur_sum > path_sum，就更新path_sum

 3. what do you want to report to your parent?
 只有当max((1),(2))是正数时，我们才认为这个sum是有用的，才返回上一层父节点，添加到父节点的cur_sum中
 否则，只返回当前节点的value

 任意node到任意node，当前层要检查：从下往上走到当前节点为止，有没有可能找到cur_sum最大的路径，同时跟max_sum比较。我们要招的是一个完整路径，所以要把左右两边的sub tree的值都加上。
 */

int find_max_sum_from_node_to_node(BinaryTreeNode* root, int &path_sum){
    if(root == NULL) return 0; // base case

    int left_cost = find_max_sum_from_node_to_node(root->left, path_sum);
    int right_cost = find_max_sum_from_node_to_node(root->right, path_sum);

    // 在当前层检查的是：以当前层root为根节点，在它下面的所有路径中所组成的最大anynode到anynode的max sum是多少
    int left_val = left_cost>0 ? left_cost : 0;
    int right_val = right_cost>0 ? right_cost : 0;
    int cur_val = left_val + right_val + root->val;
    path_sum = max(cur_val, path_sum);

    // 但是往上面传的话，就只用上传一条路径，所以我们要用max(left, right)
    // 注意 return to parents时只能返回left_cost或者right_cost，二选一。因为我们返回的是包括root在内的这一条路径
    if(max(left_cost, right_cost) > 0)
        return max(left_cost, right_cost) + root->val;
    else
        return root->val;
}
/*
 int helper(BinaryTreeNode* root, int& max) {
 if (root == NULL) {
 return 0;
 }
 int left = helper(root->left, max);
 int right = helper(root->right, max);
 left = left < 0 ? 0 : left;
 right = right < 0 ? 0 : right;
 max = max > (root->val + left + right) ? max : (root->val + left + right);
 return left > right ? (left + root->val) : (right + root->val);
 }*/

int maxPathSum(BinaryTreeNode *root) {
    if(root == NULL) return INT_MIN;
    int path_sum = INT_MIN;
    find_max_sum_from_node_to_node(root, path_sum);
    return path_sum;
}
