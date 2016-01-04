//
//  Intersection of Two Lists.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Write a program to find the node at which the intersection of two singly linked lists begins.
 For example, the following two linked lists:
 A:      a1 → a2
                ↘
                c1 → c2 → c3
                ↗
 B: b1 → b2 → b3
 begin to intersect at node c1.
 Notes:
 If the two linked lists have no intersection at all, return null.
 The linked lists must retain their original structure after the function returns.
 You may assume there are no cycles anywhere in the entire linked structure.
 Your code should preferably run in O(n) time and use only O(1) memory.
 */

#include "Header.h"

// O(n) runtime, O(1) space
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA==NULL || headB==NULL) return NULL;
    ListNode* curA = headA;
    ListNode* curB = headB;
    int lenA = 1;
    int lenB = 1;
    while(curA->next){
        lenA++;
        curA = curA->next;
    }
    while(curB->next){
        lenB++;
        curB = curB->next;
    }
    if(curA != curB){
        return NULL;
    }

    curA = headA, curB = headB;
    int gap = (lenA>=lenB)?(lenA-lenB):(lenB-lenA);
    if(lenA>=lenB)
        for(int i=0; i<gap; i++) curA = curA->next;
    else
        for(int i=0; i<gap; i++) curB = curB->next;

    while(curA != curB){
        curA = curA->next;
        curB = curB->next;
    }
    return curA;
}

