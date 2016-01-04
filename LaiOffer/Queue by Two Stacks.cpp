//
//  Queue by Two Stacks.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/29/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Java: Implement a queue by using two stacks. The queue should provide size(), isEmpty(), offer(), poll() and peek() operations. When the queue is empty, poll() and peek() should return null.

 C++: Implement a queue by using two stacks. The queue should provide size(), isEmpty(), push(), front() and pop() operations. When the queue is empty, front() should return -1.

 Assumptions

 The elements in the queue are all Integers.
 size() should return the number of elements buffered in the queue.
 isEmpty() should return true if there is no element buffered in the queue, false otherwise.
 */

#include <stack>
#include <iostream>
using namespace std;

/*
 stack 1    bottom1   <--top
 stack 2    bottom2   432<--top   pop(1)
 solution:

 head 1  2 3 4 ----  5 6  tail
 Stack1
 Stack2   0  9 8 7 6 5
 solution:
 (1) we regard stack 1 as the stack to insert/push new element in
 (2) we regard stack 2 as the stack to pop out element.

 When popping out an element, check stack 2,
 if not empty, then pop one element out
 if empty, then dump all data from stack 1 to stack 2 
           (special case, if both stack 1 and 2 are empty, then return NULL);

 when push in, just push into stack 1;

 Time complexity: push O(1)
 pop() : amortized O(1)
 */

class Queue_by_Stack {
    public:
        void pop() {
            swap();
            if(out.empty()){
                return;
            }else{
                out.pop();
            }
        }

        void push(int element) {
            in.push(element);
        }

        int front() {
            swap();
            if(out.empty()){
                return -1;
            }else{
                return out.top();
            }
        }

        int size() {
            return in.size() + out.size();
        }

        bool isEmpty() {
            return in.empty() && out.empty();
        }

        // when out stack is empty, move all the elements from in.
        void swap(){
            if(out.empty()){
                while(!in.empty()){
                    out.push(in.top());
                    in.pop();
                }
            }
        }
    private:
        stack<int> in; // only push element to stack in
        stack<int> out; // only pop element from stack out
    };