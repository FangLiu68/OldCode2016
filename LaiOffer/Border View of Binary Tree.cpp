//
//  Border View of Binary Tree.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/20/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/* print the border view of bianry tree
    
 border view
                5
            /         \
          1              9
            \          /   \
             3        8    11
              \
                4

 1. the most left path (start from root, always go left, the nodes on the path)
 2. all the leaves
 3. the most right path

 border view: {5, 1, 4, 8, 11, 9}

*/

#include "BinaryTree.h"
#include <iostream>
using namespace std;

/*
 1. the leftmost path (start from root, always go left, the nodes on the path) [5, 1]
 2. all the leaves, left to right [4, 8,11]
 3. the rightmost path (bottom to up) [11, 9, 5]
 4. there should not be duplicate nodes in the view. border view: [5, 1, 4, 8, 11, 9]
 
 Method 1:
 leftmost path: preorder, left path
 leaves: post/in/preorder, left to right
 rightmost path: postorder, right path
 
 */

void view_DFS(BinaryTreeNode* root, bool leftMost, bool rightMost){
    if(root == NULL){
        return;
    }
    
    // pre order
    if(leftMost || (root->left==NULL && root->right==NULL)){
        cout << root->val << " ";
    }
    
    view_DFS(root->left, leftMost, false);
    view_DFS(root->right, false, rightMost);
    
    // post order
    if(rightMost && !leftMost && (root->left!=NULL && root->right!=NULL)){
        cout << root->val << " ";
    }
}

void border_view(BinaryTreeNode* root){
    view_DFS(root, true, true);
}
/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(5);
    BinaryTreeNode* node1 = new BinaryTreeNode(1);
    BinaryTreeNode* node3 = new BinaryTreeNode(3);
    BinaryTreeNode* node4 = new BinaryTreeNode(4);
    BinaryTreeNode* node9 = new BinaryTreeNode(9);
    BinaryTreeNode* node8 = new BinaryTreeNode(8);
    BinaryTreeNode* node11 = new BinaryTreeNode(11);
    
    root->left = node1;
    node1->right = node3;
    node3->right = node4;
    root->right = node9;
    node9->left = node8;
    node9->right = node11;
    
    border_view(root);
    cout << endl;
    return 0;
}*/