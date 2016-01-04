//
//  Is in Sorted 2D Arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a 2D array, in which each row is sorted in an ascending order and each column is sorted in ascending order. How to determine whether a target number x is in the array or not.
 1    2     3 4     5 6
 2    3     4 5     6 7
 3    4.5  5 6     7 8
 4    5     6 7     8 9
 E.g.,
 target = 4.5 return true;
 target = 0 return false;
 O(m+n)
 bool find(const vector<vector<int>>& matrix, int target) {
 int row = matrix.size();
 if (row == 0) {
 return false;
 }
 int col = matrix[0].size();
 if (col == 0) {
 return false;
 }
 int index = binary_search(matrix, target, 0, col - 1);
 return find_helper(matrix, target, 0, index);
 }
 int binary_search(const vector<vector<int>>& matrix, int target, int left, int right) {
 while (left < right - 1) {
 int mid = (left + right) / 2;
 if (matrix[0][mid] > target) {
 right = mid - 1;
 }
 else {
 left = mid;
 }
 }
 if (matrix[0][right] < target) {
 return right;
 }
 if (matrix[0][left] < target) {
 return left;
 }
 return -1;
 }
 bool find_helper()...
 

 */