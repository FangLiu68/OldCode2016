//
//  Find Nth Node From End of List.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// find the nth to last element of a single linked list.

#include "Header.h"

// 这里没说n是永远有效的，所以要考虑n是否超过链表长度的情况
ListNode* find_nth_node_from_end_of_list(ListNode* pHead, int n){
    if(pHead==NULL || n<=0) return NULL;
    ListNode* fast = pHead;
    ListNode* slow = pHead;
    for(int i=0; i<n-1; i++){
        if(fast==NULL){
            return NULL;
        }
        fast = fast->next;
    }
    if(fast==NULL) { // n==len+1
        return NULL;
    }
    while(fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}