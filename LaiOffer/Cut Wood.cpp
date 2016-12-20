//
//  Cut Wood.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/1/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 There is a wooden stick with length L >= 1, we need to cut it into pieces, where the cutting positions are defined in an int array A. The positions are guaranteed to be in ascending order in the range of [1, L - 1]. The cost of each cut is the length of the stick segment being cut. Determine the minimum total cost to cut the stick into the defined pieces.
 Examples
	• L = 10, A = {2, 4, 7}, the minimum total cost is 10 + 4 + 6 = 20 (cut at 4 first then cut at 2 and cut at 7)
 __ __ __ __ __ __ __ __ __ __
 0   1   2   3   4   5   6   7   8   9  10
 first cut at 7: 10
 cut at 4 : 7
 cut at 2 : 4
 dp[i][j] = min cost of cutting subarray(i,j)
 对于固定位置的切木头，只能用dp来做。二维DP
 
 
 What if we don’t care where exactly the 4 pieces of woods in the original stick, but we just need 4 pieces, length of {2,2,3,3} ?
 对于不固定位置的切木头，即只要切成拥有list里面长度的4块，不用管到到底先切哪儿后切那儿，可以用huffman encoding的方法来做。每次取cost最小的两个，组成新Node，再push back to min heap。循环直到min heap只剩下一个Node，即 root of the HF tree
 */

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// tree node
struct woodnode{
    double weight;
    woodnode* left;
    woodnode* right;
    woodnode():weight(0), left(NULL), right(NULL){}
};

// get height of tree
int helper_height(woodnode* root){
    if(root == NULL){
        return 0;
    }
    int left = helper_height(root->left);
    int right = helper_height(root->right);
    return max(left, right) + 1;
}

// min heap
struct comp{
    bool operator()(woodnode* node1, woodnode* node2){
        return node1->weight > node2->weight;
    }
};

// build tree
woodnode* build_HFtree(vector<woodnode*> nodes){
    if(nodes.empty()){
        return NULL;
    }
    
    priority_queue<woodnode*, vector<woodnode*>, comp> min_heap;
    for(int i = 0; i < nodes.size(); ++i){
        min_heap.push(nodes[i]);
    }
    
    while(min_heap.size() >= 2){
        woodnode* node1 = min_heap.top();
        min_heap.pop();
        woodnode* node2 = min_heap.top();
        min_heap.pop();
        
        woodnode* fathernode;
        fathernode->weight = node1->weight + node2->weight;
        fathernode->left = node1;
        fathernode->right = node2;
        
        min_heap.push(fathernode);
    }
    
    return min_heap.top();
}

// get total cost of tree
double get_cost(vector<woodnode*> nodes){
    if(nodes.empty()){
        return 0;
    }
    
    double res = 0;
    woodnode* root = build_HFtree(nodes);
    int root_height = helper_height(root);
    
    for(int i = 0; i < nodes.size(); ++i){
        int cur_height = helper_height(nodes[i]);
        int level = root_height - cur_height;
        res += nodes[i]->weight * level;
    }
    
    return res;
}


