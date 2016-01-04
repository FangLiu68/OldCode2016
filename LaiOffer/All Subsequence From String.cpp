//
//  All Subsequence From String.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
  Given a sorted string of chars with duplicated chars, return all possible subsequence. The solution set must not contain duplicate subsequence.
 
 For example,
 string input  = “ab1b2”;
 output =
 a
 b
 ab // note that you cannot have both ab1 and ab2 in the solution
 bb
 abb
 string  = “a b1 b2 b3 c”
 a {a} {not a}
	        /          \
 b1             {a b1}          {a, -} // 0 b
                /             \                   |
 b2     {ab1b2}         {ab1 -} 1b    |
           /              \            |          |
 b3   {ab1b2b3} {ab1b2}  |       |  // 2 b
     /            \            |       |           |
 c   {ab1b2b3c}     {a,b1b2- c/c} {a,b1 -- c/c}   {a ---- c not c)
        /         \
 b4    0 1 2 3  4         b4   not-b4
 private void helper(List<List<Integer>> res, List<Integer> tmp, int[] num, int index){
        if(index == num.length){
            res.add(new ArrayList<Integer>(tmp));    // base case
            return;
        }
        // Case1: Add num[index]
        tmp.add(num[index]);
        helper(res, tmp, num, index + 1);
        tmp.remove(tmp.size() - 1);

        while(index < num.length - 1 && num[index+1] == num[index]) {
            index++;
        }

        // Case2: Do not add num[index]
        helper(res, tmp, num, index + 1);
    }
 

 */