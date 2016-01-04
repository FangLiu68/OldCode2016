//
//  Add Two ListsII.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/14/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Add two Lists II

 1 -> 2 -> 3 -> null
 0 -> 7 -> 8 -> null

 123 + 78 = 201
 2 -> 0 -> 1 -> null

 Method 3: 递归做法还没写
 1). Recursion.
 2). a’s length - b’s length = 1
 */

#include "Header.h"

// Method 2: Stack.
// push both lists' value into two stacks, then add each one's top value
ListNode* addLists_stack(ListNode* node1, ListNode* node2){
    if(node1 == NULL) return node2;
    if(node2 == NULL) return node1;
    ListNode* cur1 = node1;
    ListNode* cur2 = node2;
    stack<int> stk1;
    while(cur1){
        stk1.push(cur1->val);
        cur1 = cur1->next;
    }
    stack<int> stk2;
    while(cur2){
        stk2.push(cur2->val);
        cur2 = cur2->next;
    }
    ListNode dummy(INT_MIN);
    ListNode* cur = &dummy;
    int carry = 0;
    while(!stk1.empty() || !stk2.empty()){
        int val1 = stk1.empty()? 0 : stk1.top();
        int val2 = stk2.empty()? 0 : stk2.top();
        int val = val1 + val2 + carry;
        carry = val / 10;
        cur->next = new ListNode(val % 10);
        cur = cur->next;
        if(!stk1.empty()) stk1.pop();
        if(!stk2.empty()) stk2.pop();
    }
    if(carry > 0) cur->next = new ListNode(1);
    return dummy.next;
}

/*
 Method 1: reverse both list, add two lists I, reverse back.
 4->7->8 list1
 5->9->4 list2
 运行之后不能改变list1/list2的原始指向
 */
ListNode* addLists_reverse(ListNode* head1, ListNode* head2){
    if(head1 == NULL){
        return head2;
    }else if(head2 == NULL){
        return head1;
    }

    // head1=4,head2 = 5
    ListNode* newHead1 = reverseList_iter(head1);
    ListNode* newHead2 = reverseList_iter(head2);
    // head1=4, newHead1 = 8; head2 = 5, newHead2 = 4

    ListNode dummy(INT_MIN);
    ListNode* cur = &dummy;
    int carry = 0;

    // 注意这里要用local variable指向newHead1/newHead2从而同时后移，newHead1/newHead2不能动
    ListNode* cur1 = newHead1;
    ListNode* cur2 = newHead2;
    // head1=4, newHead1 = 8, cur1=8; head2 = 5, newHead2=4, cur2=4

    while(cur1 || cur2){
        int val1 = cur1 ? cur1->val : 0;
        int val2 = cur2 ? cur2->val : 0;
        int val = val1 + val2 + carry;
        carry = val / 10;
        cur->next = new ListNode(val % 10);
        cur = cur->next;
        if(cur1) cur1 = cur1->next;
        if(cur2) cur2 = cur2->next;
    }
    // cur1=NULL, cur2=NULL
    if(carry > 0) cur->next = new ListNode(1);

    // reverse back
    head1 = reverseList_iter(newHead1);
    head2 = reverseList_iter(newHead2);
    return reverseList_iter(dummy.next);
}

/*
int main(){
    ListNode* node1 = new ListNode(4);
    ListNode* node2 = new ListNode(7);
    ListNode* node3 = new ListNode(8);
    ListNode* node4 = new ListNode(5);
    ListNode* node5 = new ListNode(9);
    ListNode* node6 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node4->next = node5;
    node5->next = node6;
    ListNode* res = addLists_reverse(node1, node4);
    while(res){
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}*/