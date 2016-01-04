//
//  Remove Dup in Sorted List.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include "Header.h"
#include "LinkedList.h"


/*
 Given a sorted linked list, delete all duplicates such that each element appear only once.
 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.
 */

ListNode* remove_dup_from_sorted_list1(ListNode* pHead){
    if(pHead == NULL)   return NULL;
    ListNode* pre = pHead;
    ListNode* cur = pHead->next;
    while(cur){
        if(pre->val == cur->val){ // 删除连续相同节点
            pre->next = cur->next;
            delete cur;
            cur = pre->next;
        }else{
            pre = cur;
            cur = pre->next;
        }
    }
    return pHead;
}


// time compleixty O(N), space complexity O(1) eg: 1 1 1 2 2 3 4 4
ListNode* remove_dup_from_sorted_list(ListNode* pHead){
    if(pHead == NULL) return NULL;
    ListNode* cur = pHead;
    while(cur && cur->next){
        if(cur->val == cur->next->val) // 删除连续的相同节点
            cur->next = cur->next->next;
        else
            cur = cur->next;
    }
    return pHead;
}

