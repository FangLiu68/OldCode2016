//
//  Insertion Sort Linked List.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include "Header.h"


// time complexity O(N^2), space complexity O(1)
ListNode* findInsertPos(ListNode* head, int x);

ListNode *insertionSortList(ListNode *head) {
    if(head==NULL) return NULL;
    ListNode dummy(INT_MIN); // 注意这里dummy的值要设置成INT_MIN
    ListNode* cur = head;
    while(cur){
        ListNode* pos = findInsertPos(&dummy, cur->val); // dummy永远代表最前面的那个节点，但我们返回的pos是需要插入的位置
        ListNode* curNext = cur->next;
        cur->next = pos->next;
        pos->next = cur;
        cur = curNext;
    }
    return dummy.next;
}
// 找到需要插入的位置。x应该插入pre之后
ListNode* findInsertPos(ListNode* head, int x){
    ListNode* pre = NULL;
    ListNode* cur = head;
    while(cur && cur->val<=x){
        pre = cur;
        cur = cur->next;
    }
    return pre; // the node which x should be inserted after
}
