//
//  Sum of All Paths.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/4/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Sum of all paths from root to leaf nodes in a binary tree
            7
        /     \
       4       9
      /  \     /
     1    5   8
          /
         3
 sum = 741 + 7453 + 798 = 8992
 */

#include "Header.h"

/*
 pass down: the value of the path so far
 */
int allPathSum(BinaryTreeNode* root, int cur_val){
    if(root == NULL){
        return 0;
    }
    
    cur_val = cur_val * 10 + root->val;
    if(root->left == NULL && root->right == NULL){
        return cur_val;
    }
    
    return allPathSum(root->left, cur_val) + allPathSum(root->right, cur_val);
}