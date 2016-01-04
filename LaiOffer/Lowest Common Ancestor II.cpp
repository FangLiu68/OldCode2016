//
//  Lowest Common Ancestor II.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/3/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given two nodes in a binary tree (with parent pointer available), find their lowest common ancestor.
 Assumptions
 There is parent pointer for the nodes in the binary tree
 The given two nodes are not guaranteed to be in the binary tree
 Examples
      5
    /   \
   9     12
 /  \      \
 2    3      14
 The lowest common ancestor of 2 and 14 is 5
 The lowest common ancestor of 2 and 9 is 9
 The lowest common ancestor of 2 and 8 is null (8 is not in the tree)
 */

#include "BinaryTree.h"
#include <iostream>
#include <unordered_set>
using namespace std;

struct TreeNodeP{
    int value;
    TreeNodeP* left;
    TreeNodeP* right;
    TreeNodeP* parent;
    TreeNodeP(int v) : value(v), left(NULL), right(NULL), parent(NULL){}
    TreeNodeP(int v, TreeNodeP* p) : value(v), left(NULL), right(NULL), parent(p){}
};
int getLen(TreeNodeP* node);
TreeNodeP* mergeNode(TreeNodeP* one, TreeNodeP* two, int lendiff);

TreeNodeP* LCA_with_parent_pointer(TreeNodeP* one, TreeNodeP* two) {
    if(one==NULL || two==NULL) return NULL;
    int lenone = getLen(one);
    int lentwo = getLen(two);
    return mergeNode(one, two, lenone-lentwo);
}

TreeNodeP* mergeNode(TreeNodeP* one, TreeNodeP* two, int lendiff){
    if(lendiff<0) return mergeNode(two, one, lendiff);
    while(lendiff>0){
        one = one->parent;
        lendiff--;
    }
    while(one!=two && one && two){
        one = one->parent;
        two = two->parent;
    }
    return one;
}

int getLen(TreeNodeP* node){
    if(node==NULL) return 0;
    int len = 0;
    while(node){
        len++;
        node = node->parent;
    }
    return len;
}

/*
struct Node{
    int val;
    Node* left;
    Node* right;
    Node* parent;
    Node(int v) : left(NULL), right(NULL), parent(NULL), val(v) {}
};

int getLen(Node* p){
    if(p == NULL){
        return 0;
    }
    int len = 0;
    while(p){
        len++;
        p = p->parent;
    }
    return len;
}

Node* LCA(Node* root, Node* one, Node* two){
    if(root == NULL || one == NULL || two == NULL){
        return NULL;
    }
    int len1 = getLen(one);
    int len2 = getLen(two);
    if(len1 > len2){
        int gap = len1 - len2;
        for(int i=0; i<gap; ++i){
            one = one->parent;
        }
        while(one && two){
            if(one == two){
                return one;
            }
            one = one->parent;
            two = two->parent;
        }
        return NULL;
    }else{
        int gap = len2 - len1;
        for(int i=0; i<gap; ++i){
            two = two->parent;
        }
        while(one && two){
            if(one == two){
                return two;
            }
            one = one->parent;
            two = two->parent;
        }
        return NULL;
    }
}*/

/*
int main(){
    TreeNodeP* root = new TreeNodeP(5);
    TreeNodeP* node1 = new TreeNodeP(9);
    TreeNodeP* node2 = new TreeNodeP(12);
    TreeNodeP* node3 = new TreeNodeP(2);
    TreeNodeP* node4 = new TreeNodeP(3);
    TreeNodeP* node5 = new TreeNodeP(14);
    root->left = node1;
    root->right = node2;
    node1->parent = root;
    node2->parent = root;
    node1->left = node3;
    node1->right = node4;
    node3->parent = node1;
    node4->parent = node1;
    node2->right = node5;
    node5->parent = node2;
    TreeNodeP* node6 = new TreeNodeP(8);
    TreeNodeP* res = LCA_with_parent_pointer(node3, node6);
    if(res == NULL){
        cout << "no res" << endl;
    }else{
        cout << res->value << endl;
    }
    return 0;
}*/