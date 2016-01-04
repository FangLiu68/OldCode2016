//
//  All Combination of K Elem in Arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array of size n,  print all possible combinations of k elements in array. For example, if input array is {2, 1, 3, 4} and k == 2, then output should be {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4} and {3, 4}.
 Discussion:    {1, 2} and {2, 1}
 1 2 3 4
 level 0:  1 insert 1          not insert 1
 level 1:  2
 level 2:  3
 level 3: 4

 1  2  3  4
 3  (214 → 124)
         /   |   \
 ==========================================
 level0:     1       2          3      4
                    /   |   \   /   |   \
 level 1     2    3    4  1  3   4
 public void combineHelper(int[] array, int target, int index, List<List<Integer>> lists, ArrayList<Integer> res) {
 if (res.size() == target) {
 lists.add(new ArrayList<Integer>(res));
 return;
	} else if (res.size() > target) {
	return;
	}
	for (int i = index; i < array.length; i++) {
	int candidate = array[i];
	res.add(candidate);
	combineHelper(array, target, i + 1, lists, res);
	res.remove(res.size() - 1);
	}
 }

 */