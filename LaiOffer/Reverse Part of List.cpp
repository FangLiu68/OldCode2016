//
//  Reverse Part List.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Reverse a linked list from position m to n. Do it in-place and in one-pass.
 For example:
 Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 return 1->4->3->2->5->NULL.

 Note:
 Given m, n satisfy the following condition:
 1 ≤ m ≤ n ≤ length of list.
 */

#include "Header.h"
#include "LinkedList.h"

/*
 1->2->3->4->5->NULL
 m     n
 用两个指针nodeM、nodeN分别指向位置在m和n的结点
 记得保存nodeM之前和nodeN之后的结点
 对nodeM、nodeN之间的子链表进行reverse，参考reverse linked list
 */
//O(n) runtime, O(1) space
ListNode* reverseBetween1(ListNode* head, int m, int n) {
    if(head == NULL || m==n) return head;
    ListNode dummy(INT_MIN);
    ListNode* pre = &dummy;
    ListNode* nodeM = head;
    pre->next = nodeM;

    // nodeM move forward to position m, pre point to position m
    for(int i=0; i < m-1; i++){
        pre = nodeM;
        nodeM = nodeM->next;
    }

    // nodeN move forward to position n, nxt is right after position n
    ListNode* nodeN = nodeM;
    for(int i=0; i < n-m; i++)
        nodeN = nodeN->next;
    ListNode* nxt = nodeN->next;

    // reverse the sublist from position m to position n
    // remember: always keep the "next node" before u wanna change any pointer's direction
    pre->next = nodeN;
    pre = nodeM;
    ListNode* cur = nodeM->next;
    while(cur != nxt){
        ListNode* temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    nodeM->next = nxt;

    return dummy.next;
}

/*
 m         n
 1 -> 2 -> 3 -> 4 -> 5 -> NULL
 pre nodeM  nxt
 主要目的是nxt指向pre->next. 为了满足这个指针的变化，转换的同时必须更新指向nxt的结点和nodeM所指向的结点。
 所以
 在每次更新nxt的next指向之前，都必须更新nodeM的next指向（直到nodeM指向位置n的下一个结点为止）
 而每次更新nxt的next指向之后，都必须更新pre的next指向（直到pre指向位置n的结点为止）
 */
// time complexity O(N), space complexity O(1)
ListNode *reverseBetween2(ListNode *head, int m, int n){
    if(head == NULL || m==n) return head;
    ListNode dummy(INT_MIN);
    ListNode* pre = &dummy;
    ListNode* nodeM = head;
    pre->next = nodeM;

    // nodeM move forward to position m, pre point to position m
    for (int i = 0; i < m-1; i++){
        pre = nodeM;
        nodeM = nodeM->next;
    }

    for (int i = m; i < n; i++){
        ListNode* nxt = nodeM->next; // 保存3

        nodeM->next = nxt->next; // 2连到4
        nxt->next = pre->next; // 3连到2
        pre->next = nxt; // 1连到3
    }
    return dummy.next;
}