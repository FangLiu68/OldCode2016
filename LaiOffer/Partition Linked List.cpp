//
//  Partition Linked List.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/29/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a linked list and a target value T, partition it such that all nodes less than T are listed before the nodes larger than or equal to target value T. The original relative order of the nodes in each of the two partitions should be preserved.

 Examples

 L = 2 -> 4 -> 3 -> 5 -> 1 -> null, T = 3, is partitioned to 2 -> 1 -> 3 -> 4 -> 5 -> null
 */

#include "Header.h"


ListNode* partition_list(ListNode* head, int target) {
    if(head == NULL) return NULL;

    ListNode dummy1(INT_MIN);
    ListNode* small = &dummy1;

    ListNode dummy2(INT_MIN);
    ListNode* big = &dummy2;
    
    ListNode* cur = head;
    while(cur){
        if(cur->val < target){
            small->next = cur;
            small = small->next;
        }
        else{
            big->next = cur;
            big = big->next;
        }
        cur = cur->next;
    }
    big->next = NULL; // de-link the big partition from the list
    small->next = dummy2.next; // connect two partitions
    return dummy1.next;
}