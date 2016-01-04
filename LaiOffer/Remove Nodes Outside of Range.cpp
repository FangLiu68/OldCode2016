//
//  Remove Nodes Outside of Range.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 retain only the nodes in range for BST [min, max], change the structure minimized
            5
        /        \
      1             9
       \           /  \
        3          8  11

            5
        /        \
       3           8

 [MIN, MAX] = [2, 8]

 get: 3, 5, 8

 Method 1: In-Order traverse, delete all the nodes out of range. O(n * logn).

 Method 2: recursion. O(n).
 如果current node value比min小，就直接访问cur->right
 如果current node value比max大，就直接访问cur->left
 如果current node value在可取值范围之间，就将cur->left设置为其左子树给他返回的结果(返回的这个结果肯定是在正确范围之内的)，
 同时将cur->right设置为其右子树给他返回的结果(同样在正确范围之内)
 同时因为current node在可取值范围之内，所以他向上一层返回的就是自己的值
 */

#include "Header.h"

BinaryTreeNode* remove_outOfRange(BinaryTreeNode* root, int min, int max){
    if(root == NULL){
        return NULL;
    }
    if(root->val < min){
        return  remove_outOfRange(root->right, min, max);
    }else if(root->val > max){
        return remove_outOfRange(root->left, min, max);
    }else{
        root->left = remove_outOfRange(root->left, min, max);
        root->right = remove_outOfRange(root->right, min, max);
        return root;
    }
}
/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(5);
    BinaryTreeNode* left1 = new BinaryTreeNode(1);
    BinaryTreeNode* right1 = new BinaryTreeNode(9);
    BinaryTreeNode* left12 = new BinaryTreeNode(3);
    BinaryTreeNode* right11 = new BinaryTreeNode(8);
    BinaryTreeNode* right12 = new BinaryTreeNode(11);
    root->left = left1;
    root->right = right1;
    left1->right = left12;
    right1->left = right11;
    right1->right = right12;
    BinaryTreeNode* res = remove_outOfRange(root, 2, 8);
    vector<int> val = inOrder_iter(res);
    for(int i=0; i<val.size(); ++i){
        cout << val[i] << " ";
    }return 0;
}*/