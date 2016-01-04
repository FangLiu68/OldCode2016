//
//  Merge K Sorted Lists.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Merge K sorted lists into one big sorted list in ascending order.
 Assumptions
 None of the lists is null.
 */

#include <iostream>
#include <vector>
#include <queue>
#include "Header.h"
using namespace std;

/*
 O(nk log k) runtime, O(k) space – Heap:
 We could use a min heap of size k. 
 The heap is first initialized with the smallest element from each list. 
 Then as we extract the nodes out from the heap, we must remember to insert its next node into the heap.
 As each insert operation into the heap costs log(k) and there are a total of nk elements, the total runtime complexity is O(nk log k).
 Ignoring the extra space that is used to store the output list, we only use extra space of O(k) due to the heap.
 */
struct comp{
    bool operator()(ListNode* node1, ListNode* node2){
        return node1->val >= node2->val; // min heap
    }
};

ListNode* mergeKLists(vector<ListNode*> &lists) {
    if(lists.empty()) return NULL;
    ListNode dummyNode(INT_MIN);
    ListNode* cur = &dummyNode;

    // push each list's first node into priority queue
    priority_queue<ListNode*, vector<ListNode*>, comp> min_heap;
    for(int i=0; i<lists.size(); ++i){
        if(lists[i])
            min_heap.push(lists[i]); // k size min heap
    }

    while(!min_heap.empty()){
        ListNode* top = min_heap.top();
        if(top->val != cur->val){ // 加了if判断条件去除重复。如果不用care重复的情况的话，去掉if条件(if里面的内容保留)就好
            cur->next = top;
            cur = cur->next;
        }
        min_heap.pop();
        if(top->next){ // push前要check next是否有效
            min_heap.push(top->next);
        }
    }
    return dummyNode.next;
}

/*
int main(){
    ListNode* head1 = new ListNode(1);
    ListNode* head11 = new ListNode(3);
    ListNode* head12 = new ListNode(8);
    head1->next = head11;
    head11->next = head12;
    ListNode* head2 = new ListNode(2);
    ListNode* head21 = new ListNode(4);
    ListNode* head22 = new ListNode(10);
    head2->next = head21;
    head21->next = head22;
    ListNode* head3 = new ListNode(5);
    ListNode* head31 = new ListNode(6);
    ListNode* head32 = new ListNode(9);
    head3->next = head31;
    head31->next = head32;
    ListNode* head1 = new ListNode(-2);
    ListNode* head11 = new ListNode(-1);
    ListNode* head12 = new ListNode(-1);
    ListNode* head13 = new ListNode(-1);
    
    head1->next = head11;
    head11->next = head12;
    head12->next = head13;
    vector<ListNode*> lists;
    lists.push_back(head1);
    lists.push_back(NULL);
    //lists.push_back(head3);
    ListNode* res = merge_k_sorted_lists(lists);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}*/