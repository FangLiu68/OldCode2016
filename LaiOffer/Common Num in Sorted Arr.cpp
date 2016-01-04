//
//  Common Elem in Two Arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/6/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Find common elements in two sorted arrays
 A[m] = 1, 2,3 , 4, 5
 B[n] = 4, 5, 6
 */

/*
 1. hash all elements from one array to hashtable, then check the other array
    hash the shorter array into hash table
    O(m+n)
 2. use two index move together
 */

// 注意，找intersection和找union是不一样的。找intersection, 只要任意一个数组查找完毕，就可以结束查找。但是找union,一定要把所有数组查找完毕。所以对于找union of two sorted arr来说，while(lenA && lenB)之后，还要继续找while(lenA), while(lenB)

#include <vector>
#include <iostream>
using namespace std;

// O(m+n) runtime, O(1) space
// 注意这里runtime O(m+n), eg: a[]={1,2,99}, b[]={3,4,...100}
vector<int> common_elem_in_two_sorted_arr(int A[], int lenA, int B[], int lenB){
    vector<int> res;
    if(A==NULL || B==NULL || lenA<=0 || lenB<=0) return res;
    int indexA = 0;
    int indexB = 0;
    while(indexA <= lenA && indexB <= lenB){
        if(A[indexA] == B[indexB]){
            res.push_back(A[indexA]);
            indexA++;
            indexB++;
        }
        else if(A[indexA] < B[indexB])
            indexA++;
        else
            indexB++;
    }
    return res;
}


/*
 Find common elements in three sorted arrays
 1, 2, 3, 5, 10
 3, 4, 6
 3, 9
 */
// each time move the pointer which point to the SMALLEST element
vector<int> common_elem_in_three_sorted_arr(int A[], int lenA, int B[], int lenB, int C[], int lenC){
    vector<int> res;
    if(A==NULL || B==NULL || C==NULL || lenA<=0 || lenB<=0 || lenC<=0) return res;
    int indexA = 0;
    int indexB = 0;
    int indexC = 0;
    while(indexA<=lenA && indexB<=lenB && indexC<=lenC){
        if(A[indexA] == B[indexB] && B[indexB] == C[indexC]){
            res.push_back(A[indexA]);
            indexA++, indexB++, indexC++;
        }
        else if(A[indexA] <= B[indexB] && A[indexA] <= C[indexC]) // NOTICE: <=
            indexA++;
        else if(B[indexB] <= A[indexA] && B[indexB] <= C[indexC])
            indexB++;
        else
            indexC++;
    }
    return res;
}


/*
 Find common elements in K sorted arrays
 1. same as above
 2. use K pointers, each time move the pointer which point to the SMALLEST element
    then, how to find the smallest element? use min_heap or something else?
 */