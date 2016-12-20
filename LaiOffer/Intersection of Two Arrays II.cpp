//
//  Intersection of Two Arrays II.cpp
//  LaiOffer
//
//  Created by Fang Liu on 8/3/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//


/*
 Given two arrays, write a function to compute their intersection.
 
 Example:
 Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 
 Note:
 Each element in the result should appear as many times as it shows in both arrays.
 The result can be in any order.
 
 Follow up:
 What if the given array is already sorted? How would you optimize your algorithm?
 if sorted, then O(m+n)
 
 What if nums1's size is small compared to nums2's size? Which algorithm is better?
 
 What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
 If only nums2 cannot fit in memory, put all elements of nums1 into a HashMap, read chunks of array that fit into the memory, and record the intersections.
 If both nums1 and nums2 are so huge that neither fit into the memory, sort them individually (external sort), then read 2 elements from each array at a time in memory, record intersections.
 */

#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

/*
 1. sort two arrays, then use two pointers, iterate two arrays together
 time: max(m, n)log(max(m, n))
 space: m + n
 2. use hash table to store nums1 elements, iterate hashtable to check all nums2 elements
 time: m + n
 space: m or n
 */
vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
    vector<int> res;
    if(nums1.empty() || nums2.empty()) return vector<int>(0);
    
    unordered_map<int, int> mp;
    for(int i=0; i<nums1.size(); ++i) mp[nums1[i]] = 0;
    for(int i=0; i<nums1.size(); ++i) mp[nums1[i]]++;
    
    for(int i=0; i<nums2.size(); ++i){
        if(mp.find(nums2[i]) != mp.end() && --mp[nums2[i]]>=0){
            res.push_back(nums2[i]);
        }
    }
    
    return res;
}