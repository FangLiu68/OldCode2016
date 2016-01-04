//
//  Design BST.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/30/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// how to design binary search tree which allows duplicate values in the tree

#include "Header.h"

struct DupBST{
    int value;
    int count; // count how many same node for now
    DupBST* left;
    DupBST* right;
    DupBST(int v): value(v), left(NULL), right(NULL){}
};

DupBST* insert(int value){
    return NULL;
}

DupBST* remove(int value){
    return NULL;
}