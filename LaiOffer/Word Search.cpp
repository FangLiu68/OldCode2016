//
//  Word Search.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/12/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a 2D board and a word, find if the word exists in the grid.
 The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. 
 The same letter cell may not be used more than once.

 For example,
 Given board =
 [
 ["ABCE"],
 ["SFCS"],
 ["ADEE"]
 ]
 word = "ABCCED", -> returns true,
 word = "SEE", -> returns true,
 word = "ABCB", -> returns false.
 */

#include "Header.h"

/*
 以board上的每个cell为出发点，用DFS向上 下 左 右 四个方向搜索匹配word。
 搜索的时候要考虑board边界，cell是否已经在DFS的路径上被用过，以及cell上的值是否与word的当前字符匹配。
 为了跟踪DFS的路径避免同一个cell被访问多次，用一个visited矩阵来代表board上的任意cell(i,j)是否已经被访问过。
 */

bool helper_wordSearch(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col, string& word, int index){
    if(index == word.size()){
        return true;
    }

    if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || visited[row][col] || board[row][col] != word[index]){
        return false;
    }

    visited[row][col] = true;
    helper_wordSearch(board, visited, row+1, col, word, index+1);
    helper_wordSearch(board, visited, row-1, col, word, index+1);
    helper_wordSearch(board, visited, row, col+1, word, index+1);
    helper_wordSearch(board, visited, row, col-1, word, index+1);
    visited[row][col] = false;

    return false;
}

bool wordSearch(vector<vector<char>>& board, string word){
    int row = board.size();
    int col = board[0].size();
    if(row < 0 || col < 0){
        return false;
    }
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    for(int i=0; i<row; ++i){
        for(int j=0; j<col; ++j){
            if(helper_wordSearch(board, visited, i, j, word, 0)){
                return true;
            }
        }
    }
    return false;
}