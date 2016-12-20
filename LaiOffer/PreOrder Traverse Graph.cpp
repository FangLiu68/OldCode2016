//
//  Traverse Graph.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/26/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

#include <set>
#include <vector>
#include <iostream>
using namespace std;

struct Vertex{
    vector<Vertex> neighbors;
};

void dfs_recursion(Vertex v, set<Vertex> visited);

void traverse(Vertex v){
    set<Vertex> visited;
    dfs_recursion(v, visited);
}

void dfs_recursion(Vertex v, set<Vertex> visited){
    if(visited.find(v) != visited.end()){
        return;
    }
    
    visited.insert(v);
    
    for(int i=0; i < v.neighbors.size(); ++i){
        dfs_recursion(v.neighbors[i], visited);
    }
}