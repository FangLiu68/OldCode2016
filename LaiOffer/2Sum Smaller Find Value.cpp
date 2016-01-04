//
//  2Sum Smaller.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/25/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Determine the number of pairs of elements in a given array that sum to a value smaller than the given target number.

 Assumptions
 The given array is not null and has length of at least 2
 Examples
 A = {1, 2, 2, 4, 7}, target = 7, number of pairs is 6  ({1,2}, {1, 2}, {1, 4}, {2, 2}, {2, 4}, {2, 4})
 */

#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

int smallerPairs(vector<int> array, int target) {
    if(array.size() < 2){
        return -1;
    }
    sort(array.begin(), array.end());
    int res = 0;
    int left = 0;
    int right = array.size() - 1;
    while(left < right){
        if(array[left] + array[right] >= target){
            right--;
        }else{
            res = res + (right - left);
            left++;
        }
    }
    return res;
}


/*
int main(){
    vector<int> arr(5);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 2;
    arr[3] = 4;
    arr[4] = 7;
    int res = smallerPairs(arr, 7);
    cout << res << endl;
    return 0;
}*/