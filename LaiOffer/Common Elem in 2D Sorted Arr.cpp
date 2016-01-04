//
//  Common Elem in 2D Sorted Arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a 2D integer array, where every row is sorted in increasing order. How to find a common element in all rows. If there is no common element, then returns -1.
 Example:
 Input: Array[4][5] =
                  { {0, 1, 3, 4, 6},
                    {3, 4, 6, 8, 10},
                    {2, 6, 7, 9, 11},
                    {0, 3, 6, 7, 9},
                  };
 Output: 6
 n rows
 m columns
 M1: use 2 hash_tables
 unordered_set<int> s = 0 ,1, 3, 4, 6
 s = merge(s1, row2) ->3, 4, 6
 Time = O(m*n)
 Space = O(m)

 int common_element(const vector<vector<int>>& matrix) {
 int row = matrix.size();
 if (row == 0) {
 return false;
 }
 int col = matrix[0].size();
 if (col == 0) {
 return false;
	}
 unordered_set<int> s1;
 for (int i = 0; i < col; ++i) {
 s1.insert(matrix[0][i]);
 }
 for (int i = 1; i < row; ++i) {
 unordered_set<int> s2;
 for (int j = 0; j < col; ++j) {
 s2.insert(matrix[i][j]);
 }
 unordered_set<int>::iter;
 for (iter = s1.begin(); iter != s1.end(); ++iter) {
 if (s2.find(*it) == s2.end()) {
 s1.erase(it);
 --iter;
 }
 }
 }
 if (s1.size() > 0) {
 return *(s1.begin() + 1);
 }
 else {
 return -1;
	}
 }









 M2: Can you somehow only use one integrated hash_table?
 Input: Array[4][5] =
          1        { {0, 1, 3, 4, 6},  {3, 4, 6)
                     i1
          2          {3, 4, 6, 8, 10}, {
                     i2
          3         {2, 6, 7, 9, 11},
	         i3
	        {0, 3, 6, 7, 9},
          i4
 <3, falase> <4, false> <6, false>
 hash_table = <number, <set<int row>, counter>>
 ???
 public int findCommonElement(int[][] board)
 {
 if(board.length == 0)
 return -1;
 HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
 int prev = 0;
	for(int i = 0; i < board[0].length; i++)
	{
	if(!hm.containsKey(board[0][i]))
	hm.put(board[0][i],1);
	}
	for(int i = 1; i < board.length; i++)
	{
	prev = board[0][0];
	for(int j = 0; j < board[i].length; i++)
	{
	if(hm.containsKey(board[i][j]) && board[i][j] != prev)
	{
	if(hm.get(board[i][j]) == i)
	{
	hm.put(board[i][j],hm.get(board[i][j])++);
	prev = board[i][j];
 }
	}
	}
	}
	Iterator iter = hm.entrySet().iterator();
	while (iter.hasNext()) {
	Map.Entry entry = (Map.Entry) iter.next();
	if((int)entry.getValue() == board.length)
	return entry.getKey();
	}
	return -1;
 }
 O(mn) time
 O(n) space to store all i_1, ….. i_k… i_n
 int common_element(const vector<vector<int>>& matrix) {
 int row = matrix.size();
 if (row == 0) {
 return -1;
 }
 int col = matrix[0].size();
 if (col == 0) {
 return -1;
 }
 vector<int> indecies(row, 0);
 while (1) {
 int maxPos = helper(matrix, indecies);
 int count = 1;
 for (int i = 0; i < row; ++i) {
 if (matrix[i][indecies[i]] < matrix[maxPos][indecies[maxPos]])
 indecies[i]++;
 if (indecies[i] >= col) {
 break;
 }
 if (matrix[i][indecies[i]] == matrix[maxPos][indecies[maxPos]])
 count++;
 else {
 count++;
 }
 if (count == row) {
 return matrix[maxPos][indecies[maxPos]];
 }
 }
 }
 return -1;
 }
 int helper(const vector<vector<int>>& matrix, vector<int>& indecies) {
 int maxPos = 0;
 for (int i = 1; i < indecis.size(); ++i) {
 if (matrix[i][indecis[i]] > matrix[minPos][indecis[minPos]]) {
 maxPos = i;
 }
 }
 return maxPos;
 }
 M3:
 public class AllCommentElement {
 public int allCommnetElement ( int[][] array ) {
 if ( array == null || array.length == 0 || array[0].length == 0 ) {
 return Integer.MIN_VALUE;
 }
 int localMax = Integer.MIN_VALUE;
 int columnMax = array[0].length;
 int[] rowIndex = new int [ columnMax ];
 boolean updated = true;
 while ( updated ) {
 updated = false;
 for ( int row = 0; row < array.length; row ++ ) {
 if ( array[row][ rowIndex[row] ] < localMax ) {
 while ( rowIndex[row] < columnMax &&
 array[row] [ rowIndex[row] ] < localMax ) {
 rowIndex[row] ++;
 }
 if ( rowIndex[row] == columnMax ) {
 return Integer.MIN_VALUE; // cannot find
 }
 updated = true;
 }
 if ( array [ row ] [ rowIndex[row] ] > localMax ) {
 localMax = array[row] [ rowIndex[row] ];
 updated = true;
 }
 }
 }
 return localMax;
 }
}
 */