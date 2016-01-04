//
//  Linked List Cycle.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/7/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include "Header.h"
#include <iostream>
using namespace std;


ListNode* cycle_in_linkedList(ListNode* head) {
    if(head==NULL){
        return NULL;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            ListNode* meet = fast;
            slow = head;
            while(slow != meet){
                slow = slow->next;
                meet = meet->next;
            }
            return slow;
        }
    }
    return NULL;
}