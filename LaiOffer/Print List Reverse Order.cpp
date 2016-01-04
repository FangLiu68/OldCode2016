//
//  Print List Reverse Order.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/14/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Print a linked list in reverse order.
 1. recursion
 2. stack
 3. iterative
 a. reverse first; b. print; 3. reverse back
 */

#include "Header.h"

// recursion
void print_reverseOrderList_recur(ListNode* head){
    if(head == NULL){
        return;
    }

    print_reverseOrderList_recur(head->next);
    cout << head->val << endl;
}

// use stack
void print_reverseOrderList_stack(ListNode* head){
    if(head == NULL){
        return;
    }
    stack<int> stk;
    ListNode* cur = head;
    while(cur){
        stk.push(cur->val);
        cur = cur->next;
    }
    while(!stk.empty()){
        cout << stk.top() << endl;
        stk.pop();
    }

}

// iterative 1->2->3->4
void print_reverseOrderList_iter(ListNode* head){
    if(head == NULL){
        return;
    }

    // reverse list
    ListNode* pre = NULL;
    ListNode* cur = head; // cur=head=1
    /*
     cur在function之外是看不见的。通过移动cur同时改变指针的指向，就改变了整个list的方向，这在function之外也同样改变了。
     因为cur开始指向head，首先改变head指向，然后cur后移。所以在外界看来，input head指向的原始头结点的指向变了，但指向head的指针并没有往后移动(移动的是cur，which is local variable)
     所以如果input 1->2->3，那么下面的循环结束后，如果在外界重新call print node1的话，只能print出1(此时head的next是NULL)
     所以，如果我们要用这种方法print linked list的话，我们还要reverse back
     */
    // before while(), pre=NULL, cur=1
    while(cur){
        ListNode* p_next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = p_next;
    }
    // after while(), pre=4, cur=NULL

    // print list
    ListNode* new_head = pre;
    while(new_head){
        cout << new_head->val << endl;
        new_head = new_head->next;
    }

    // after print, pre=4, cur=NULL

    // reverse back 1<-2<-3<-4
    while(pre){
        ListNode* p_next = pre->next;
        pre->next = cur;
        cur = pre;
        pre = p_next;
    }
}
/*
int main(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    print_reverseOrderList_iter(node1);
    cout << "TEST" << endl;
    while(node1){
        cout << node1->val << endl;
        node1 = node1->next;
    }
    cout << endl;
    return 0;
}*/