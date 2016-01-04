//
//  Use Arr build Stack.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Describe how you could use a single array to implement three stacks.

#include "Header.h"
#define stackSize 100

/*
 每个stack元素数量是固定的stackSize
 arr[]的大小是stackSize * 3
 stackPointer有三个元素i，i只能取[0,2]，每个元素代表每个stack. stackPointer[i]代表第i个stack此时的容量是多少，最多不可超过stackSize
 absTopOfStack(stackNum) 得到这个stackNum的top元素在arr[]里的index是多少
 */
class ArrToThreeStacks{
public:
    ArrToThreeStacks(){
        for(int i=0; i<3; ++i){
            stackPointer[i] = 0;
        }
    }

    void push(int stackNum, int val){
        // check if has space
        if(stackNum >=3 || stackPointer[stackNum] >= stackSize){
            return;
        }
        // increase stack pointer and then update top value
        stackPointer[stackNum]++;
        arr[absTopOfStack(stackNum)] = val;
    }

    void pop(int stackNum){
        if(stackNum >= 3 || stackPointer[stackNum] == 0){
            return;
        }
        arr[absTopOfStack(stackNum)] = 0; // clear index
        stackPointer[stackNum]--; // decrease pointer
    }

    int top(int stackNum){
        if(stackNum >= 3){
            return INT_MIN;
        }
        return arr[absTopOfStack(stackNum)];
    }

    bool isEmpty(int stackNum){
        return stackPointer[stackNum] == 0;
    }

    // return index of top of stack "stackNum", in absolute terms
    int absTopOfStack(int stackNum){
        return stackNum * stackSize + stackPointer[stackNum];
    }

private:
    int arr[stackSize * 3];
    int stackPointer[3]; // pointers to track top elements
};