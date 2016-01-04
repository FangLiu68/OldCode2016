//
//  Closest Number in BST.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 In a binary search tree, find the node containing the closest number to the given target number.
 Examples
    5
  /    \
  2      11
        /   \
        6    14

 closest number to 4 is 5
 closest number to 10 is 11
 closest number to 6 is 6
 */

#include "Header.h"

/*
Case (1) if the current_node value <  target value, 
compare the difference of current node value with the target value, update if it is closer; Go to the rChild node
Case (2) if the current_node value  > target value,  
compare the difference of current node value with the target value, update if it is closer; Go to the lChild node;
*/

int closet_num_in_BST(BinaryTreeNode* root, int target) {
    if(root == NULL){
        return INT_MIN;
    }
    int min_diff = INT_MAX;
    BinaryTreeNode* res = root;
    while(1){
        int cur_diff = abs(root->val - target);
        if(cur_diff < min_diff){
            min_diff = abs(cur_diff);
            res = root;
        }
        if(target < root->val){
            root = root->left;
        }else if(target > root->val){
            root = root->right;
        }else{
            return root->val;
        }
        if(root == NULL){
            break;
        }
    }
    return res->val;
}



/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(5);
    BinaryTreeNode* node1 = new BinaryTreeNode(2);
    BinaryTreeNode* node2 = new BinaryTreeNode(11);
    BinaryTreeNode* node3 = new BinaryTreeNode(6);
    BinaryTreeNode* node4 = new BinaryTreeNode(14);

    root->left = node1;
    root->right = node2;
    node2->left = node3;
    node2->right = node4;
    BinaryTreeNode* res = closet_num_in_BST(root, 10);
    cout << res->val << endl;
    return 0;
}*/