//
//  Right View of BT.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a Binary Tree, print Right view of it. Right view of a Binary Tree is set of nodes visible when tree is visited from Right side.
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

/*
        1
      /  \
    2      3
     \    /
      4  5
     /
    6
 
 Node   cur     max     print       change_max_to
 1      1       0           1           1
 3      2       1           3           2
 NULL
 5      3       2           5           3
 2      2       3           X           
 4      3       3           x
 6      4       3           6           4

 同一层上的节点的level value是相同的，max在小于cur的时候都会增加1
 pre order traversal
 */

void helper_rightSideView(BinaryTreeNode* root, int cur_level, int& max, vector<int>& res){
    if(root == NULL){
        return;
    }
    if(cur_level > max){
        res.push_back(root->val);
        max = cur_level;
    }
    helper_rightSideView(root->right, cur_level+1, max, res);
    helper_rightSideView(root->left, cur_level+1, max, res);
}

vector<int> rightSideView(BinaryTreeNode* root) {
    vector<int> res;
    if(root == NULL) return res;
    int max = 0;
    helper_rightSideView(root, 1, max, res);
    return res;
}

/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(1);
    BinaryTreeNode* node1 = new BinaryTreeNode(2);
    BinaryTreeNode* node2 = new BinaryTreeNode(3);
    BinaryTreeNode* node3 = new BinaryTreeNode(4);
    BinaryTreeNode* node4 = new BinaryTreeNode(5);
    BinaryTreeNode* node5 = new BinaryTreeNode(6);
    root->left = node1;
    root->right = node2;
    node1->right = node3;
    node2->left = node4;
    node3->left = node5;
    vector<int> res = rightSideView(root);
    cout << endl;
    return 0;
}*/