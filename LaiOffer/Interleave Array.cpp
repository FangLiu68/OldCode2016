//
//  Interleave Array.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/14/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given three char arrays A, B and C. Determine if C can be created by merging A and B in a way that maintains the relative order of the characters in A and B.

 Assumptions
 none of A, B, C is null
 Examples
 C = {'a', 'b', 'c', 'd', 'e'}, A = {'a', 'c', 'd'}, B = {'b', 'e'}, return true
 C = {'a', 'b', 'c', 'd', 'e'}, A = {'a', 'd', 'c'}, B = {'b', 'e'}, return false
 */

#include <iostream>
#include <string>
using namespace std;

bool canMerge(string a, string b, string c) {
    // a="",b="ab",c="ab" 也是对的  所以下面的判断不必要
    /*if(a.empty() || b.empty() || c.empty()){
        return false;
    }*/

    int alen = a.size();
    int blen = b.size();
    int clen = c.size();
    if(alen + blen != clen){
        return false;
    }
   
    bool canMerge[alen+1][blen+1];
    for(int i=0; i<=alen; ++i){
        for(int j=0; j<=blen; ++j){
            if(i==0 && j==0){
                canMerge[i][j] = true;
            }
            if(i>0 && a[i-1]==c[i+j-1]){
                canMerge[i][j] = canMerge[i][j] || canMerge[i-1][j];
            }
            if(j>0 && b[j-1]==c[i+j-1]){
                canMerge[i][j] = canMerge[i][j] || canMerge[i][j-1];
            }
        }
    }
    return canMerge[alen][blen];
}