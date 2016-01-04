//
//  Remove Node in BST.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/6/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// remove a node in BST

#include "Header.h"

BinaryTreeNode* helper_findNode(BinaryTreeNode* root, int target, BinaryTreeNode*& parent){
    if(root == NULL){
        return NULL;
    }
    parent = NULL;
    BinaryTreeNode* cur = root;
    while(cur){
        if(cur->val < target){
            parent = cur;
            cur = cur->right;
        }else if(cur->val > target){
            parent = cur;
            cur = cur->left;
        }else{
            return cur;
        }
    }
    // not found
    parent = NULL;
    return NULL;
}

/*
 case1: deleteNode has no left child and no right child
 case2: deleteNode has only left child
 case3: deleteNode has only right child
 case4: deleteNode has both left child and right child
 4.1 deleteNode's left child has no right child
 4.2 deleteNode's left child has right child
 */
void delete_in_BST(BinaryTreeNode*& root, int target){
    if(root == NULL){
        return;
    }

    BinaryTreeNode* parent = NULL; // parent node for tobeDelete node
    BinaryTreeNode* next = NULL; // node which should be connected to the tree after we delete tobeDelete
    BinaryTreeNode* parentNext = NULL; // tobeDelete's left subtree's rightmost child's parent
    BinaryTreeNode* tobeDelete = helper_findNode(root, target, parent);

    // couldn't find node that should be deleted
    if(tobeDelete == NULL){
        return;
    }

    if(tobeDelete->left==NULL && tobeDelete->right==NULL){ // case1
    }else if(tobeDelete->left==NULL){ // case2
        next = tobeDelete->right;
    }else if(tobeDelete->right==NULL){ // case3
        next = tobeDelete->left;
    }else{
        parentNext = tobeDelete;
        next = tobeDelete->left;
        while(next->right){
            parentNext = next;
            next = next->right;
        }
        if(parentNext == tobeDelete){ // case4.1
            next->right = tobeDelete->right;
        }else{
            parentNext->right = next->left;
            next->left = tobeDelete->left;
            next->right = tobeDelete->right;
        }
    }

    if(parent == NULL){ // tobeDelete is the root
        root = next;
    }else if(parent->val < tobeDelete->val){
        parent->right = next;
    }else{
        parent->left = next;
    }

    delete tobeDelete;
}

void print_BST(BinaryTreeNode* root){
    if(root == NULL){
        return;
    }
    print_BST(root->left);
    cout << root->val << " ";
    print_BST(root->right);
}
/*
int main(){
    BinaryTreeNode* root = NULL;
    insertNode(root, 10);
     insertNode(root, 5);
     insertNode(root, 15);
     insertNode(root, 4);
     insertNode(root, 7);
     insertNode(root, 6);
     insertNode(root, 9);
     insertNode(root, 8);
     insertNode(root, 14);
     insertNode(root, 16);
    print(root);
    cout << endl;
    cout << root->val << endl;
    deleteTest(root, 3);
    print(root);
    cout << endl;
    return 0;
}*/

//===============================================================
// 方法2 没仔细看  用上面的方法就行
BinaryTreeNode* deleteSmallest(BinaryTreeNode* root);
BinaryTreeNode* delete_in_BSTII(BinaryTreeNode* root, int value) {
    // base case
    if(root == NULL)  return NULL;

    if(root->val < value){
        root->right = delete_in_BSTII(root->right, value);
        return root;
    }
    else if(root->val > value){
        root->left = delete_in_BSTII(root->left, value);
        return root;
    }
    else{
        if(root->left == NULL)
            return root->right;
        else if(root->right == NULL)
            return root->right;
        else if(root->right->left == NULL){
            root->right->left = root->left;
            return root->right;
        }
        else{
            BinaryTreeNode* newRoot = deleteSmallest(root->right);
            newRoot->left = root->left;
            newRoot->right = root->right;
            return newRoot;
        }
    }
}

BinaryTreeNode* deleteSmallest(BinaryTreeNode* root){
    while(root->left->left)
        root = root->left;
    BinaryTreeNode* smallest = root->left;
    root->left = root->left->right;
    return smallest;
}