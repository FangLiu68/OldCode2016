//
//  Heap Implementation.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/9/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Heap is a binary tree based data structure
 Across the entire tree, the relation between a parent node and a child node stays consistent.

 Min Heap:
 1. the parent node is always <= its two child node (parent node is the smallest node in the subtree roted at itself)
 2. the relation between the two child nodes can differ
 
 The commen implementation of a heap is using a complete binary tree
 a complete binary tree: a binary tree in which every level, except possibly the last level, is completely filled, and all nodes are as far left as possible.
 
 O(1) access min(min heap), max(max heap)
 O(logN) delete min/max, add new element.
 */

/*
 Representation:
 it can also be represneted as an array (by the level order tarversal of the binary tree) since it is a complete binary tree.

 child index → parent index
 parent = (child - 1) / 2

 parent index → children index
 left child = parent * 2 + 1
 right child = parent * 2 + 2

 basic internal operations of heap:
 percolateUp(int index)
 offer()
 update()

 percolateDown(int index)
 poll()
 update()
 heapify()

 index of parent = i, then:
 left child = 2*i + 1;
 right child = 2*i + 2;
 parent = (child-1)/2
 the root of the tree is at index 0.
 */

 /*
 Basic Heap Internal Operations:
 percolateUp()
 when to use:
 the element need to be moved up to maintain the heap's property. eg, add new element to heap (to the last position)
 how:
 compare the element with its parent, move it up when necessary. do this until the element does not need to be moved.
 
 percolateDown()
 when to use:
 the element need to be moved down to maintain the heap's property. eg, remove the top element from the heap (then move the last element to the top position)
 */

 /*
  Heapify()
  convert an array into a heap in O(N) time

  how?
  for each node that has at least one child, we perform percolateDown() action, in the order of from the nodes on teh deepest level to the root.
  
  time complexity of heapify() is O(N)
  
  注意：如果想implement min heap，就对所有非叶子节点按照从后往前的顺序做percolateDown()的操作
                    10
            /             \
           11               7
       /        \        /      \
     2          8      4         6
   /      \
  13       3
  例如上面这个树，要按照2，7，11，10的顺序进行percolateDown()的操作直到2，7，11，10都走到正确的位置上
  
  if array size is n, the range of indices need to perform percolateDown() is [0, n/2 - 1]
  */
