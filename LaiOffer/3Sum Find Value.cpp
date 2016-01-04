//
//  3Sum.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/24/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Determine if there exists three elements in a given array that sum to the given target number. 
 Return all the triple of values that sums to target.

 Assumptions
 The given array is not null and has length of at least 3
 No duplicate triples should be returned, order of the values in the tuple does not matter
 Examples
 A = {1, 2, 2, 3, 2, 4}, target = 8, return [[1, 3, 4], [2, 2, 4]]
 */

#include <vector>
#include <set>
#include <iostream>
using namespace std;

vector<vector<int>> threeSum(vector<int> arr, int target){
    vector<vector<int>> res;
    if(arr.empty()) return res;
    sort(arr.begin(), arr.end());
    for(int i=0; i<arr.size(); ++i){

        // 跳过重复元素
        if(i>0 && arr[i] == arr[i-1])
            continue;
        int left = i+1;
        int right = arr.size() - 1;
        while(left < right){
            // 用同样的方法跳过重复元素
            if(left >i + 1 && arr[left] == arr[left-1])
                continue;
            if(right < arr.size()-1 && arr[right] == arr[right+1])
                continue;

            vector<int> tmp(3);
            int sum = arr[i]+arr[left]+arr[right];
            if(sum == target){
                tmp[0] = arr[i];
                tmp[1] = arr[left];
                tmp[2] = arr[right];
                res.push_back(tmp);
                left++, right--;
            }else if(sum < target){
                left++;
            }else{
                right--;
            }
        }
    }
    return res;
}


// 记得要用set 去除重复
vector<vector<int>> threeSum1(vector<int> array, int target) {
    set<vector<int>> res;
    if(array.empty()) return vector<vector<int>>();
    sort(array.begin(), array.end());

    for(int i=0; i<array.size(); i++){
        int left = i+1;
        int right = array.size()-1;
        while(left < right){ // can't be left<=right
            vector<int> tmp(3);
            if(array[i] + array[left] + array[right] == target){
                tmp[0] = array[i];
                tmp[1] = array[left];
                tmp[2] = array[right];
                res.insert(tmp);
                left++, right--;
            }
            else if(array[i] + array[left] + array[right] < target)
                left++;
            else
                right--;
        }
        //while(i<array.size()-1 && array[i]==array[i+1]) i++;
    }
    return vector<vector<int>>(res.begin(), res.end());
}