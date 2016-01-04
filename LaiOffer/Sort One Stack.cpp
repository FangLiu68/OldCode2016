//
//  Sort One Stack.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Write a program to sort a stack in ascending order (with biggest items on top). You may use at most one additional stack to hold items, but you may not copy the elements into any other data structure (such as an array). The stack supports the following operations: push, pop, peek, and isEmpty
 */

#include "Header.h"

//用一个新的stack做缓冲，每次取原stack.top()，看他适合插入在新stack的哪个位置
// O(N^2) time, O(N) space
stack<int> sortStack(stack<int> input){
    if(input.empty()) return input;

    stack<int> buffer;
    buffer.push(input.top());
    input.pop();

    while(!input.empty()){
        int tmp = input.top();
        while(!buffer.empty() && buffer.top() > tmp){
            input.push(buffer.top());
            buffer.pop();
        }
        buffer.push(tmp);
    }

    return buffer;
}