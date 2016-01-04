//
//  Deep Copy Skip List.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 A Skip List is a special type of linked list, where each of the nodes has a forward pointer to another node in the front and forward pointers are guaranteed to be in non-descending order.
 Make a deep copy of the original skip list.
 */
/*
 input:
 N1 -> N2 -> N3 -> N4 -> N5 -> NULL
 |     |     ^           ^
 |     |     |           |
 |-----|------           |
       |------------------
 output:
 N1’ -> N2’ ->N3’ ->N4’ ->N5’ -> NULL
 |     |     ^           ^
 |     |     |           |
 |-----|------           |
       |------------------

 */
#include "Header.h"
#include "LinkedList.h"

struct skipListNode{
    int val;
    skipListNode* next;
    skipListNode* forward;
    skipListNode(int v) : val(v), next(NULL), forward(NULL){}
};

skipListNode* deepCopy(skipListNode* head){
    if(head == NULL) return NULL;
    unordered_map<skipListNode*, skipListNode*> mp;
    skipListNode* newHead = new skipListNode(head->val);
    mp[head] = newHead;
    skipListNode* newCur = newHead; // cur pointer in the new copied list
    while(head){
        if(head->next){
            if(mp.find(head->next) == mp.end()){
                mp[head->next] = new skipListNode(head->next->val);
            }
            newCur->next = mp[head->next];
        }
        if(head->forward){
            if(mp.find(head->forward) == mp.end()){
                mp[head->forward] = new skipListNode(head->forward->val);
            }
            newCur->forward = mp[head->forward];
        }
        head = head->next;
        newCur = newCur->next;
    }
    return newHead; // 注意这里不能直接返回mp[pHead] 因为mp在这个function结束后就自动销毁
}
