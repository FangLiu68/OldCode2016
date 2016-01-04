//
//  Reverse Linked List.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/7/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// reverse a single linked list

#include "Header.h"

//        1 -> 2 -> 3 -> 4 -> NULL
// NULL<- 1 <- 2 <- 3 <- 4

/*

 1st call R-func:    NULL  ←     Node1 ←    Node2 ←    Node3                newHead=N3
                                 head       next
 ======================================================================================
 2nd call R-func:                Node1 →    Node2 ←    Node3                newHead=N3
                                            head       next
 ======================================================================================
 3rd call R-func:                Node1 →    Node2 →     Node3→     NULL     newHead=N3
                                                        head       next


 */

// use recursion. O(N) runtime
ListNode* reverseList_recur(ListNode* head){
    // base case
    if(head == NULL || head->next == NULL) return head;

    ListNode* cur_node = head;
    ListNode* next_node = head->next;
    ListNode* nodeN = reverseList_recur(next_node); // recursion的是next_node，那么由base case判断条件得知，当next_node为最后一个节点是时候，触底反弹，返回当前node(就是这个next_node).而cur_node一直都是next_node之前的那个node

    // 这两行current状态要做的事情。nodeN从最后一步一直往前传，但在current reverse指针的时候nodeN没有参与，我们只是不断把nodeN的值传过来而已
    // 下面这俩的顺序不能反！否则会出错，还没仔细看为啥
    next_node->next = cur_node;
    cur_node->next = NULL;

    return nodeN;
}

ListNode* reverseList_iter(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* prev = NULL;
    ListNode* cur = head;
    while (cur != NULL) {
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev; // new head after reversing the whole linkedlist
}


