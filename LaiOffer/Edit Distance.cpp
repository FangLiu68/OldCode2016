//
//  Edit Distance.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/13/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int editDistance(string s1, string s2) {
    if(s1.empty()){
        return s2.size();
    }else if(s2.empty()){
        return s1.size();
    }
    int row = s1.size();
    int col = s2.size();
    int M[row+1][col+1];
    for(int i = 0; i <= s1.size(); ++i){
        for(int j=0; j <= s2.size(); ++j){
            if(i == 0){
                M[i][j] = j;
            }else if(j == 0){
                M[i][j] = i;
            }else if(s1[i-1] == s2[j-1]){
                M[i][j] = M[i-1][j-1];
            }else{
                M[i][j] = min(min(M[i-1][j], M[i][j-1]), M[i-1][j-1]) + 1;
            }
        }
    }
    return M[row][col];
}