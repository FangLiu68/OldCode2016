//
//  Deep Copy Undirectd Graph.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Make a deep copy of an undirected graph, there could be cycles in the original graph.

 Assumptions
 The given graph is not null
 */

#include "Header.h"
#include "LinkedList.h"

struct GraphNode {
  int value;
  vector<GraphNode*> neighbors;
  GraphNode(int v) : value(v) {}
};

/*
 使用额外的内存来使用map存储源节点和拷贝节点之间的对应关系。
 有了这个关系之后，在遍历图的过程中，就可以同时处理访问节点及访问节点的拷贝节点，一次完成
 */
GraphNode* copy_graph(GraphNode* startNode) {
    if(startNode == NULL) return NULL;

    queue<GraphNode *> visit;
    visit.push(startNode);

    unordered_map<GraphNode *, GraphNode *> mp;
    GraphNode * nodeCopy = new GraphNode(startNode->value);
    mp[startNode] = nodeCopy;

    /*
     对每一个点，先copy这个当前点，再把这个点的所有邻居都copy过去
     用queue存原始点的顺序（先进先出），每次都从queue的最前面拿node（叫他cur_orig）来开始做copy
     每次要copy cur_orig的邻居中的某一个点Node的时候，要先check将要copy的这个原始点Node(key)是否在map中，
     如果没有，表示Node还没有被copy过，那么要做这几步：
        1. new一个新的copyNode；
        2. 把pair<Node, copyNode>放入map中；
        3. 把Node push进入queue里；
        4. 把新new的这个copyNode放入（cur_orig的copy）的neighbors里 （cur_orig的copy用map[cur_orig]来表示）。不能少！！
     如果这个点已经存在过了，表明这个点Node已经被copy过了，那我们只需要做第四步，把copy过的点放入map[cur_orig]的neighbors里就行
     */
    while (!visit.empty()){
        GraphNode* cur_orig = visit.front();
        visit.pop();

        vector<GraphNode*> cur_neis = cur_orig->neighbors;

        for (int i = 0; i< cur_neis.size(); ++i){
            // no copy of neighbor node yet. create one and associate with the copy of cur
            if (mp.find(cur_neis[i]) == mp.end()){
                GraphNode* cur_copy = new GraphNode(cur_neis[i]->value);
                mp[cur_neis[i]] = cur_copy;

                visit.push(cur_neis[i]);

                mp[cur_orig]->neighbors.push_back(cur_copy);
            }
            else{
                // already a copy there. Associate it with the copy of cur
                mp[cur_orig]->neighbors.push_back(mp[cur_neis[i]]);
            }
        }
    }
    return nodeCopy;
}