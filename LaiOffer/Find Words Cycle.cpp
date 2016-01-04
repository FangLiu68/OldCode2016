//
//  Find Words Cycle.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array of strings, find if all the strings can be chained to form a circle

 Input: arr[] = {"aaa", "bbb", "baa", "aab"};
 Output: Yes, the given strings can be chained.  
 The strings can be chained as "aaa", "aab", "bbb" and "baa"Output: Yes

 Input: arr[] = {"aaa", "bbb"};
 Output: No

 Input: arr[] = {"aaa"};
 Output: Yes
 */

#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <assert.h>
#include <iostream>
using namespace std;

// Use a graph to represent the problem. The vertices of the graph are characters forming
// the input strings, eg., 'a' - 'z', or others.
// This is essentially verify whether a directed graph has a Eulerian_path,
// which connects all the starting+ending chars of each input string.
// See sufficient & necessary conditions for a Eulerian_path (from wiki):
// "A directed graph has an Eulerian cycle if and only if every vertex has equal in degree
// and out degree, and all of its vertices with nonzero degree belong to a single strongly connected component."

// This is an O(n) altorithm since number of chars is constant.
bool canChainAsCircle(vector<string> inputs) {
    // first, standard sanity checks.
    if (inputs.size() == 0) {
        return false;
    }
    if (inputs.size() == 1) {
        int len = inputs[0].size();
        return len == 0 ? false : inputs[0].at(0) == inputs[0].at(len - 1);
    }

    map<char, vector<char> > edges;
    set<char> vertices;
    map<char, int> inDegree;
    map<char, int> outDegree;
    // Loop the inputs and build our graph. Meanwhile build in-degree and out-degree
    // for each vertex.
    for (int i = 0; i < inputs.size(); ++i) {
        edges[inputs[i].at(0)].push_back(inputs[i].at(inputs[i].size() - 1));
        vertices.insert(inputs[i].at(0));
        vertices.insert(inputs[i].at(inputs[i].size() - 1));
        outDegree[inputs[i].at(0)]++;
        inDegree[inputs[i].at(inputs[i].size() - 1)]++;
    }

    // We check two things, 1. the in-degree of each vertex is equal to the out-degree.
    // 2. the vertices with >0 edges form a strongly connected graph.
    // Here, to determine strongly connected graph, I'm using the hack of doing
    // BFS from every node and see if all other nodes can be reached.
    // Better algorithms exist such as Kosaraju's algorithm and Trojan algorithm
    // (see wiki). But, since the number of vertices V is constant, V^2 is constant
    // as well.

    for (map<char, int>::iterator it = outDegree.begin(); it != outDegree.end(); ++it) {
        if (inDegree[it->first] != it->second) {
            return false;
        }
        char start = it->first;
        // BFS
        queue<char> q;
        set<char> visited;
        q.push(start);
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            for (int i = 0; i < edges[curr].size(); ++i) {
                if (visited.find(edges[curr][i]) == visited.end()) {
                    visited.insert(edges[curr][i]);
                    q.push(edges[curr][i]);
                }
            }
        }
        if (visited.size() != vertices.size()) {
            return false;
        }
    }
    return true;
}


void testCanChainAsCircle() {
    {
        string s[] = {"good", "dog"};
        vector<string> v_s(s, s + sizeof(s) / sizeof(string));
        assert(true == canChainAsCircle(v_s));
    }
    {
        string s[] = {"good"};
        vector<string> v_s(s, s + sizeof(s) / sizeof(string));
        assert(false == canChainAsCircle(v_s));
    }

    {
        string s[] = {"aaa", "bbb", "baa", "aab"};
        vector<string> v_s(s, s + sizeof(s) / sizeof(string));
        assert(true == canChainAsCircle(v_s));
    }
    {
        string s[] = {"aaa"};
        vector<string> v_s(s, s + sizeof(s) / sizeof(string));
        assert(true == canChainAsCircle(v_s));
    }
    {
        string s[] = {"aaa", "bbb"};
        vector<string> v_s(s, s + sizeof(s) / sizeof(string));
        assert(false == canChainAsCircle(v_s));
    }
    {
        string s[] = {"aaa", "bbb", "aaa", "bbb"};
        vector<string> v_s(s, s + sizeof(s) / sizeof(string));
        assert(false == canChainAsCircle(v_s));
    }
    {
        string s[] = {"aaa", "aaa", "aaa", "aaa"};
        vector<string> v_s(s, s + sizeof(s) / sizeof(string));
        assert(true == canChainAsCircle(v_s));
    }
    {
        string s[] = {"alsdfkjhaklsdjf", "fjjjjjjjj", "js", "sssssssaaaaa"};
        vector<string> v_s(s, s + sizeof(s) / sizeof(string));
        assert(true == canChainAsCircle(v_s));
    }

    {
        string s[] = {"ab", "ab"};
        vector<string> v_s(s, s + sizeof(s) / sizeof(string));
        assert(false == canChainAsCircle(v_s));
    }
}