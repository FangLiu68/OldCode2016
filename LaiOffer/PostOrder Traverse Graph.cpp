//
//  PostOrder Traverse Graph.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/26/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 starting N1, after visited all the nodes reachable from N1, then we mark N1 visited once and only once. 
 we need some additional state for each node in "visiting": a special marker of the nodes on the current DFS path to avoid duplicately visiting nodes.
 - not visited
 - visiting
 - visited
 */

#include <map>
#include <vector>
#include <iostream>
using namespace std;

struct Vertex{
    vector<Vertex> neighbors;
};

enum State{
    NOT_VISITED, VISITING, VISITED
};

void dfs_recursion(Vertex v, map<Vertex, State> states);

void traverse(Vertex v){
    map<Vertex, State> states;
    dfs_recursion(v, states);
}

void dfs_recursion(Vertex v, map<Vertex, State> states){
    State state = states[v];
    if(state == VISITED){
        return;
    }
    
    if(state == VISITING){
        return; // there is a cycle
    }
    
    states[v] = VISITING;
    
    for(int i = 0; i < v.neighbors.size(); ++i){
        traverse(v.neighbors[i]);
    }
    
    states[v] = VISITED;
}