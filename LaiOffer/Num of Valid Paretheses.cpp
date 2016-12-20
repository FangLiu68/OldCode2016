//
//  Num of Valid Paretheses.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/15/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Computer the number of valid expression consists of n ( and )
 
 */

#include <iostream>
using namespace std;

int helper_numOfValidParenthes(int opened, int closed, int n);
int num_of_validParenthes(int n){
    if(n < 0){
        return 0;
    }
    
    return helper_numOfValidParenthes(0, 0, n);
}

int helper_numOfValidParenthes(int opened, int closed, int n){
    // base case
    if(opened == n && closed == n){
        return 1;
    }
    
    int res = 0;
    
    if(opened < n){
        res = res + helper_numOfValidParenthes(opened+1, closed, n);
    }
    
    if(closed < opened){
        res = res + helper_numOfValidParenthes(opened, closed+1, n);
    }
    
    return res;
}