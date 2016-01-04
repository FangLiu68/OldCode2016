//
//  subsut.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/14/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a set of characters represented by a String, return a list containing all subsets of the characters.

 Assumptions
 There are no duplicate characters in the original set.
 ​Examples
 Set = "abc", all the subsets are [“”, “a”, “ab”, “abc”, “ac”, “b”, “bc”, “c”]
 Set = "", all the subsets are [""]
 Set = null, all the subsets are []
 */

#include "Header.h"
/*
 DFS实质：
 找一个图、树等等里面所有的可能性
 基本上，有i个元素可以选择，就有i层
 每层的状态由 选i/不选i/选几个i 这几个状态
 base case经常是:
 最底层下面的NULL的情况（经常是index==input.size()之类）
 主体经常是：
 每个状态茬出几个茬
 */

/*
 what does it store on each level?
 level = 3
 add i-th element i or not put
 element_Index =  0 1 2
 a b c
 take a, Yes or No?       so there are 2^3 subsets
 take b, Yes or No?
 take c, Yes or No?
 How many different states should we try to put on this level?
 put the element into the set or  not, so two states
 
 empty                            ()
                             /           \
                        add 'a'            add ''
 level0 (for a)            'a'               ''
                        /     \             /    \
                    add 'b'    add ''    add 'b'  add ''
 level1 (for b)      'ab'       'a'       'b'      ''
                   /    \      /   \     /   \     /   \
 level2 (for c)  add'c'      add'c'     add'c'   add'c'
                 'abc'  'ab'  'ac'  'a'  'bc'  'b'  'c'  ''
 level3          print
 
 由上图可见，每个点都叉出2个状态
 */

// print all subset of set (strings)
void DFS_Subset(string input_string, int cur_level, string solu) {
    // base case
    // only when we have examined all the elements in the set,
    // we can terminate DFS and print the solution
    if(input_string.size() == cur_level){
        cout << solu << " ";
        return;
    }

    // for each of the element in the set, either we append it to the solution or we do not append it
    // case 1:  add element input_string[cur_level] into subset
    solu.push_back(input_string[cur_level]);
    DFS_Subset(input_string, cur_level + 1, solu);
    // when we falling back to the previous state, we need to clean up the change made to the solution at current state
    solu.pop_back();

    // case 2: do not add….
    DFS_Subset(input_string, cur_level + 1, solu);
}

//=============================================================================
// get all subset of set (strings)
void helper_subsetI_str(string input, int cur_level, string cur, vector<string>& res);
vector<string> subsetI_str(string input){
    vector<string> res;
    if(input.empty()){
        return res;
    }
    string cur;
    helper_subsetI_str(input, 0, cur, res);
    return res;
}

void helper_subsetI_str(string input, int cur_level, string cur, vector<string>& res){
    if(input.size() == cur_level){
        res.push_back(cur);
        return;
    }
    cur.push_back(input[cur_level]);
    helper_subsetI_str(input, cur_level+1, cur, res);
    cur.pop_back();

    helper_subsetI_str(input, cur_level+1, cur, res);
}

//======================================================================
/*
 Given a set of distinct integers, S, return all possible subsets.

 Note:
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If S = [1,2,3], a solution is:
 [
 [3],
 [1],
 [2],
 [1,2,3],
 [1,3],
 [2,3],
 [1,2],
 []
 ]
 */
void helper_subsetI_int(vector<int>& s, int cur_level, vector<int> tmp, vector<vector<int>>& res);
vector<vector<int> > subsetI_int(vector<int> &S) {
    vector<vector<int>> res;
    if(S.empty()) return res;
    vector<int> tmp;
    helper_subsetI_int(S, 0, tmp, res);
    sort(res.begin(), res.end());
    return res;
}

void helper_subsetI_int(vector<int>& s, int cur_level, vector<int> tmp, vector<vector<int>>& res){
    if(s.size() == cur_level){
        sort(tmp.begin(), tmp.end());
        res.push_back(tmp);
        return;
    }
    tmp.push_back(s[cur_level]);
    helper_subsetI_int(s, cur_level+1, tmp, res);
    tmp.pop_back();
    helper_subsetI_int(s, cur_level+1, tmp, res);
}

/*
int main(){
    string input_string = " ";
    //int cur_level = 0;
    //string solu = "";
    //DFS_Subset(input_string, cur_level, solu);
    vector<string> res = subset(input_string);
    for(int i=0; i<res.size(); ++i){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
*/
