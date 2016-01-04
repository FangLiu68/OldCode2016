//
//  Create LinkedList on Each Level.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Givne a binary tree, design an algorithm which creates a linked list of all the nodes at each depth. (eg, if you have a tree with depth D, then you will have D linked lists)

#include "Header.h"

// breadth first search
vector<ListNode*> createListEachLevel(BinaryTreeNode* root){
    vector<ListNode*> res;
    if(root == NULL){
        return res;
    }

    queue<BinaryTreeNode*> qu;
    qu.push(root);

    while(!qu.empty()){
        int levelSize = qu.size();

        ListNode dummy(INT_MIN);
        ListNode* head = &dummy;

        for(int i=0; i < levelSize; ++i){
            BinaryTreeNode* cur = qu.front();
            qu.pop();
            head->next = new ListNode(cur->val);
            head = head->next;

            if(cur->left != NULL){
                qu.push(cur->left);
            }
            if(cur->right != NULL){
                qu.push(cur->right);
            }
        }

        res.push_back(dummy.next);
    }

    return res;
}

/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(0);
    BinaryTreeNode* node1 = new BinaryTreeNode(1);
    BinaryTreeNode* node2 = new BinaryTreeNode(2);
    BinaryTreeNode* node3 = new BinaryTreeNode(3);
    BinaryTreeNode* node4 = new BinaryTreeNode(4);
    BinaryTreeNode* node5 = new BinaryTreeNode(5);
    BinaryTreeNode* node6 = new BinaryTreeNode(6);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;

    vector<ListNode*> res = createListEachLevel(root);
    for(int i=0; i < res.size(); ++i){
        ListNode* head = res[i];
        while(head){
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
    return 0;
}*/



