//
//  Balanced Bianry Tree.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/6/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//


/* 
 determine whether a binary tree is a balanced bianry tree

 Balanced binary tree: 
 a binary tree in which the depth of the left and right subtrees of every node differ by 1 or less.

 任意两个节点的左右子树高度差不超过1.
 可以用最基本的方法做，先求任意两个节点的高度差，比较，如果超过1就返回false （会重复计算某些节点的高度差）
 
        1                       1
    /      \                  /    \
    2      3                 2      3
  /   \     \               /        \
 4     5     6             4          5
      /                   /
     7                   6
左边的是balanced tree; 右边的不是balanced tree
*/

#include "Header.h"

/*
                        10  root (2 times getHeight n/2 + n/2)-->O(n)
                /                  \
 5(2 times getHeight  n/2)       15(n/2)  -->O(n)
    /               \               /   \
   3(N/4)             9(N/4)     12(N/4)  20(N/4)

 total level = log(n) level
 for each level   O(n)
 So, the total time complexity = O(nlog(n))
 对每一个node T来说，getHeight(T)的复杂度是以T为根节点的所有子节点的个数
 例如：
 对根节点10来说，getHeight(10)=getHeight(5)+getHeight(15)
 假设整个树一共有N个node，假设说是完全二叉树，那么10的左子树一共有N/2个node, 右子树有N/2个Node，
 那么第一行对getHeight(10)的BIGO是N/2+N/2 = N

 第二行对节点5来说，getHeight(5) = getHeight(3)+getHeight(9)
 同样，由于3和9都各自拥有N/4个node的subtree，所以getHeight(3)和getHeight(9)各自的复杂度都是N/4，所以getHeight(5)的复杂度是N/2
 所以5的兄弟getHeight(15)的复杂度也是N/2
 那么第二行一共的getHeight的复杂度为：getHeight(5)+getHeight(15) = N/2 + N/2 = N
 ....
 每一行的所有getHeight的复杂度一共是N
 整个树一共有logN行
 所以isBlanced(root)这种算法的复杂度一共是NlogN
 */

// O(N) runtime. N is the total number of nodes in the subtree rooted at "root"
int helper_getHeight(BinaryTreeNode* root);

// O(NlogN) runtime
bool isBalanced_slow(BinaryTreeNode* root){
    if(root == NULL) return true; // base case

    // what do you expect from left and right child
    int left_height = helper_getHeight(root->left);
    int right_height = helper_getHeight(root->right);
    // what do you want to do in the current layer
    if(abs(left_height - right_height) > 1)
        return false;

    // what do you want to report to your parent
    return isBalanced_slow(root->left) && isBalanced_slow(root->right);
}

// O(N) runtime, O(logN) space 因为不断压栈的过程
int helper_getHeight(BinaryTreeNode* root){
    // base case
    if(root == NULL) return 0;

    // what do you want from your left and right child
    int left_height = helper_getHeight(root->left); // breaking point.除非拿到结果（触底到最后一层），否则是不会返回的
    int right_height = helper_getHeight(root->right);

    return max(left_height, right_height) + 1; // what do you want to report to your parent
}

////////////////////////////
int getHeight_fast(BinaryTreeNode* root);
bool isBalanced_fast(BinaryTreeNode* root){
    if(root == NULL) return true; // 注意这里我们认为空树为true
    return getHeight_fast(root) != -1;
}

// O(N) runtime
int getHeight_fast(BinaryTreeNode* root){
    if(root == NULL) return 0;

    int left = getHeight_fast(root->left);
    int right = getHeight_fast(root->right);
    if(abs(left-right) > 1 || left == -1 || right == -1)
        return -1;

    return max(left, right)+1;
}
/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(1);
    BinaryTreeNode* node1 = new BinaryTreeNode(2);
    BinaryTreeNode* node2 = new BinaryTreeNode(3);
    BinaryTreeNode* node3 = new BinaryTreeNode(4);
    BinaryTreeNode* node4 = new BinaryTreeNode(5);
    BinaryTreeNode* node5 = new BinaryTreeNode(6);
    BinaryTreeNode* node6 = new BinaryTreeNode(7);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node4->left = node6;
    if(isBalanced_slow(root)) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}
*/