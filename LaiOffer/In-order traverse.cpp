//
//  in_order traverse.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Implement an iterative, in-order traversal of a given binary tree, return the list of keys of each node in the tree as it is in-order traversed.
 Examples
        5
      /    \
    3        8
  /   \        \
 1      4        11
 In-order traversal is [1, 3, 4, 5, 8, 11]
 Corner Cases
 What if the given binary tree is null? Return an empty list in this case
 */
#include "BinaryTree.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
 nth Loop			stack content b1	sc b2 		print
 1                               421       21           4
 2                                21		1           2
 3                                51		1           5
 4                                 1	empty           1
 5                                63		3           6
 6                                 3	empty           3
 7                                 7	empty           7
 每次在breaking point2的地方，stack为空的时候，都表明此时我们已经done printing整个左子树部分
 而当breaking point1的地方stack为空的时候，表明整个循环结束
 */

// traverse use stack
vector<int> inOrder_iter(BinaryTreeNode* root){
    vector<int> res;
    if(root == NULL) return res;
    stack<BinaryTreeNode*> stk;
    BinaryTreeNode* cur = root;
    while(cur || !stk.empty()){
        if(cur){
            stk.push(cur);
            cur = cur->left;
        }else{ // 当cur==NULL，就不再push cur into stack，直接从stack pop out value
            BinaryTreeNode* tmp = stk.top();
            stk.pop();
            res.push_back(tmp->val);
            cur = tmp->right;
        }
    }
    return res;
}

//==============================================================
void helper_in(BinaryTreeNode* root, vector<int> &res);
vector<int> inOrder_recur(BinaryTreeNode* root) {
    vector<int> res;
    if(root == NULL) return res;
    helper_in(root, res);
    return res;
}
void helper_in(BinaryTreeNode* root, vector<int> &res){
    if(root == NULL) return;
    helper_in(root->left, res);
    res.push_back(root->val);
    helper_in(root->right, res);
}

/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(5);
    BinaryTreeNode* level11 = new BinaryTreeNode(3);
    BinaryTreeNode* level12 = new BinaryTreeNode(8);
    BinaryTreeNode* level21 = new BinaryTreeNode(1);
    BinaryTreeNode* level22 = new BinaryTreeNode(4);
    BinaryTreeNode* level23 = new BinaryTreeNode(11);
    root->left = level11;
    root->right = level12;
    level11->left = level21;
    level11->right = level22;
    level12->right = level23;
    vector<int> res = inorder_iter(root);
    for(int i=0; i<res.size(); ++i){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}*/