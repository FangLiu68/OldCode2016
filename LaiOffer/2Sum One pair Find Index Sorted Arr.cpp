//
//  2Sum One pair Find Index Sorted Arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/18/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

 The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

 You may assume that each input would have exactly one solution.

 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2
 */

#include <vector>
#include <iostream>
using namespace std;

// Method 1: two pointers 相向而行. O(N) runtime, O(1) space
pair<int, int> twoSumSortedArr(vector<int> input, int target){
    pair<int, int> res;
    if(input.empty()) return res;
    int left = 0;
    int right = input.size()-1;
    while(left < right){
        if(input[left] + input[right] == target){
            res.first = left + 1;
            res.second = right + 1;
            break; // 如果不要break的话，这里要写left++, right--，否则出不了while
        }else if(input[left] + input[right] < target){
            left++;
        }else{
            right--;
        }
    }
    return res;
}


// Method 2: for each element x, look up if (target-x) exists in O(logN) time by applying binary search over the sorted arr
// total O(NlogN)
int helper_binarySearch(vector<int> input, int start, int target){
    if(input.empty()) return INT_MIN;

    int left = start;
    int right = input.size()-1;

    while(left <= right){
        int mid = left + (right - left)/2;
        if(input[mid] == target){
            return mid;
        }else if(input[mid] < target){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    return -1;
}

pair<int, int> twoSumSortedArr_BS(vector<int> input, int target){
    pair<int, int> res;
    if(input.empty()) return res;
    for(int i=0; i<input.size(); ++i){
        int cur = input[i];
        int index = helper_binarySearch(input, i+1, target-input[i]);
        //cout << index << endl;
        if(index != -1){
            res.first = i + 1;
            res.second = index + 1;
            break;
        }
    }
    return res;
}

/*
int main(){
    vector<int> input = {2,4,5,8,11};
    int target = 10;
    cout << twoSumSortedArr_BS(input, target).first << " " << twoSumSortedArr_BS(input, target).second << endl;
    return 0;
}*/