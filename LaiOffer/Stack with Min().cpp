//
//  Stack with Min().cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/7/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Enhance the stack implementation to support min() operation. min() should return the current minimum value in the stack. If the stack is empty, min() should return -1.

 pop() - remove and return the top element, if the stack is empty, return -1
 push(int element) - push the element to top
 top() - return the top element without remove it, if the stack is empty, return -1
 min() - return the current min value in the stack
 
 synchronized input and deletion 注意
 保证：对于此时的cur.top()来说，此时的min.top()代表的是此时的最小值
 */

#include <stack>
#include <iostream>
using namespace std;


class Stack_with_Min{
public:
    // when value <= current min value in stack,
    // need to push the value to minStack.
    void push(int x) {
        if(minStack.empty() || x <= minStack.top()){
            minStack.push(x);
        }
        curStack.push(x);
    }

    // when the popped value is the same as top value of minStack, the value
    // need to be popped from minStack as well.
    void pop() {
        if(curStack.empty()){
            return;
        }
        if(minStack.top() == curStack.top()){
            minStack.pop();
        }
        curStack.pop();
    }

    int top() {
        if(curStack.empty())
            return -1;
        return curStack.top();
    }

    int min() {
        if(minStack.empty()){
            return -1;
        }else{
            return minStack.top();
        }  
    }
private:
    stack<int> curStack;
    stack<int> minStack;
};