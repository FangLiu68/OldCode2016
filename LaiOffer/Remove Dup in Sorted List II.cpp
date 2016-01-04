//
//  Remove Dup in Sorted List II.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

 For example,
 Given 1->2->3->3->4->4->5, return 1->2->5.
 Given 1->1->1->2->3, return 2->3.
 */

#include "Header.h"
#include "LinkedList.h"
/*
 是重复的元素就全部移掉，前面有一道是移掉多余的重复元素，保留一个。
 这道题的关键就需要注意保存重复元素的前一个指针，这样才能移除元素。
 */

/*
 Given 1->1->1->2->3, return 2->3.
 cur指向重复数字中的第一个1，第一个while把cur后面的重复的1全部删除，此时还剩下cur没有删除
 需要用一个bool来tag此cur是不是重复中的一个
 如果是，删除cur，同时continue.注意这里continue的用法，直接跳过后面非重复的情况
 如果cur开始的不是dup node，直接把pre和cur同时向后移
 */
// time complexity O(N), space complexity O(1)
ListNode *deleteDuplicates(ListNode *head) {
    if(head == NULL || head->next==NULL) return head;
    ListNode dummy(INT_MIN);
    ListNode* pre = &dummy;
    pre->next = head;
    ListNode* cur = head;
    while(cur){
        bool dup = false;

        // if cur starts from dup nodes
        while(cur->next!=NULL && cur->next->val == cur->val){ // delete first two 1
            dup = true;
            ListNode* temp = cur;
            cur = temp->next;
            delete temp;
        }
        if(dup){ // delete last 1
            pre->next = cur->next;
            delete cur;
            cur = pre->next;
            continue;
        }

        // if cur is not one of the dup nodes
        pre = cur;
        cur = pre->next;
    }
    return dummy.next;
}

