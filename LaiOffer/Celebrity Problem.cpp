//
//  Celebrity Problem.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/1/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 A group of people, if there exists one person such that he doesn't know any other people, but every person knows him, is there such a person existed? if so, who is it?
 
 1. how many celebrities in total we can have? -- at most 1
    suppose we have two celebrities c1 and c2
    if c1 knows c2, c1 is not celebrity, if c1 doesn't know c2, then c2 is not celebrity
 
 each pair of persons, we know one of them is not celebrity.
 we can do pair comparison for n-1 times, then we have a candidate.
 we still need to check if the candidate is the celebrity
 */

#include <iostream>
#include <vector>
using namespace std;

// assume valid input, matrix[i][j] == true represents people i knows people j. O(N*N)
int candidateFinding(vector<vector<bool>> matrix){
    int row = 0;
    int col = 1;
    for(col = 1; col < matrix.size(); ++col){
        if(matrix[row][col]){
            row = col;
        }
    }
    return row;
}

/*
 why do we need to verify
 
 */