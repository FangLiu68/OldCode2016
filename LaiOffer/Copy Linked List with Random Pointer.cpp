//
//  Deep Copy Linked List with Random Pointer.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 Return a deep copy of the list.
 */

// solution are the same with the previous question: deep copy skip list

/*
use map, to guarantee you only copy once for each node.
 map, key: original node; value: copied node
 原linked list从头到尾iterate，每次遇到新的node，先在map中形成新的copy node，然后再与之前已经形成的copied linked list链接起来
 */

#include "Header.h"
#include "LinkedList.h"


struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
    if(head==NULL) return NULL;
    unordered_map<RandomListNode*, RandomListNode*> mp;
    RandomListNode* newHead = new RandomListNode(head->label);
    mp[head] = newHead;
    RandomListNode* newCur = newHead;
    
    while(head){
        if(head->next){
            if(mp.find(head->next) == mp.end())
                mp[head->next] = new RandomListNode(head->next->label);
            newCur->next = mp[head->next];
        }
        if(head->random){
            if(mp.find(head->random) == mp.end())
                mp[head->random] = new RandomListNode(head->random->label);
            newCur->random = mp[head->random];
        }
        head = head->next;
        newCur = newCur->next;
    }
    return newHead;
}