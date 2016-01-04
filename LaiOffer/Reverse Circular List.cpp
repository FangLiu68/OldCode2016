//
//  Reverse Circular List.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/14/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Reverse Circular Linked List

 1  <- 2 <- 3 <- 1
           p      h
 1 <- 2 <- 3 <- 1

 convert to non-circular list
 convert back

 1 -> 2 -> 3 -> 1
 p    c
 */

#include "Header.h"
#include "LinkedList.h"


ListNode* reverse(ListNode* root) {
    if (root == NULL || root->next == NULL) {
        return root;
    }
    ListNode* prev = root;
    ListNode* cur = root->next;
    ListNode* stop = cur;
    while (true) {
        ListNode* post = cur->next;
        cur->next = prev;
        prev = cur;
        cur = post;
        if (cur == stop) {
            break;
        }
    }
    return prev;
}
