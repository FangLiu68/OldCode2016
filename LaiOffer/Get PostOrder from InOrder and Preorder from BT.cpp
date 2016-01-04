//
//  Get PostOrder from InOrder and Preorder from BT.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given Inorder and Preorder traversals of a binary tree, print Postorder traversal without reconstructing a binary tree.
 Example:
 Input:
 Inorder traversal in[] = {4, 2, 5, 1, 3, 6}
 Preorder traversal pre[] = {1, 2, 4, 5, 3, 6}

 Output:
 Postorder traversal is {4, 5, 2, 6, 3, 1}
 index     0 1  2  3 | 4 5
 in[] =    { 4, 2, 5, 1,| 3, 6}
 pre[] =  { 1, 2, 4, 5,| 3, 6}
      left size == 3   |  right size == 2
 1 == root of the whole tree   →  last node to print out in post-order

 public void postTraverse (int[] inorder, int[] preorder)
 {
 if (inorder == null || inorder.length == 0)
 return;
 traverse (inorder, 0, inorder.length-1, preorder, 0, preorder.length-1);
 }
 public void traverse(int[] inorder, int il, int ir,
                     int[] preorder, int pl, int pr) {
 if (il > ir)
 return;
 int index = findRoot (inorder, preorder[pl], il, ir);
 traverse (inorder, il, index-1, preorder, pl+1, pl+(index-il));
 traverse (inorder, index+1, ir, preorder, pl+index-il+1, pr);
 System.out.print (preorder[pl]+” “);  // print root last;
 }
 public int findRoot (int[] inorder, int root, int il, int ir)
 {
 for(int i=il; i <= ir; i++)
 {
 if (inorder[i] == root)
 return i;
 }
 return -1;
 }

 */