//
//  Bottom View of Binary Tree.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a Binary Tree, print out the  bottom view of the tree from left to right. A node x is printed out iff x is the deepest node on its column in the tree.
 Examples:
             20(0)
                    /      \
                 8(-1)    22(1)
                /   \             \
             5(-2)   3(0)      25(2)
                     /     \
                10(-1)   14(1)
                /
                       13(0)
                      /
     12(-1)
 The output should be 5, 10, 3, 14, 25.
 Solution:
 print each node’s value as well as its column number?
 HashMap<Integer,List<Integer> > hp = new HashMap<Integer,List<Integer> >();
 void Preorder(TreeNode root, int column, int level){
      if(root==null){
 return;
      }
 if(!containsKey(column)){
 List<Integer>newPair = new ArrayList<Integer>();
 newPair.add(level);
 newPair.add(root.value);
 hp.put(column,newPair);
 }else{
 List<Integer>curPair = hp.get(column);
 int curlevel = curPair.get(0);
 if (level > curlevel){
 curPair.set(0,level);
 curPair.set(1,root.val);
 }
 hp.put(column,curPair);
 }
      preorder(root.left, column-1,level+1);
      preorder(root.right, column+1,level+1);
 }
 <key = column, value == <lowest level on this column, its value>>
   -1       4 10
 

 */