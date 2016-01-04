//
//  LinkedList.h
//  LaiOffer
//
//  Created by Fang Liu on 7/1/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#ifndef LaiOffer_LinkedList_h
#define LaiOffer_LinkedList_h

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(NULL){}
};

struct DoubleListNode{
    int val;
    DoubleListNode* pre;
    DoubleListNode* next;
    DoubleListNode(int v) : val(v), pre(NULL), next(NULL){}
};

#endif
