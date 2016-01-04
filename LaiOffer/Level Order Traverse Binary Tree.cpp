//
//  Get Keys in Binary Tree Level by Level.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/3/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Get the list of list of keys in a given binary tree layer by layer. Each layer is represented by a list of keys and the keys are traversed from left to right.
 Examples
 5
 /    \
 3        8
 /   \        \
 1     4        11
 the result is [ [5], [3, 8], [1, 4, 11] ]
 Corner Cases
 What if the binary tree is null? Return an empty list of list in this case
 */

#include "BinaryTree.h"
#include <vector>
#include <deque>
#include <queue>
#include <iostream>
using namespace std;

// BFS 用queue, first in first out
void print_keys_level_by_level(BinaryTreeNode* root){
    if(root == NULL) return ;
    queue<BinaryTreeNode*> qu;
    qu.push(root);
    while(!qu.empty()){
        int len = qu.size();
        for(int i=0; i<len; i++){
            BinaryTreeNode* cur = qu.front();
            qu.pop();
            if(i!=0)
                cout << ",";
            cout << cur->val;
            if(cur->left)   qu.push(cur->left);
            if(cur->right) qu.push(cur->right);
        }
        cout << endl;
    }
    cout << endl;
}

// get keys level by level
vector<vector<int> > traverse_level_by_level(BinaryTreeNode* root) {
    vector<vector<int>> res;
    if(root == NULL) return res;
    queue<BinaryTreeNode*> eachLevel;
    vector<int> tmp;
    eachLevel.push(root);
    while(!eachLevel.empty()){
        int len = eachLevel.size();

        for(int i=0; i<len; ++i){
            BinaryTreeNode* cur = eachLevel.front();
            eachLevel.pop();
            tmp.push_back(cur->val);
            if(cur->left) eachLevel.push(cur->left);
            if(cur->right) eachLevel.push(cur->right);
        }
        
        res.push_back(tmp);
        tmp.clear();
    }
    return res;
}


void print_levelOrder(BinaryTreeNode* root){
    if(root == NULL) return;
    queue<BinaryTreeNode*> qu;
    qu.push(root);
    while(!qu.empty()){
        int len = qu.size();
        for(int i=0; i<len; ++i){
            BinaryTreeNode* cur = qu.front();
            qu.pop();
            cout << cur->val << " ";
            if(cur->left) qu.push(cur->left);
            if(cur->right) qu.push(cur->right);
        }
        cout << endl;
    }
    cout << endl;
}
/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(5);
    BinaryTreeNode* node1 = new BinaryTreeNode(3);
    BinaryTreeNode* node2 = new BinaryTreeNode(8);
    BinaryTreeNode* node3 = new BinaryTreeNode(1);
    BinaryTreeNode* node4 = new BinaryTreeNode(4);
    BinaryTreeNode* node5 = new BinaryTreeNode(11);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->right = node5;
    print_keys_level_by_level(root);
    cout << "test" << endl;
    vector<vector<int>> res = traverse_level_by_level(root);
    for(int i=0; i<res.size(); ++i){
        vector<int> tmp = res[i];
        for(int j=0; j<tmp.size(); ++j){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    //print_levelOrder(root);
    return 0;
}*/