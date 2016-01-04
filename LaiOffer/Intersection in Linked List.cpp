//
//  Intersection in Linked List.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/7/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// find a intersection in two linked list, otherwise return NULL

#include "Header.h"
#include <iostream>
using namespace std;

ListNode* merge_node_in_list(ListNode* headA, ListNode* headB){
    if(headA==NULL || headB==NULL){
        return NULL;
    }
    ListNode* cur1 = headA;
    ListNode* cur2 = headB;
    int len1 = 1;
    int len2 = 1;
    while(cur1){
        len1++;
        cur1 = cur1->next;
    }
    while(cur2){
        len2++;
        cur2 = cur2->next;
    }

    if(cur1 != cur2){
        return NULL; // no intersection
    }

    cur1 = headA;
    cur2 = headB;
    int gap = abs(len1-len2);
    if(len1 > len2){
        for(int i=gap; i>0; --i){
            cur1 = cur1->next;
        }
    }else{
        for(int i=gap; i>0; --i){
            cur2 = cur2->next;
        }
    }

    while(cur1 != cur2){
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;
}

