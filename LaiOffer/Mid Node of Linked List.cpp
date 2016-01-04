//
//  Mid Node of Linked List.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/28/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Find the middle node of a given linked list.

 Examples

 L = null, return null
 L = 1 -> null, return 1
 L = 1 -> 2 -> null, return 1
 L = 1 -> 2 -> 3 -> null, return 2
 L = 1 -> 2 -> 3 -> 4 -> null, return 2
 */

#include "Header.h"


/*
 struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(NULL){}
 };
 */

ListNode* middleNode(ListNode* head) {
    if(head == NULL || head->next==NULL) return head;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next && fast->next->next){ // 注意这里条件
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}