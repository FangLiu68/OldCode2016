//
//  Influencer Finder.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/30/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a matrix of following between N linkedin users (with ids from 0 to n-1):
 followingMatrix[i][j] == true iff user i is following user j
 thus followingMatrix[i][j] doesn't imply followingMatrix[j][i]
 lets also agree that followingMatrix[i][i] == false
 
 Influencer is a user who is:
 followed by everyone else and not following anyone himself
 
 This method should find an influencer by a given matrix of following, or return -1 if there is no influencer in teh group
 */

#include <vector>
#include <iostream>
using namespace std;

// same as find celebrity. O(N) time
int getInfluencer(vector<vector<bool>> matrix){
    int row = matrix.size();
    int left = 0;
    int right = row - 1;
    
    while(left < right){
        if(matrix[left][right]){
            left++;
        }else{
            right--;
        }
    }
    
    for(int i = 0; i < row; ++i){
        if(left != i){
            if(matrix[left][i] || !matrix[i][left]){
                return -1;
            }
        }
    }
    
    return left;
}