//
//  Remove Dup in Unsorted List.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// remove duplicates from an unsorted linked list.
// how would you do this if a temporary buffer is not allowed?

#include "Header.h"

// pre指向需要被删除节点的前节点
// cur指向重复节点
// O(N) runtime, O(N) space
void remove_dup_unsortedList(ListNode* head){
    if(head == NULL) return;
    unordered_set<int> st;
    ListNode* pre = head;
    ListNode* cur = pre->next;
    st.insert(pre->val);
    while(cur){
        if(st.find(cur->val) != st.end()){
            pre->next = cur->next;
            delete cur;
            cur = pre->next;
        }else{
            st.insert(cur->val);
            pre = cur;
            cur = pre->next;
        }
    }
}

// O(N^2) runtime, O(1) space
void remove_dup_unsortedList_noBuffer(ListNode* head){
    if(head == NULL || head->next==NULL) return;

    ListNode* cur = head;
    while(cur){
        // remove all future nodes that have the same value
        ListNode* runner = cur;
        while(runner->next){
            if(runner->next->val == cur->val){
                ListNode* tmp = runner->next;
                runner->next = tmp->next;
                delete tmp;
                tmp = NULL;
            }else{
                runner = runner->next;
            }
        }
        cur = cur->next;
    }
}


/*
int main(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(3);
    ListNode* node5 = new ListNode(1);
    ListNode* node6 = new ListNode(2);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    remove_dup_unsortedList(node1);
    while(node1){
        cout << node1->val << " ";
        node1 = node1->next;
    }return 0;
}*/