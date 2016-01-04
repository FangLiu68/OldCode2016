//
//  Is PostOrder of BST.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array with integers, determine whether the array contains a valid postorder traversal sequence of a BST.
 For example:   {3, 5, 4}  is valid
 { 3,  6,  2,  5,  4} is not valid

 root = 4
 / \
 {left_subtree 3} { 6  2 5right_subtree}
 root
 3 xxxxxx  |   xxxxxxxx5              4
 Step1:   take 4, and try to cut [0  n-2] elements into two parts
 Step 2: For left,

 1  2
 public boolean determine(int[] array, int left, int right) {
 if(left <= right) {
	return true;
	}
	int rightNum = array[right];
	int cut_index;
	for(int i = left; i <= right - 1; i++) {
	if(array[i] > rightNum) {
	if (helper(rightNum, i, right - 1) == false) {
	return false;
 }
	cut_index = i;
	break;
 }
	}
	return determine(array, left, cut_index - 1)  && determine(array, cut_index, right);
 }



 private boolean helper(rightNum, int left, int right) {
 for(int i = left; i <= right; i++) {
 if(array[i] < rightNum) {
 return false;
 }
	}
	return true;
 }

 */