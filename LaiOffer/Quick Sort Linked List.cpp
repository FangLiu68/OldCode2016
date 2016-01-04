//
//  Quick Sort Linked List.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/7/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a singly-linked list, where each node contains an integer value, sort it in ascending order. The quick sort algorithm should be used to solve this problem.

 Examples

 null, is sorted to null
 1 -> null, is sorted to 1 -> null
 1 -> 2 -> 3 -> null, is sorted to 1 -> 2 -> 3 -> null
 4 -> 2 -> 6 -> -3 -> 5 -> null, is sorted to -3 -> 2 -> 4 -> 5 -> 6
 */


#include "Header.h"
#include <iostream>
using namespace std;

ListNode* combine(ListNode* one, ListNode* two, ListNode* pivot) {
    if (!one) {
        pivot->next = two;
        return pivot;
    }
    ListNode* oneTail = one;
    while (oneTail->next) {
        oneTail = oneTail->next;
    }
    oneTail->next = pivot;
    pivot->next = two;
    return one;
}

ListNode* quickSort(ListNode* head) {
    if (!head|| !head->next) {
        return head;
    }
    ListNode* pivot = head;
    ListNode* smallDummy = new ListNode(0);
    ListNode* largeDummy = new ListNode(0);
    ListNode* smallCur = smallDummy;
    ListNode* largeCur = largeDummy;
    while (head->next) {
        if (head->next->val < pivot->val) {
            smallCur->next = head->next;
            smallCur = smallCur->next;
        } else {
            largeCur->next = head->next;
            largeCur = largeCur->next;
        }
        head = head->next;
    }
    smallCur->next = largeCur->next = NULL;
    ListNode* smallHead = smallDummy->next;
    ListNode* largeHead = largeDummy->next;
    smallDummy->next = NULL;
    largeDummy->next = NULL;
    pivot->next = NULL;
    smallHead = quickSort(smallHead);
    largeHead = quickSort(largeHead);
    return combine(smallHead, largeHead, pivot);
}