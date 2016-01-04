//
//  All Combination of Factor could Multiply to Target.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
  Get all possible combinations of factors that can multiply to a target number.
 Example
 24=2*2*2*3
   = 2*2*6
    =2*3*4
    =2*12
    =3*8
    =4*6
 vector<int> = {12, 8, 6, 4, 3, 2
 
 
 // DFS  Method 2:
 public List<List<Integer>> getFactorCombination(int n) {
     List<List<Integer>> result = new ArrayList<>();
     getFactorCombinationHelper(n, n/2, result, new ArrayList<Integer>());
     return result;
 }

 // largest_factor
 private void getFactorCombinationHelper(int target, int largest_factor,
	                    List<List<Integer>> result, List<Integer> prefix) {
     if(target == 1) {
         result.add(new ArrayList<Integer>(prefix));   // base case
         return;
     }
     for(int i = largest_factor; i >= 2; i--) {
         if (target % i != 0) {
   continue;
 }
         prefix.add(i);
         getFactorCombinationHelper(target / i, i, result, sub);
         prefix.remove(sub.size() - 1);
     }
 }

 */