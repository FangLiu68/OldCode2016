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

/*
 去重复的宗旨是：排序后，只要这次遇见的数与上次相邻的遇见的书相同，我们就跳过，走下一个
 注意：
 1. base case: nums.size() < 3
 2. condition to jump current i:
    if(i>0 && nums[i]==nums[i-1]) continue;
    or
    we only do under condition if(i==0 || nums[i]>nums[i-1])
 3. condition to jum current start and end
    while(start<end && ...)   here we should use while
*/
// O(N^2)
vector<vector<int>> test_3sum(vector<int>& nums){
    vector<vector<int>> res;
    if(nums.size() < 3){
        return res;
    }
    
    vector<int> cur(3, 0);
    sort(nums.begin(), nums.end());
    
    for(int i=0; i<nums.size()-2; ++i){
        if(i>0 && nums[i]==nums[i-1]) continue;
        
        // if(i==0 || nums[i]>nums[i-1]){
        int start = i+1;
        int end = nums.size() - 1;
        while(start < end){
            int sum = nums[start] + nums[end];
            if(nums[i] + sum == 0){
                cur[0] = nums[i];
                cur[1] = nums[start++];
                cur[2] = nums[end--];
                res.push_back(cur);
                
                // 去重复. start和end更新后和之前的值作比较
                while(start<end && nums[start]==nums[start-1]) start++;
                while(start<end && nums[end]==nums[end+1]) end--;
            }else if(nums[i] + sum < 0){
                start++;
            }else{
                end--;
            }
        }
        //}
    }
    
    return res;
}


// 下面的做法是错的，3sum==0，万一三个元素本身都是0怎么办，就没有push into result直接跳出去了
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