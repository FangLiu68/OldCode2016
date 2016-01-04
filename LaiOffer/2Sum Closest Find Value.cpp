//
//  2Sum Closest.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/24/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Find the pair of elements in a given array that sum to a value that is closest to the given target number. 
 Return the values of the two numbers.

 Assumptions
 The given array is not null and has length of at least 2
 Examples
 A = {1, 4, 7, 13}, target = 7, closest pair is 1 + 7 = 8, return [1, 7].
 */

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> twoSum_close(vector<int> array, int target) {
    vector<int> res(2);
    if(array.size() < 2){
        return res;
    }
    int closest = INT_MAX;
    sort(array.begin(), array.end());
    int left = 0;
    int right = array.size()-1;
    while(left < right){
        int gap = abs(array[left] + array[right] - target);
        if(gap < closest){
            res[0] = array[left];
            res[1] = array[right];
            closest = gap;
        }
        if(array[left] + array[right] < target){
            left++;
        }else{
            right--;
        }
    }
    return res;
}

/*
int main(){
    vector<int> arr = {1,4,7,13};
    int target = 7;
    vector<int> res = twoSum_close(arr, target);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}*/