//
//  Reverse Double Linked List.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/14/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include "Header.h"
#include "LinkedList.h"


DoubleListNode* reverse_doubleList(DoubleListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    DoubleListNode* p_next = head->next;
    p_next->pre = NULL;
    DoubleListNode* newHead = reverse_doubleList(head->next);
    p_next->next = head;
    head->pre = p_next;
    return newHead;
}