//
//  Remove Nodes by Indices.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/30/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 4.2 remove all nodes by indices.

 1 -> 2 -> 3 -> 4 -> 5 -> null, indices needed to be deleted: {1, 3} sorted in ascending order.
 1 -> 3 -> 5 -> null
 */

#include "Header.h"
#include "LinkedList.h"


ListNode* remove_indices(ListNode* head, vector<int> indices){
    if(head == NULL || indices.empty()){
        return NULL;
    }

    ListNode dummy(INT_MIN);
    ListNode* cur = &dummy;
    cur->next = head;
    int count = 0; // 代表原始list上的每个节点的index(所以不论其对应的value是否需要删除，他都应该每次往后移动一位)
    int countIndex = 0; // 代表vector里的indices的序号(所以只有当这个序列号已经被删除了，才往后移动一位)
    while(cur->next && countIndex<indices.size()){
        if(count == indices[countIndex]){
            ListNode* temp = cur->next;
            cur->next = temp->next;
            delete temp;
            temp = NULL;
            countIndex++;
        }else{
            cur = cur->next;
            //count++;
        }
        count++;
    }
    return dummy.next;
}

/*
int main(){
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(5);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    vector<int> v = {1,3};
    ListNode* res = deleteAllIndices(head, v);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}*/