//
//  permutation no dup.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/14/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a string with no duplicate characters, return a list with all permutations of the characters.

 Examples
 Set = “abc”, all permutations are [“abc”, “acb”, “bac”, “bca”, “cab”, “cba”]
 Set = "", all permutations are [""]
 Set = null, all permutations are []

 */

#include "Header.h"

void swap_permuI(string& input, int i, int index);
void helper_permutation_noDup(string& input, vector<string>& res, int index);
vector<string> permutation_noDup(string input) {
    vector<string> res;
    if(input.empty()){
        res.push_back("");
        return res;
    }
    int index = 0;
    helper_permutation_noDup(input, res, index);
    return res;
}

// index is the current layer that we are tyring
void helper_permutation_noDup(string& input, vector<string>& res, int index){
    if(index == input.size()){ // index的大小就是层数
        res.push_back(input);
        return;
    }

    // 把index后面的所有字符都和i位置上的字符互换
    // put each letter in the index-th position of the input str.
    /*
     
     empty                        abc
                    /              |            \
                swap(0,0)        sp(0,1)        sp(0,2)
     level0      (a)bc           (b)ac           (c)ba
                 /    \           /   \           /   \
             sp(1,1) sp(1,2) sp(1,1) sp(1,2) sp(1,1) sp(1,2)
     level1  (ab)c   (ac)b   (ba)c    (bc)a    (cb)a   (ca)b
               |       |       |         |       |       |
             sp(2,2)  sp(2,2)  sp(2,2)  sp(2,2)  sp(2,2) sp(2,2)
     level2  (abc)   (acb)     (bac)     (bca)    (cba)   (cab)
     level3   print
     
     由上图可见，最开始每个点叉出3格状态，每层递减，最后一层每个点只叉出1个状态
     
     index是层数(从0开始),同时Index也是i的起始点(从哪个位置开始往后逐步swap)
     最开始在level0，就是index为0的上一层，input是原始的输入abc
     在第0层，index为0，i从0开始直到input.size()-1，将0与i所指向的每一个字符swap
            注意，i每次与index swap完毕，继续进行下一层（index+1），然后i+1要继续和index swap的时候，我们在这之前要在前一步的后面swap back
            因为DFS在相同层上try不同状态的时候，都要先回到上一层的父节点（swap back），才能继续另一个状态
     在第1层，index为1，i从1开始直到input.size()-1, 将1与i所指向的每一个字符swap
     在第2层，index为2，i从2开始直到input.size()-1，将2与i所指向的每一个字符swap
     在第3层，index为3，i与input size相等，就将此时的input放入res

     在上一层上，对于每个父节点而言，他有可能在这一层上叉出K个状态
     
     DFS的程序将要call自己几次，就表明他有几层
     写在base case下面的这几个状态（for()循环），就表明每层上的每个节点将要叉出几个状态
     当叉出的状态数不能确定，状态数与层数有关时，就用for()循环来做
     */
    for(int i=index; i<input.size(); ++i){
        swap_permuI(input, index, i);
        helper_permutation_noDup(input, res, index+1);
        swap_permuI(input, index, i);
    }
}

void swap_permuI(string& input, int i, int index){
    if(i == index) return;
    char tmp = input[i];
    input[i] = input[index];
    input[index] = tmp;
}

/*
int main(){
    string input = "ab";
    vector<string> res = permutation_noDup(input);
    for(int i=0; i<res.size(); ++i){
        cout << res[i] << endl;
    }
    cout << endl;
    return 0;
}*/