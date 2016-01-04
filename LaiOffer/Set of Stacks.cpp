//
//  Set of Stacks.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Imagine a (literal) stack of plates. If the stack gets too high, it migh t topple. 
 Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. 

 Implement a data structure SetOfStacks that mimics this. 
 SetOfStacks should be composed of several stacks and should create a new stack once the previous one exceeds capacity.
 SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack 
 (that is, pop () should return the same values as it would if there were just a single stack).
 FOLLOW UP
 Implement a function popAt(int index) which performs apop operation ona specific sub-stack.
 */

#include "Header.h"
/*
class Stk;

class SetOfStacks{
private:
    vector<Stk> stks;
public:
    Stk getLastStack(){
        return stks[stks.size()-1];
    }

    void push(int v){

        if(!getLastStack().empty()){

        }
    }

    void pop(){

    }
};

class Stk{
private:
    int capacity;
    int top, bottom;
    int size = 0;
public:
    Stk(int capacity){
        this->capacity = capacity;
    }

    bool isFull(){
        return capacity == size;
    }

};
*/

