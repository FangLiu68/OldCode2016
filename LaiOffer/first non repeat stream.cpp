//
//  first non repeat stream.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/1/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Q4.2 Given an unlimited stream of characters, find the first non-repeating character from stream. You need to tell the first non-repeating character in O(1) time at any moment.
 (Similar the use of LRU, which is implemented by Doubly Linked List + hash_table)
 0 1 2 3 4
 a b c d a
 a a a a b

 200,000 entry of key  ‘char’     		3 Bytes    600,000
 1MB for key + 5MB values

 When we are scanning a new element “X”, what should we do????
 Solution:
	Case1: X has not been seen yet (1st time see “X”)
 1.1 we insert X in the tail (right end) of the doubly linked list
 1.2 we insert X into the hash_table
	Case2: X has been seen before
 Case 2.1 X has been just seen for the 2nd time
 (1)delete X from the doubly linked list.
 (2) and set the value of  “X” in the hash_table to NULL (which means the letter “x” has been see for  2nd or more times.)
 Case 2.2 X has been seen for the 3rd or more times
	we do nothing


	<key= letter itself,   value = address of the node>

 The answer is the head of the doubly linked list at all times.
 =========================================

 */