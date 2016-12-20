//
//  Change Node Value in BST.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/4/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Change the value of each nodes in a BST to the sum of all the nodes <= its own value
          5(10)
        /       \
      3(5)       8(24)
     /          /   \
    2(2)      6(16)  12(36)
 
 */

#include "Header.h"

// pass total value sum of nodes from the previous level which are less than current node
// return total value sum of tree with current node as rot node
int accumulteHelper(BinaryTreeNode* root, int totalSmaller){
    if(root == NULL){
        return 0;
    }
    
    int left_total = accumulteHelper(root->left, totalSmaller);
    
    int root_val = root->val;
    root->val = root->val + left_total + totalSmaller;
    int right_total = accumulteHelper(root->right, root->val);
    
    return left_total + right_total + root_val;
}

void accumulateSumBST(BinaryTreeNode* root){
    accumulteHelper(root, 0);
}