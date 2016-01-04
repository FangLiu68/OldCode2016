//
//  Get Count of Right Smaller Nums.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array A[N] with all positive integers from [1...N]. How to get an array B[N] such that B[i] represents how many elements A[j] that are smaller than A[i] and  j > i.
 For example, given  A[N] = { 4, 1, 3, 2 }, we should get B[N] = { 3, 0, 1, 0 }.   Requirement:    Time = O(nlogn).
 
 
 A[N] = {    4(0)      1(0)       |       3(0)       2(0)   }
     4    |      1
 left_half   =  4     left_half = 3      3
	       i          i
 right_half =  1 right_half = 2      2
                           j=1         j=1
 solution_L= { 1(0),   4(1)
                                 i
 solution_R =  {2(0) , 3(1)
                   j=2
 Final_solution = {1(0), 2(0), 3(1), 4(1+j = 1+2 = 3)

 */


/*
 Given an array A[N] with all positive integers from [1...N]. How to get an array B[N] such that B[i] represents how many elements A[j] that are smaller than A[i] and  j > i.
 For example, given  A[N] = { 4, 1, 3, 2 }, we should get B[N] = { 3, 0, 1, 0 }.   Requirement:    Time = O(nlogn).
 4 1   3 2
	 41                   32
        4      1 3      2
 4
            i=0
            1
     j=1
 solu = 1(0) 4(0+j=1)
 ================================
            14                   23
 4 (4, 0)
 i
 1(1, 0)
        j =1
 1 4 2 3
 (1, 0) (4, X=1)       (2, 0) (3, 1)
 i = 1                  j=2
 (1, 0) (2, 0) (3, 1) (4, 3)
 class Result {
 int value;
 int count;
 public Result(int value, int count);
 }
 public int[] getNewArray(int[] array) {
 if (array == null || array.length == 0) {
 return null;
	}
	Result[] result =  helper(array, 0, array.length);
	return getResult(result, array);
 }
 private int[] getResult(Result[] result,  int[] array) {
 HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
 int[] count = new int[result.length];
 for (int i = 0; i < result.length; i++) {
 map.put(result[i].value, result[i].count);
	}
	for (int i = 0; i < array.length; i++) {
	count[i] = map.get(result[i].value);
	}
	return count;
 }
 private Result[] helper(int[] array, int start, int end) {
 if (start >= end) {
 Result[] result = new Result[1];
 result[0] = new Result(array[start], 0);
 return result;
 }
 int mid = start + (end - start) / 2;
 Result[] leftRes = helper(array, start, mid);
 Result[] rightRes = helper(array, mid + 1, end);
 return merge(leftRes, rightRes);
 }
 private Result[] merge(Result[] leftRes, Result[] rightRes) {
 int newLength = leftRes.length + rightRes.length;
 Result[] result = new Result[newLength];
 int li = 0;
 int ri = 0;
 int index = 0;
 while (li < leftRes.length && ri < rightRes.length) {
 if (leftRes[li].value < rightRes[ri].value) {
 result[index++] = new Result(leftRes[li].value, leftRes[li].count + ri);
 li++;
 } else {
 result[index++] = new Result(rightRes[li].value, rightRes[ri].count);
 ri++;
 }
	}
	if (li < leftRes.length) {
	result[index++] = new Result(leftRes[li].value, leftRes[li].count + ri);
 li++;
	}
	if (ri < rightRes.length) {
	result[index++] = new Result(rightRes[ri].value, rightRes[ri].count);
	ri++;
	}
	return result;
 }

 */