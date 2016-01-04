//
//  Str Chained Form a Circle.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
  Given an array of strings, find if the strings can be chained to form a circle
 Input: arr[] = {"aaa", "bbb", "baa", "aab"};
 Output: Yes, the given strings can be chained.  The strings can be chained as "aaa", "aab", "bbb"  and "baa"

 Input: arr[] = {"aaa", "bbb"};
 Output: No

 Input: arr[] = {"aaa"};
 Output: Yes
 Solutions
	1. how many levels are there in the tree?
	2. how many staes can be branched from each state?
 public void findCircle(String[] array) {
 if (array == null || array.length == 0) {
 return;
	}
	findCircleHelper(array, 0);
 }
 public void findCircleHelper(String[] array, int index) {
 if (array.length == index) {
 if (array[0].charAt(0) == array[index - 1].charAt(array[index -1].length - 1)) {
 // print….
 }
	}
	for (int i = index; i < array.length; i++) {
	String prev = array[index- 1];
	String curr = array[i];
	if (curr.charAt(0) == prev.charAt(prev.size() - 1)) {
	swap(array, i, index);
	findCircleHelper(array, index + 1);
	swap(array, i, index);
	}
	}
 }
 private void swap(String[] array, int i, int j) {
 String tmp = array[i];
 array[i] = array[j];
 array[j] = tmp;
 }

 */