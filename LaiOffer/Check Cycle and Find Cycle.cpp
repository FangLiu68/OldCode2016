//
//  Check if Linked List has Cycle.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/28/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Check if a given linked list has a cycle. Return true if it does, otherwise return false.
 */

#include "Header.h"

bool hasCycle(ListNode* head) {
    if(head == NULL) return false;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

ListNode *detectCycle(ListNode *head) {
    if(head == NULL){
        return NULL;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == NULL){
            return NULL;
        }else{
            if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
    }
    return NULL;
}

//////////////不看下面的
ListNode* find_cycle_in_list(ListNode* head) {
    if(head == NULL) return NULL;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    if(fast==NULL || fast->next==NULL) return NULL;
    ListNode* mark = slow;
    slow = head;
    while(mark != slow){
        mark = mark->next;
        slow = slow->next;
    }
    return mark;
}
