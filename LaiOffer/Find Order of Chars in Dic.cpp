//
//  Find Order of Chars in Dic.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a new language that uses the, "ab", “bc”, “ca”, "cb", "cca" “ccc” in a sorted dictionary.
 Output:  the ordering of all chars in this particular language.
 e.g., a → b → c
 Step1:  通过字典里sorted好的word的先后顺序，得到每个pair of char的先后partial order.   → Find the ordering between each pair of characters.
 "cca"
   i
 “ccc”
   j
 a → b
 b → c
 a → c
 Step2: Use topological sorting to find the complete order of all chars.
 http://en.wikipedia.org/wiki/Topological_sorting
 Data structure:
 class Node {
 int indegree; // how many nodes pointing to me
 char value;
 Node(char value) {
 this.value = value;
	}
 }
 Queue<Node>,
 ArrayList<Node>
 (1)
 (2) Hash_table<key = Node,           value =  ArrayList<Node>>
        parent node,        successors
 Algorithm:
 L ← Empty list that will contain the sorted elements (= results)
 S ← Set of all nodes with no incoming edges
 while S is non-empty do
    remove a node n from S
    add n to tail of L
    for each node m with an edge e from n to m do
        remove edge e from the graph
        if m has no other incoming edges then
            insert m into S
 if graph has edges then
    return error (graph has at least one cycle)
 else
    return L (a topologically sorted order)

 */