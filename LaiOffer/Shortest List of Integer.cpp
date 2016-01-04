//
//  Shortest List of Integer.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/23/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int shortest(int x){
    int* M = new int[x+1];
    M[1] = 1;
    for(int i=2; i<=x; ++i){
        int y = sqrt(x);
        int cur_min = INT_MIN;
        for(int j=1; j<=y; ++j){
            cur_min = min(M[x-j*j]+1, cur_min);
        }
        M[i] = cur_min;
    }
    int res = M[x];
    delete[] M;
    return res;
}
