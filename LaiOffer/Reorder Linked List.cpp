//
//  Reorder Linked List.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/19/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Reorder the given singly-linked list N1 -> N2 -> N3 -> N4 -> … -> Nn -> null to be N1- > Nn -> N2 -> Nn-1 -> N3 -> Nn-2 -> … -> null

 Examples
 L = null, is reordered to null
 L = 1 -> null, is reordered to 1 -> null
 L = 1 -> 2 -> 3 -> 4 -> null, is reordered to 1 -> 4 -> 2 -> 3 -> null
 L = 1 -> 2 -> 3 -> null, is reordred to 1 -> 3 -> 2 -> null
 */

#include "Header.h"


/*
 So the algorithm implemented below can be summarized as:
 Step 1  Find the middle pointer of the linked list (you can use the slow/fast pointers)
 Step 2  Reverse the second part of the linked list (from middle->next to the end)
 Step 3  Do the reordering. (inset every element in the second part in between the elements in the first part)
 */

ListNode* find_mid_node(ListNode* head);
ListNode* reverseList(ListNode* head);
ListNode* merge_two_lists(ListNode* one, ListNode* two);

ListNode* reorder(ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    ListNode* mid = find_mid_node(head);
    ListNode* one = head;
    ListNode* two = mid->next;
    mid->next = NULL; // de-link the second half from the list
    two = reverseList(two);
    return merge_two_lists(one, two);
}

ListNode* find_mid_node(ListNode* head){
    if(head == NULL){
        return NULL;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* reverseList(ListNode* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    ListNode* pre = NULL;
    ListNode* cur = head;
    while(cur){
        ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

// 注意这里是怎么两两交错merge的. cur = cur->next->next
ListNode* merge_two_lists(ListNode* one, ListNode* two){
    if(one == NULL) return two;
    if(two == NULL) return one;
    ListNode dummy(INT_MIN);
    ListNode* cur = &dummy;
    while(one && two){
        ListNode* one_next = one->next;
        ListNode* two_next = two->next;

        cur->next = one;
        cur->next->next = two;
        one = one_next;
        two = two_next;

        cur = cur->next->next;
    }
    
    cur->next = one ? one : two;

    return dummy.next;
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
    ListNode* res = reorder(node1);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}*/