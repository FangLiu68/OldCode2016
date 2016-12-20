//
//  search in shifted sorted arrII.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a target integer T and an integer array A, A is sorted in ascending order first, then shifted by an arbitrary number of positions.

 For Example, A = {3, 4, 5, 1, 2} (shifted left by 2 positions). Find the index i such that A[i] == T or return -1 if there is no such index.

 Assumptions
 There could be duplicate elements in the array.
 Examples
 A = {3, 4, 5, 1, 2}, T = 4, return 1
 A = {1, 2, 3, 4, 5}, T = 4, return 3
 A = {3, 4, 6, 1, 2}, T = 5, return -1
 A = {1, 1, 1, 2, 1}, T = 1, return 0 or 1 or 2 or 4
 Corner Cases
 What if A is null or A is of zero length? We should return -1 in this case.
 */

#include <vector>
#include <iostream>
using namespace std;

int helper(int input[], int len, int target);
int search_in_rotated_sorted_arr_has_dup(int input[], int len, int target) {
    if(input==NULL) return -1;
    int left = 0;
    int right = len-1;
    int mid;
    while(left <= right){
        mid = left + (right-left)/2;
        if(input[mid] == target) return mid;

        if(input[left] < input[mid]){ //left part is sorted
            if(input[left] <= target && target < input[mid]) right = mid-1;
            else left = mid+1;
        }

        else if(input[left] > input[mid]){ // right part is sorted
            if(input[mid] < target && target <= input[right])  left = mid+1;
            else right = mid-1;
        }

        else if(input[left] == input[mid]){
            if(input[left] != input[right]){
                left = mid + 1;
            }else {
                return helper(input, len, target);
            }
        }
    }
    return -1;
}

int helper(int input[], int len, int target){
    if(input == NULL || len<=0) return -1;
    for(int i=0; i<len; i++)
        if(input[i] == target) return i;
    return -1;
}
/*
int main(){
    int arr[] = {1,2,1,1,1};
    int len =5;
    int target = 2;
    int res = solve(arr, len, target);
    cout << res << endl;
    return 0;
}*/