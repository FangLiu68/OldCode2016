//
//  merge sort linked list.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a singly-linked list, where each node contains an integer value, sort it in ascending order. The merge sort algorithm should be used to solve this problem.

 Examples
 null, is sorted to null
 1 -> null, is sorted to 1 -> null
 1 -> 2 -> 3 -> null, is sorted to 1 -> 2 -> 3 -> null
 4 -> 2 -> 6 -> -3 -> 5 -> null, is sorted to -3 -> 2 -> 4 -> 5 -> 6
 */

#include "Header.h"
#include <iostream>
using namespace std;

/*
 merge sort linked list
 双横线以上变了，每行都是O(N)，但upper bound还是NLOGN，时间复杂度不变

 常数空间且O(NlogN)，单链表适合用merge sort，双链表适合用quick sort
 本题可以复用merge two sorted lists的代码

 mergesort linked list和mergesort array的方法是完全一样的。
 1. 找到中间节点，将list/array分成两部分
 2. recrusion地对这两部分进行mergesort
 3. 将有序的两部分（从上一步得到）进行merge，最终成为有序的合体。
 对array的merge部分，用三个指针分别指向A1[index1]和A2[index2]以及res[index]，每次比较A1[index1]和A2[index2]的大小并把较小的元素放在res[index]上，同时前移指针
 对linked list的merge部分，直接参考mergeTwoSortedLinkedList()函数。
 */

ListNode* helper_mergeTwoSortedLists(ListNode* l1, ListNode* l2){
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    ListNode dummy(-1);
    ListNode* head = &dummy;
    while(l1 && l2){
        if(l1->val < l2->val){
            head->next = l1;
            l1 = l1->next;
        }
        else{
            head->next = l2;
            l2 = l2->next;
        }
        head = head->next;
    }
    head->next = (l1==NULL)? l2 : l1;
    return dummy.next;
}

// O(nlogn) runtime, O(1) space
ListNode *sortList(ListNode *head) {
    if(head == NULL || head->next==NULL){
        return head; // 注意：head->next==NULL不能少！
    }

    // seperate list to two parts
    // slow是list后半部分的头结点，所以一定要定义一个pre来记录slow之前的那个节点，从而把两部分lists分开
    ListNode* pre = NULL;
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast && fast->next){
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = NULL;

    // recursively merge two lists
    ListNode* left = sortList(head);
    ListNode* right = sortList(slow);

    // merge two sorted parts
    return helper_mergeTwoSortedLists(left, right);
}

/*
int main(){
    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
   // MergeSortLinkedList(&node1);
    ListNode* cur = sortList(node1);
    while(cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    return 0;
}*/