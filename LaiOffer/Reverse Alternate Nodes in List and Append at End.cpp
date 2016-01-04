//
//  Reverse Alternate Nodes in List and Append at End.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a linked list, reverse alternate nodes and append at the end
	Example1 Input List:  1  -> 2 ->3->4->5->6
                                   curr  next         nnext
 Output List:                1->3->5->6->4->2
	Example2 Input List:  1->2->3->4->5
	Output List:                1->3->5->4->2
 Step1: create a new list to accommodate the nodes in the even positions.
   2  4  6
 Step 2: (in the meantime, you need to link 1->3->5). be careful about the corner case
 Step 3:  connect the two short linked list
	Example1 Input List:  1  ->  2   ->3->4->5->6
                      curr  next    nnext
 Output List:                1->3->5->6->4->2
	Example2 Input List:  1->2->3->4->5

 Output List:                1->3->5->4->2
 public ListNode change (ListNode head) {
 if (head == null || head.next == null)
 return head;
 ListNode evenHead = null;
 ListNode cur = head;
 ListNode next = cur.next;
 ListNode nnext = null;
 while (cur != null && next != null)
 {
 nnext = next.next;
 next.next = evenHead;
 evenHead = next;
 cur.next = nnext;
 if (nnext == null)
 break;
 cur = nnext;
 next = cur.next;
 }
 cur.next = evenHead;   // cur can be null or not????
 return head;
 }

 Node* Reverse(Node* root) {
 if (root == NULL || root->next == NULL) {
	return root;
	}
 Node* even_head = NULL;
 Node* curr = root;
 while (curr &&  curr->next) {
 Node* nnext = curr->next->next;
 curr->next->next = even_head;
 even_head = curr->next;
 curr->next = nnext;
 if (nnext == NULL)
 break;  // curr is still not NULL
 curr = nnext;
	}
	curr->next = even_head;
 return root;
 }

 */