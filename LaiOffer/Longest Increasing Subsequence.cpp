//
//  Longest Ascending Subsequence.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/13/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array A[0]...A[n-1] of integers, find out the length of the longest ascending subsequence.

 Assumptions
 A is not null
 Examples
 Input: A = {5, 2, 6, 3, 4, 7, 5}
 Output: 4
 Because [2, 3, 4, 5] is the longest ascending subsequence
 */

// Longest Ascending Subarray (when at i, look back at i-1)
// Longest Ascending Subsequence (when at i, look back at 1….i-1)

/*
 Solution:
 Base case;  M[0]  = 1;
 Induction rule:

 M[i] represents the length of the longest ascending sub-sequence including A[i] itself.
 M[i] = max( M[j]) + 1,		if (A[i] > A[j])  for all 0<= j < i
      = 1            	    otherwise

    {1, 2, 4,		     3,				7,6,4,5}
 M[] 1  2  3=max(1+1,	 3=max(1+1
             2+1)          2+1
 
 对于arr[i]来说，到arr[i]为止的最长ascending subsequence是在下面这些值里面取最大值：
 从0到i之间的index，对于所有的比arr[i]小的数，每个数都在访问arr[i]之前计算过M[index]，取这些M[index]里面的最大值
 如果arr[i]是迄今为止[0,i]之间的最小值（在他之前没有比他更小的了，那么M[i]=1）
 */

#include <iostream>
#include <vector>
using namespace std;

int Longest_ascending_subsequence(vector<int> input){
    if(input.empty()){
        return 0;
    }
    int res = 1;
    int* M = new int[input.size()];
    M[0] = 1;
    for(int i=1; i<input.size(); ++i){
        int cur_max = 1;
        for(int j=0; j<i; ++j){
            if(input[j] < input[i]){
                cur_max = max(cur_max, M[j]+1);
            }
        }
        M[i] = cur_max;
        res = max(res, cur_max);
    }
    delete[] M;
    return res;
}
/*
int main(){
    int arr[] = {5,2,3,1,9,4,2,1,5,7,8};
    cout << Longest_ascending_subsequence(arr, 11) << endl;
    return 0;
}*/