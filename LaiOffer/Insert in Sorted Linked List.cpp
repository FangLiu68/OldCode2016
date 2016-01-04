//
//  Insert in Sorted Linked List.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/7/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Insert a value in a sorted linked list.

 Examples
 L = null, insert 1, return 1 -> null
 L = 1 -> 3 -> 5 -> null, insert 2, return 1 -> 2 -> 3 -> 5 -> null
 L = 1 -> 3 -> 5 -> null, insert 3, return 1 -> 3 -> 3 -> 5 -> null
 L = 2 -> 3 -> null, insert 1, return 1 -> 2 -> 3 -> null
 */
#include "Header.h"

ListNode* insert(ListNode* head, int value) {
    if(head==NULL)
        return new ListNode(value);

    ListNode dummy(INT_MIN);
    ListNode* cur = &dummy;
    cur->next = head;

    // find insert position
    while(cur->next && value > cur->next->val)
        cur = cur->next;

    // insert
    ListNode* newNode = new ListNode(value);
    newNode->next = cur->next;
    cur->next = newNode;
    
    return dummy.next;
}


void insertNodeIntoSortedList(int value, ListNode*& head) {
    ListNode* node = new ListNode(value);
    if (head == NULL || head->val >= value) {
        node->next = head;
        head = node;
        return;
    }
    ListNode* prev = head;
    while (prev->next != NULL && prev->next->val < value) {
        prev = prev->next;
    }
    node->next = prev->next;
    prev->next = node;
}
