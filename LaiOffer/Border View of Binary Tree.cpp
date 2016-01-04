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

void borderView(BinaryTreeNode* root, int flag1, int flag2){
    if(root == NULL){
        return;
    }
    if(flag1 == 0 || (root->left==NULL && root->right==NULL)){
        cout << root->val << " ";
    }
    borderView(root->left, flag1, 1);
    borderView(root->right, 1, flag2);
    if(flag2==0 && (root->left!=NULL && root->right!=NULL) && flag1==1){
        cout << root->val << " ";
    }
}