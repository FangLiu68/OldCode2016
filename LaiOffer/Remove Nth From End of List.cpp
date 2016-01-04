//
//  Remove Nth From End of List.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/* Given a linked list, remove the nth node from the end of list and return its head.
 For example, Given linked list: 1->2->3->4->5, and n = 2.
 After removing the second node from the end, the linked list becomes 1->2->3->5. Note:
 Given n will always be valid. Try to do this in one pass.
 */

#include "Header.h"
#include "LinkedList.h"


// time complexity O(n), space complexity O(1)
ListNode* remove_nth_node_from_end(ListNode* head, int n){
    if(head==NULL || n<=0) return NULL;
    ListNode dummy(INT_MIN);
    dummy.next = head;
    ListNode* slow = &dummy;
    ListNode* fast = &dummy;

    // slow 和 fast都从head之前的dummy开始move，很好地解决了n==len 即删除头结点的问题
    // 只要fast比slow提前N步，不管fast和slow开始是从哪儿出发的，最终当fast到达最后一个节点时，slow会指向被删除节点之前的点
    for(int i=0; i<n; i++){
        if(fast == NULL){
            return NULL;
        }
        fast = fast->next; // 向前移动n步
    }
    while(fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    ListNode* temp = slow->next;
    slow->next = temp->next;
    delete temp;
    temp = NULL;
    return dummy.next;
}

/*
int main(){
    ListNode* node0 = new ListNode(0);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);
    ListNode* node7 = new ListNode(7);
    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;

    ListNode* res = remove_nth_node_from_end(node0, 8);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}*/
