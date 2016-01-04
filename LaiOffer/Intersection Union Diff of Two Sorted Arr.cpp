//
//  Intersection Union Diff of Two Sorted Arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/30/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/* find intersection/ union/ difference of two sorted arrays
 two sorted arrays, intersection/union/difference

 A = {1, 2, 5, 7}
 B = {2, 4, 6}

 intersection = {2}
 union = {1, 2, 4, 5, 6, 7}
 difference_A (in A but not in B) = {1, 5, 7}
 difference_B (in B but not in A) = {4, 6}
 */
#include <iostream>
#include <vector>
using namespace std;

void find_intersection_union_diff(vector<int> arr1, vector<int> arr2, vector<int>& Intersection, vector<int>& Union, vector<int>& Diff1, vector<int>& Diff2){
    if(arr1.empty() || arr2.empty()){
        return ;
    }
    int index1 = 0;
    int index2 = 0;
    while(index1 < arr1.size() && index2 < arr2.size()){
        if(arr1[index1] == arr2[index2]){
            Union.push_back(arr1[index1]);
            Intersection.push_back(arr1[index1]);
            index1++, index2++;
        }else if(arr1[index1] > arr2[index2]){
            Union.push_back(arr2[index2]);
            Diff2.push_back(arr2[index2]);
            index2++;
        }else{
            Union.push_back(arr1[index1]);
            Diff1.push_back(arr1[index1]);
            index1++;
        }
    }
    while(index1 < arr1.size()){
        Union.push_back(arr1[index1]);
        Diff1.push_back(arr1[index1]);
        index1++;
    }
    while(index2 < arr2.size()){
        Union.push_back(arr2[index2]);
        Diff2.push_back(arr2[index2]);
        index2++;
    }
}