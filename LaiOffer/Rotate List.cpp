//
//  Rotate List.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Given a list, rotate the list to the right by k places, where k is non-negative.
// For example: Given 1->2->3->4->5->nullptr and k = 2, return 4->5->1->2->3->nullptr.

#include "Header.h"
#include "LinkedList.h"


/*
 Analysis:
 The idea is to get the whole length of the list, then compute the rotate position.
 And cut the list from the rotate position, link the front part to the last part.

 e.g.
 1->2->3->4->5->null , k =2;
 len = 5;
 rotate pos = 5-2 = 3;

 cut list:  1->2->3  --->  4->5->null
 link :     4->5->1->2->3->null
 */

// 要考虑三种情况：k==len; k==0; k>len; 前两种情况都能归结为k%len==0
// 快慢指针
// time complexity o(n), space complexity O(1)
ListNode *rotateRight_onlinePass(ListNode *head, int k) {
    if(head==NULL || head->next==NULL) return head;
    ListNode dummy(-1);
    dummy.next = head;
    ListNode* p = &dummy;

    int len = 0;
    for(;head; head=head->next) len++;
    k = k%len;
    if(k==0) return p->next; // 这里不可少！！

    ListNode* slow = p;
    ListNode* fast = p;
    for(int i=0; i<k; i++) fast = fast->next;
    while(fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    ListNode* res = slow->next;
    fast->next = p->next;
    slow->next = NULL;
    return res;
}


int getListLength(ListNode *h){
    int len = 0;
    for ( ; h; h = h->next) len++;
    return len;
}
ListNode *rotateRight(ListNode *head, int k){
    if (!head || !head->next) return head;
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *pre = &dummy;

    int n = getListLength(head);
    k %= n;
    for (k--; k &&  head->next; k--) head = head->next;

    while (head->next){
        head = head->next;
        pre = pre->next;
    }
    ListNode *h = pre->next;
    pre->next = nullptr;
    head->next = dummy.next;

    return h;
}


ListNode *rotateRight1(ListNode *head, int k) {
    //Special treatment
    if(head==NULL)  return NULL;

    //initialization variables
    ListNode *cur = head;
    ListNode *pre = head;
    int i = 1, j = 1;

    //1. Normal situation
    for(; cur->next!=NULL; i++, cur=cur->next)
    {
        if((i-j)==k){
            j++;
            pre=pre->next;
        }
    }

    //2. special situation1
    if(i==k) return head;

    //3. special situation2
    if(k>i){
        k%=i;
        while ((i-j)!=k){
            j++;
            pre=pre->next;
        }
    }

    //connect new link
    cur->next = head;
    head = pre->next;
    pre->next = NULL;

    return head;
}

ListNode* rotate_list2(ListNode* pHead, int k){
    if(pHead == NULL) return NULL;
    int len = 0;
    ListNode* cur = pHead;
    while(cur){
        len++;
        cur = cur->next;
    }
    int cutPoint;
    if(k==len) return pHead;
    else
        cutPoint = len-k%len-1;
    cur = pHead;
    while(cutPoint>0){
        cur = cur->next;
        cutPoint--;
    }
    // new head
    ListNode* newHead = cur->next;
    ListNode* tail = cur;
    while(cur->next) cur = cur->next;
    cur->next = pHead;
    tail->next = NULL;
    return newHead;
}



/*
 int main(){
 ListNode* node1 = new ListNode(1);
 ListNode* node2 = new ListNode(2);
 ListNode* node3 = new ListNode(3);
 ListNode* node4 = new ListNode(4);
 ListNode* node5 = new ListNode(5);
 node1->pNext = node2;
 node2->pNext = node3;
 node3->pNext = node4;
 node4->pNext = node5;
 ListNode* result = rotate_list(node1, 0);
 while(result){
 cout << result->mValue << " ";
 result = result->pNext;
 }
 cout << endl;
 return 0;
 }*/