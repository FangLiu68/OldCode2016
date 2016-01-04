//
//  Add Two Nums.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 */

#include "Header.h"
#include "LinkedList.h"


// time complexity O(m+n), space complexity O(1)
ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    ListNode dummy(-1);
    ListNode* pre = &dummy;
    int carry = 0;
    while(l1 || l2){
        int val1 = (l1!=NULL)?(l1->val):0;
        int val2 = (l2!=NULL)?(l2->val):0;
        int res = val1 + val2 + carry;
        int val = res%10;
        carry = res/10;
        pre->next = new ListNode(val);
        
        pre = pre->next;
        if(l1) l1 = l1->next; // if(l1)不能少
        if(l2) l2 = l2->next;
    }
    if(carry)   pre->next = new ListNode(carry);
    return dummy.next;
}
