//
//  Convert Sorted Arr to BST.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/7/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// convert a sorted array to a balanced binary search tree

#include "BinaryTree.h"
#include <iostream>
#include <vector>
using namespace std;

BinaryTreeNode* helper_convert(vector<int>& num, int left, int right);
BinaryTreeNode *sortedArrayToBST(vector<int> &num) {
    if(num.empty()){
        return NULL;
    }
    int left = 0;
    int right = num.size()-1;
    return helper_convert(num, left, right);
}

BinaryTreeNode* helper_convert(vector<int>& num, int left, int right){
    if(left > right){ // base case注意是>
        return NULL;
    }
    int mid = left+(right-left)/2;
    BinaryTreeNode* root = new BinaryTreeNode(num[mid]);
    root->left = helper_convert(num, left, mid-1);
    root->right = helper_convert(num, mid+1, right);
    return root;
}