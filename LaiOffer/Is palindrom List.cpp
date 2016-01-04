//
//  Is palindrom List.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a linked list, check whether it is a palindrome.  Space O(1)
 Example
 Input a → b → c → b → a
 output: True.
 Input a → b →c ->null          c ->b  → a ->null
 a-> b-> c
 output: False
   public static boolean checkPalindrome (LinkedList  head) {
	boolean odd = true;
	// find the middle node;
	LinkedList fast = head.next;
	LinkdList slow = head;
	while (fast != null || fast.next != null) {
 fast == fast.next.next;
 slow = slow.next;
	}
	if(fast.next == null){
 odd = false;
	}
	// reverse linkedlist
	LinkedList second = slow.next;
	slow.next = null;
	LinkedList first = head;
	reverse(second);
	// compare one by one;
	return compare(first, second);
 }
 public static void reverse (LinkedList second) {
 LinkedList pre = null;
 LinkedList cur = second;
 while (cur != null) {
 LinkedList next = cur.next;
 cur.next = pre;
 pre = cur;
 cur = next;
	}
	return pre;
 }
 public static boolean compare (LinkedList first , LinkedList second){
 while(first != null && second != null){
	if (first.val != second.val ){
 return false;
	}
 first  = first.next;
 second = second.next;
	}
	return true;
 }
 Method 3
 // Initial parameters to this function are &head and head
 00 bool isPalindromeHelper(Node*& left, Node *right) {
 01   if (right == NULL) // base case
 02 return true;
 03   // If sub-list is not palindrome then no need to
 04   // check for current left and right, return false
 05   bool isp = isPalindromeHelper(left, right->next);
 06   if (isp == false)
 07      return false;
 08   // Check values at current left and right
 09   bool isp1 = (right->data == left->data);
 10   left = left->next;
 11   return isp1;
 12 }
 // A wrapper over isPalindromeUtil()
 bool isPalindrome(Node *head) {
   isPalindromeHelper(&head, head);
 }
 Level 1     a → b → c → b → a
         r       l
 Level 2     a → b → c → b → a
             r   l
 Level 3     a → b → c → b → a
                 lr
 Level 4     a → b → c → b → a
                     r
       l
 Level 5     a → b → c → b → a
             l           r
 Level 6     a → b → c → b → a  null
   l   r base case;
*/
 