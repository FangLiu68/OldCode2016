//
//  Left View of Binary Tree.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/4/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 get the left view of a binary tree
        5
    /      \
   1        9
    \     /   \
     3    8    11
    /
   2
 left view: 5 1 3 2
 */

#include "Header.h"


// BFS, left to right. not finished yet
vector<int> left_view(BinaryTreeNode* root){
    vector<int> res;
    if(root == NULL){
        return res;
    }
    
    queue<BinaryTreeNode*> qu;
    qu.push(root);
    bool tag = true;
    
    while(!qu.empty()){
        int len = qu.size();
        for(int i=0; i<len; ++i){
            BinaryTreeNode* top = qu.front();
            qu.pop();
            
            if(top->left) qu.push(top->left);
            if(top->right) qu.push(top->right);
        }
        tag = !tag;
    }
    return res;
}



 // DFS, pre/post/in, left to right

