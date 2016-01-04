//
//  Merge Two Lists Alternatively.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include "Header.h"
#include "LinkedList.h"



/*
 l1 = 1 2 3 4 5; 
 l2 = 6 7; 
  l = 1 6 2 7 3 4 5

 l1 = 1 2; 
 l2 = 3 4 5 6 7; then 
  l = 1 3 2 4 5 6 7
 */

ListNode* merge_two_lists_alternatively(ListNode* one, ListNode* two){
    if(one == NULL) return two;
    if(two == NULL) return one;
    ListNode dummy(INT_MIN);
    ListNode* cur = &dummy;
    while(one && two){
        ListNode* one_next = one->next;
        ListNode* two_next = two->next;

        cur->next = one;
        cur->next->next = two;
        one = one_next;
        two = two_next;

        cur = cur->next->next;
    }

    cur->next = one ? one : two;

    return dummy.next;
}


// time complexity O(N), space complexity O(1)
void merge_two_list_alternatiely(ListNode* l1, ListNode* l2){
    if(l1==NULL || l2==NULL) return;
    ListNode* cur1 = l1;
    ListNode* cur2 = l2;
    ListNode* cur1_next = NULL;
    ListNode* cur2_next = NULL;
    while(cur1 && cur2){
        cur1_next = cur1->next;
        cur2_next = cur2->next;

        if(cur1_next==NULL && cur2->next){
            cur1->next = cur2;
            break;
        }

        cur1->next = cur2;
        cur2->next = cur1_next;

        cur1 = cur1_next;
        cur2 = cur2_next;
    }
}