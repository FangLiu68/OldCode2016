//
//  Merge Two Sorted Linked Lists.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/7/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Merge two sorted lists into one large sorted list.

 Examples
 L1 = 1 -> 4 -> 6 -> null, L2 = 2 -> 5 -> null, merge L1 and L2 to 1 -> 2 -> 4 -> 5 -> 6 -> null
 L1 = null, L2 = 1 -> 2 -> null, merge L1 and L2 to 1 -> 2 -> null
 L1 = null, L2 = null, merge L1 and L2 to null
 */

#include "Header.h"

ListNode* merge(ListNode* one, ListNode* two) {
    if(one == NULL) return two;
    if(two == NULL) return one;

    ListNode dummy(INT_MIN);
    ListNode* cur = &dummy;

    while(one && two){
        if(one->val <= two->val){
            cur->next = one;
            one = one->next;
        }
        else{
            cur->next = two;
            two = two->next;
        }
        cur = cur->next;
    }

    cur->next = one ? one : two;

    return dummy.next;
}