//
//  Intersection of Two Arrays.cpp
//  LaiOffer
//
//  Created by Fang Liu on 8/3/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given two arrays, write a function to compute their intersection.
 
 Example:
 Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 
 Note:
 Each element in the result must be unique.
 The result can be in any order.
 */

#include <set>
#include <vector>
#include <iostream>
using namespace std;

/*
 Method 1:
 1. sort both arrays O(mlogm + nlogn)
 2. use two pointers, go over both arrays, find their intersection O(m+n)
 totally use O(mlogm + nlogn) time
 */

vector<int> intersection1(vector<int>& nums1, vector<int>& nums2){
    set<int> res;
    if(nums1.empty() || nums2.empty()) return vector<int>(0);
    
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    
    int index1 = 0;
    int index2 = 0;
    
    while(index1 < nums1.size() && index2 < nums2.size()){
        if(nums1[index1] < nums2[index2]){
            index1++;
        }else if(nums1[index1] > nums2[index2]){
            index2++;
        }else{
            res.insert(nums1[index1]);
            index1++, index2++;
        }
    }
    
    return vector<int>(res.begin(), res.end());
}

/*
 Method 2:
 1. sort the smaller array. suppose size of num1=m > size of num2=n, then O(nlogn)
 2. for each element k in m, binary search k in n, then O(mlogn)
 total nlogn+mlogn = (m+n)logn (when m>n)
 when m>>n, method2 is much better than method1
 */
int helper_binarySearch(vector<int>& input, int target);

vector<int> intersection2(vector<int>& nums1, vector<int>& nums2){
    set<int> res;
    if(nums1.empty() || nums2.empty()) return vector<int>(0);
    
    // we suppose nums1.size() < nums2.size()
    if(nums2.size() < nums1.size()){
        return intersection2(nums2, nums1);
    }
    
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    
    // search each element in nums2 in nums1
    for(int i=0; i<nums1.size(); ++i){
        int found = helper_binarySearch(nums2, nums1[i]);
        if(found == INT_MIN){
            continue;
        }else{
            res.insert(found);
        }
    }
    
    return vector<int>(res.begin(), res.end());
}

int helper_binarySearch(vector<int>& input, int target){
    if(input.empty()){
        return INT_MIN;
    }
    
    int left = 0;
    int right = input.size() - 1;
    
    while(left <= right){
        int mid = left + (right-left)/2;
        if(input[mid] == target){
            return target;
        }else if(input[mid] < target){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    
    return INT_MIN;
}

/*
 int main(){
 vector<int> nums1 = {1, 2, 3};
 vector<int> nums2 = {1, 3};
 vector<int> res = intersection2(nums1, nums2);
 for(int i=0; i<res.size(); ++i){
 cout << res[i] << " ";
 }
 cout << endl;
 return 0;
 }*/