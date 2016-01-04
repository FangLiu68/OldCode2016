//
//  Delete Node in List.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/3/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Delete a node in a linked list, given only the pointer to the node which should be deleted.

#include "Header.h"

void delete_mid_node(ListNode* pDelete){
    if(pDelete == NULL){
        return;
    }
    if(pDelete->next){
        ListNode* pnext = pDelete->next->next;
        ListNode* remove = pDelete->next;
        pDelete->val = remove->val;
        pDelete->next = pnext;
        delete remove;
        remove = NULL;
    }
}