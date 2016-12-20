//
//  Odd Even Linked List.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/3/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
 
 You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
 
 Example:
 Given 1->2->3->4->5->NULL,
 return 1->3->5->2->4->NULL.
 
 Note:
 The relative order inside both the even and odd groups should remain as it was in the input.
 The first node is considered odd, the second node even and so on ...
 */

#include "Header.h"

ListNode* oddEvenList(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    ListNode* oddHead = head;
    ListNode* odd = oddHead;
    
    ListNode* evenHead = head->next;
    ListNode* even = evenHead;
    
    while(even && even->next){
        odd->next = even->next;
        odd = odd->next;
        
        even->next = odd->next;
        even = even->next;
    }
    
    odd->next = evenHead;
    return oddHead;
}