//
//  Get Dot Product.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/17/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Two int arrays with same length, how to get the dot product?
 what if in fact, the arrays are very long, but most of the elements in the arrays are 0.
 A = {1, 2, 0, 0, 3}
 B = {0, 1, 3, 0, 2}
 */

#include "Header.h"

/*
 A dot B = 1*0 + 2*1 + 0*3 + 0*0 + 3*2 = 8
 n: size of the array
 m: number of non-zero values in the array.
 
 naive solution: O(n)
 
 if non-zero values=m << n
 compress the space for zero values. use a list to only store non-zero values with its index, then do merge
 
 (index, value)
 A -> [(0,1),(1,2),(4,3)]
 B -> [(1,1),(2,3),(4,2)]
 */

// if the number of non-zero values = m << n, then we use this method
// O(m)

struct Pair{
    int index;
    int value;
    Pair *next;
};

// merge two linked lists
int dotProduct(Pair* a, Pair* b){
    if(a == NULL || b == NULL) return 0;
    
    int res = 0;
    
    while(a && b){
        if(a->index == b->index){
            res = a->value + b->value;
            a = a->next;
            b = b->next;
        }else if(a->index < b->index){
            a = a->next;
        }else{
            b = b->next;
        }
    }
    
    return res;
}


