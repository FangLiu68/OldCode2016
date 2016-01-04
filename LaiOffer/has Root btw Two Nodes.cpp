//
//  has Root btw Two Nodes.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Given a directed graph, design an algorithm to find out whether there is a route between two nodes.

#include "Header.h"

enum State{
    unvisited, visited, visiting
};

struct Node{
    vector<Node*> adjacentNodes;
    State st;
};

// bread first search
bool hasRoute(vector<Node*> graph, Node* start, Node* end){
    if(graph.empty()){
        return false;
    }

    for(int i=0; i < graph.size(); ++i){
        graph[i]->st = unvisited;
    }

    queue<Node*> qu;
    qu.push(start);
    start->st = visiting;
    while(!qu.empty()){
        Node* cur = qu.front();

        for(int i=0; i < cur->adjacentNodes.size(); ++i){
            Node* v = cur->adjacentNodes[i];
            if(v->st == unvisited){ // 只看unvisited的node，visited/visiting的node都直接跳过
                if(v == end){
                    return true;
                }else{
                    v->st = visiting;
                    qu.push(v);
                }
            }
        }

        cur->st = visited;
        qu.pop();
    }
    return false;
}