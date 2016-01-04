//
//  Max Sum in Binary Tree.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/6/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a binary tree in which each node element contains a number. Find the maximum possible sum of all nodes from one leaf node to another.
 The maximum sum path may or may not go through root. 
 For example, in the following binary tree, the maximum sum is 27(3+6+9+0-1+10). Expected time complexity is O(N).
 */

/*
                        -15
                    /           \
                   5             6
                /    \         /   \
              -8      1       3     9
              / \                    \
             2   6                    0
                                    /   \
                                   4     -1
                                        /
                                       10
 1. what do you expect from your left/ right child?
    max path cost from left subtree = (1)
    max path cost from right subtree = (2)
 2. what do you want to do in the current layer?
    including my current root node, what is the largest sum of the three parts sum
    root->val + (1) + (2) = sum
    将上面的sum与global max_sum比较。如果sum大，只有他在最后所得路径的中间时，即他必须有左孩子和右孩子，这样才有可能有叶子通过他，此时我们才更新max_sum。
    简单来说，就是更新的时候，从这个点开始往下的子树cut掉，可以形成一个从叶子到叶子并且通过这个点的路径
    比如说9，我们从下往上算到9的时候，cur_sum = 9+0+(-1)+10=18，比此时的max_sum大，但我们不能更新max_sum。因为此时如果cut掉9往下的子树，并不存在一个路径路径从叶子出发通过9再到另一个叶子
    所以我们更新的时候，必须保证左右此节点必须有左右孩子，即此时要 root->left!=NULL && root->right!=NULL
    注意，也可能有另外一种情况，如果题意说单个叶子节点也可以算作结果的话，那么如果某叶子节点的值比任何叶子到叶子加起来路径和都大，那么这个叶子节点的值也可以是结果。即此时要 root->left==NULL && root->right==NULL
 3. what do you want to report to your parent?
    report what?
    a single path with max cost from leaf node to current node
    root->val + max((1), (2))
 */


#include "BinaryTree.h"
#include <iostream>
using namespace std;

int find_max_sum_from_leaf_to_leaf(BinaryTreeNode* root, int &max_sum){
    if(root == NULL) return 0; // base case

    /*
     Find maximum sum in left and right subtree.
     Also find maximum root to leaf sums in left and right subtrees, and store them in left_cost and right_cost.
     */
    int left_cost = find_max_sum_from_leaf_to_leaf(root->left, max_sum);
    int right_cost = find_max_sum_from_leaf_to_leaf(root->right, max_sum);

    // find the maximum path sum passing through root
    int cur = left_cost + right_cost + root->val;

    // update max_sum only when needed: 左右都不为空(make sure 9不能更新)；左右都为空
    if(cur > max_sum && ((root->left && root->right) || (!root->left && !root->right))) {
        max_sum = cur;
    }

    // return the maximum (root to leaf path) cost
    if(root->left == NULL){
        return right_cost + root->val;
    }else if(root->right == NULL){
        return left_cost + root->val; // 上面这两个if不能省略
    }else{
        return max(left_cost, right_cost) + root->val;
    }
}


/*
 为什么在return之前的两个if不能省略？例子
            -1
       -2       -3
   -4              -5
 比如上面这个tree。对于node -2而言，他的left=-4，right=0，如果不判断他的右子树是否为空的情况，直接返回max(left,right)+(-2)的话，就会忽略他的左子树-4，那么-2往上返回的就是-2，而不是(-4)+(-2)，这样就不是Leaf到Leaf的情况，最后结果就是(-2)+(-1)+(-3)=-6,而真正的结果应该是(-4)+(-2)+(-1)+(-3)+(-5)=-15.
 注意，如果题目说单个叶子节点也是一个path的话，那就在中间添加一步 || (!root->left && !root->right)，那么最后的结果就是-4而不是-15.但同样要在return之前判断左右子树是否为空的情况
 */

int FindMaxPathCost(BinaryTreeNode* root){
    if(root == NULL) return INT_MIN;
    int max_sum = INT_MIN; // 注意这里设置的初始值
    find_max_sum_from_leaf_to_leaf(root, max_sum);
    return max_sum;
}
/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(-1);
    BinaryTreeNode* node1 = new BinaryTreeNode(-2);
    BinaryTreeNode* node2 = new BinaryTreeNode(-3);
    BinaryTreeNode* node3 = new BinaryTreeNode(-4);
    BinaryTreeNode* node4 = new BinaryTreeNode(-5);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node2->right = node4;
    int res = FindMaxPathCost(root);
    cout << res << endl;
}
*/







