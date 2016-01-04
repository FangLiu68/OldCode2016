//
//  Selection Sort Linked List.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/7/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include "Header.h"
#include <iostream>
using namespace std;

void replace(ListNode* one, ListNode* two) {
    if (one == two) {
        return;
    }
    if (two == one->next) {
        ListNode* tmp = two->next->next;
        one->next = two->next;
        two->next->next = two;
        two->next = tmp;
        return;
    }
    ListNode* oneNext = one->next;
    ListNode* oneNextNext = one->next->next;
    ListNode* twoNext = two->next;
    ListNode* twoNextNext = two->next->next;
    one->next = twoNext;
    twoNext->next = oneNextNext;
    two->next = oneNext;
    oneNext->next = twoNextNext;
}

ListNode* selectionSortListH(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* cur = dummy;
    while (cur->next) {
        ListNode* temp = cur;
        ListNode* min = cur;
        while (temp->next) {
            if (temp->next->val < min->next->val) {
                min = temp;
            }
            temp = temp->next;
        }
        replace(cur, min);
        cur = cur->next;
    }
    return dummy->next;
}

ListNode* selectionSort(ListNode* a) {
    return selectionSortListH(a);
}