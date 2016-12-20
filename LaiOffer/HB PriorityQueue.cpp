//
//  HB PriorityQueue.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/1/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 To Implement a data structure that can
 void insert(int) - insert a new element
 int median() - get the median of all the inserted elements
 
 median:
 sorted(fully/partially),
 size of left partition == size of right partition.
 maximum value of left partition
 minimum value of right partition

 we use two heap: minheap and maxheap
 operations:
 getMin()/ pollMin() in minheap
 getMax()/ pollMax() in maxheap
 insert() in min/maxheap
 
 can we use a balanced BST?
 median() - two BST, getMin() + getMax() - O(logN) in BST(but O(1) in heap)
 */