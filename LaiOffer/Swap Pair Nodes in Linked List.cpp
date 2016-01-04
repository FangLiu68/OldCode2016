//
//  Swap Pair Nodes in Linked List.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/8/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Reverse pairs of elements in a singly-linked list.

 Examples
 L = null, after reverse is null
 L = 1 -> null, after reverse is 1 -> null
 L = 1 -> 2 -> null, after reverse is 2 -> 1 -> null
 L = 1 -> 2 -> 3 -> null, after reverse is 2 -> 1 -> 3 -> null
 */

#include "Header.h"


ListNode* reverse_pair(ListNode* head){
    // base case
    if(head == NULL || head->next == NULL) return head;

    ListNode* cur = head;
    ListNode* pNext = head->next;
    ListNode* nodeN = reverse_pair(pNext->next);

    pNext->next = cur;
    cur->next = nodeN;
    return pNext;
}