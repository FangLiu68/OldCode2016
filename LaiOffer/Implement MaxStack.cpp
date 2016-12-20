//
//  Implement MaxStack.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/2/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 The MaxStack is a stacklike data structure that also allows stacklike access to the elements by their value. Push, peek, pop, peekMax and popMax.
 
 For example, given a stack of {1, 3, 2, 5, 3, 4, 5, 2}
 peek() -> 2, peekMax() -> 5
 pop() -> 2; peek() -> 5, peekMax() -> 5
 pop() -> 5; peek() -> 4, peekMax() -> 5
 push(6); peek() -> 6, peekMax() -> 6
 popMax() -> 6; peek -> 4, peekMax() -> 5
 popMax() -> 5; peek -> 4, peekMax() -> 4

 重点是popMax()
 
 Min Stack
 https://leetcode.com/problems/min-stack/
 
 Map and (Doubly) LinkedList
 
 Max Stack
 Stack/DLL and heap/Tree (PriorityQueue and TreeSet)
 
 First non-repeated object in stream
 Or first non repeated character in string
 http://www.geeksforgeeks.org/given-a-string-find-its-first-non-repeating-character/
 Map + Doubly linked list
 
 Retain Best Cache/LRU
 Map + sorted data structure (e.g. DLL, treeset/heap)
 
 Design a data structure that supports add(T val), remove(T val) and T removeRandomElement() all in O(1) time.
 
 Challegen:
 Ask -goal, assumption/access pattern, example
 Workable solution/optimize
 In-sync
 Hybrid data strcuture >1 internal datastructure
 Practice.
 
 

 */