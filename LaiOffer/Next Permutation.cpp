//
//  Next Permutation.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/3/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/* next greater number
 给一个数，找出下一个比他大的数，并且那个较大的数的每一位都是由这个数本身的元素组成的

        012345
 n =   “279865”
 ret = “285679”
 n = “4321”
 ret = null
*/

/* 从后往前找，直到找到非递增的那个数X，记录位置A
 * 从位置A往后找，直到找到第一个比X大的数Y
 * X和Y互换
 * 然后，reverse(A+1,END)这一段*/

/*
 Given an int array, Find the next permutation of the given one. The permutations are sorted in its lexicological.

 Example:
 All permutations of {1, 2, 3} sorted from smallest to largest:
 {1, 2, 3}
 {1, 3, 2}
 {2, 1, 3}
 {2, 3, 1}
 {3, 1, 2}
 {3, 2, 1}
 Given {2, 1, 3}, should return {2, 3, 1} as the next permutation.

 from right to left, find the first descending order pair.
 {2, 1, 3, 2}
 from the right side, find the smallest number > 1.
 swap 1 with the rightmost 2.
 {2, 2, 3, 1}
 reverse the right part.
 {2, 2, 1, 3}


 {1, 2, 2, 2} → swap {2, 2, 2, 1} → reverse {2, 1, 2, 2}
 */

#include "Header.h"

vector<int> nextBiggerNum(vector<int> input){
    if(input.empty()){
        return vector<int>();
    }

    int first_not_increase = input.size()-1;
    while(first_not_increase > 0 && input[first_not_increase] <= input[first_not_increase-1]){
        first_not_increase--;
    }

    if(first_not_increase > 0){
        first_not_increase--;
        int first_bigger = first_not_increase;
        while(first_bigger < input.size() && input[first_bigger] >= input[first_not_increase]){
            first_bigger++;
        }
        swap(input[first_not_increase], input[first_bigger-1]);
        reverse(input.begin()+first_not_increase+1, input.end());
    }
    return input;
}

/*
int main(){
    vector<int> input = {2,7,9,8,6,5};
    vector<int> res = nextBiggerNum(input);
    for(int i=0; i<res.size(); ++i){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}*/
