//
//  Remove Linked List Elem.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/30/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Remove all elements from a linked list of integers that have value val.

 Example
 Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 Return: 1 --> 2 --> 3 --> 4 --> 5
 */

#include "Header.h"
#include "LinkedList.h"


ListNode* removeElements(ListNode* head, int val) {
    if(head == NULL){
        return NULL;
    }
    ListNode dummy(-1);
    ListNode* pre = &dummy;
    pre->next = head;
    ListNode* cur = head;
    while(cur){
        if(cur->val == val){
            pre->next = cur->next;
            delete cur;
            cur = pre->next;
        }else{
            pre = cur;
            cur = cur->next;
        }
    }
    return dummy.next;
}