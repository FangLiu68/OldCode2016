//
//  get Rank of Num.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/7/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Imagine you are reading in stream of integers. you wish to be able to look up the rank of a number x (the number of values less than or equal to x). implement the data structures and algorithms to support these operations. that is, implement the method track(int x), which is caled when each number is generated, and the method getRnakOfNumber(int x), which return the number of values less than or equal to x(not including x itself).
 */

#include "Header.h"

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    int leftNodes;
    TreeNode(int v) : val(v), left(NULL), right(NULL), leftNodes(0){}
};

class NodeRank{
private:
    TreeNode* root;
public:
    void insert(int value){
        if(value <= root->val){
            while(root->left != NULL){
                root = root->left;
            }
            root->left = new TreeNode(value);
            root->leftNodes++;
        }else{
            while(root->right != NULL){
                root = root->right;
            }
            root->right = new TreeNode(value);
        }
    }

    int getRank(int value){
        if(value == root->val){
            return root->leftNodes;
        }else if(value < root->val){
            while(value < root->val){
                root = root->left;
            }
            if(root->left == NULL){
                return -1;
            }else{

            }
        }
        return -1;
    }
};