//
//  Huffman Encoding.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/1/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Each symbols has an associated weight (probability) with it,
 {A, 0.6}      -    0
 {B, 0.2}      -     101
 {C, 0.1}     -     110
 {D, 0.05}   -     111
 {E, 0.05}    -    1000
 1*3 = 3 bit.
 0.6 * 1 +  (0.2 + 0.1 + 0.05) * 3 + 0.05 * 4 = 0.6 + 1.05 + 0.2 = 1.85 bit
 The sum of the weights is 1.
 Encode the symbols with binary string so that the network bandwidth requirement is minimized.
 (expected length of encoding is minimized: 0.6 * lengthOfEncode(A) + 0.2 * lengthOfEncode(B) + … + 0.05 * lengthOfEncode(E))
 
 heuristic: the symbol with larger probability should has less length of encoding.
               the symbol with smaller probability should has longer length of encoding.

                                                     {ABCDE, 1}
                                                 / (0)                 \ (1)
                                   {BCDE, 0.4}                  {A, 0.6}
                                / (0)                \ (1)
                    {CDE, 0.2}                   {B, 0.2}
               / (0)                \ (1)
    {DE, 0.1}                 {C, 0.1}
  /(0)          \ (1)
 {D,0.05}     {E,0.05}
 encode schema: from root to each leaf nodes’ paths.
 D - 0000
 E - 0001
 C - 001
 B - 01
 A - 1
 for each round: pick two smallest, combine them to a larger symbol and put it back.
	• two times of popMin()
	• insert()

 Class Node {
 HashSet<Character> symbols;
 double weight;
 Node left;
 Node right;
 // Node parent;
 }
 
 PriorityQueue<Node> allSymbols; // …. already given.
 for n-1 rounds/ while allSymbols.size() > 1:  // only one node in the priorityqueue, which is the root of the tree.
 Node n1 = allSymbols.poll();
 Node n2 = allSymbols.poll();
 // combine
 Node larger = combine(n1, n2);
 larger.left = n1;
 larger.right = n2;
 allSymbols.offer(larger);
 */

#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct HFNode{
    vector<char> symbols;
    double weight;
    HFNode* left;
    HFNode* right;
    HFNode(): weight(0), left(NULL), right(NULL){}
};

struct comp{ // min heap
    bool operator()(HFNode node1, HFNode node2){
        return node1.weight > node2.weight;
    }
};

// return root node of HF tree
HFNode build_HFTree(vector<HFNode> nodes){
    if(nodes.empty()){
        return HFNode();
    }
    
    priority_queue<HFNode, vector<HFNode>, comp> min_heap;
    
    // push all nodes into min_heap
    for(int i = 0; i < nodes.size(); ++i){
        min_heap.push(nodes[i]);
    }
    
    while(min_heap.size() >= 2){
        // get two min top nodes
        HFNode node1 = min_heap.top();
        min_heap.pop();
        HFNode node2 = min_heap.top();
        min_heap.pop();
        
        HFNode father_node;
        
        for(int i = 0; i < node1.symbols.size(); ++i){
            father_node.symbols.push_back(node1.symbols[i]);
        }
        for(int i = 0; i < node2.symbols.size(); ++i){
            father_node.symbols.push_back(node2.symbols[i]);
        }
        
        // construct relationship
        father_node.weight = node1.weight + node2.weight;
        father_node.left = &node1;
        father_node.right = &node2;
        
        min_heap.push(father_node);
    }
    
    return min_heap.top();
}


