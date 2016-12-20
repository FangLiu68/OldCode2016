//
//  Find the Celebrity.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/30/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Suppose you are at a party with n people (labeled from 0 to n-1) and among them, there may exist one celebrity. The definition of a celebrity is that all the other n-1 people know him/her but he/she doesn't know any of them.
 
 Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions like: "Hi, A, do you know B?" to get information of whether A knows B. you need to find out the celebrity (or verify there is not one) by asking as few questions as possible (int the asymptotic sense).
 
 You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function in findCelebrity(n), your function should minimize the number of calls to know. 
 
 Note: There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return -1.
 
 0,      1,      2,     3,      4,       5,      6,     7
                                                row
                                                        col
 如果6不认识7，7就出去了，所以6只跟7比较过，6只能算是candidate，所以我们最后要再verify下6到底认不认识其他的所欲人。
 */

#include <iostream>
using namespace std;

// two pointers. O(n) time, O(1) space

bool knows(int a, int b);

int findCelebrity(int n){
    if(n <= 0){
        return -1;
    }
    
    int left = 0;
    int right = n - 1;
    
    while(left < right){
        if(knows(left, right)){ // current left couldn't be celebrity
            left++;
        }else{
            right--; // current right couldn't be celebrity
        }
    }
    
    for(int i = 0; i < n; ++i){
        if(left != i){
            if(knows(left, i) || !knows(i, left)){
                return -1;
            }
        }
    }
    
    return left;
}