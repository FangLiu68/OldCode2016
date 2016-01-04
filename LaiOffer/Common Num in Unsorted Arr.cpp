//
//  Common Num in Unsorted Arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/30/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include "Header.h"

/*
 Find all numbers that appear in both of the two unsorted arrays.

 Assumption
 Both arrays are not null.
 There are no duplicate numbers in each of the two arrays respectively.
 Exmaples
 A = {1, 2, 3}, B = {3, 1, 4}, return [1, 3]
 A = {}, B = {3, 1, 4}, return []
 */
// O(N) runtime, O(N) space
vector<int> common_num_in_two_unsorted_arr_noDup(vector<int> a, vector<int> b){
    vector<int> res;
    if(a.empty() || b.empty()) return res;
    unordered_set<int> s;
    for(int i=0; i<a.size(); i++) s.insert(a[i]);
    for(int i=0; i<b.size(); i++){
        if(s.find(b[i]) != s.end())
            res.push_back(b[i]);
    }
    return res;
}

/*
 Find all numbers that appear in both of two unsorted arrays.

 Assumptions
 Both of the two arrays are not null.
 In any of the two arrays, there could be duplicate numbers.
 Examples
 A = {1, 2, 3, 2}, B = {3, 4, 2, 2, 2}, return [2, 2, 3] (there are both two 2s in A and B)
 */
// 对于有重复元素的数组，就不能用set。要先排序，再比较
// O(NlogN) runtime(sort use nlogn. my assume)
vector<int> common_num_in_two_unsorted_arr_hasDup(vector<int> a, vector<int> b) {
    vector<int> res;
    if(a.empty() || b.empty()) return res;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int index1 = 0;
    int index2 = 0;
    while(index1<a.size() && index2<b.size()){
        if(a[index1] == b[index2]){
            res.push_back(a[index1]);
            index1++;
            index2++;

        }else if(a[index1] < b[index2]){
            index1++;
        }else{
            index2++;
        }
    }
    return res;
}
/*
int main(){
    vector<int> a = {2,1,2,3,2}; //
    vector<int> b = {2,2,2};

    vector<int> res = common_num_in_two_unsorted_arr_hasDup(a,b);
    for(int i=0; i<res.size(); i++) cout << res[i] << " ";
    cout << endl;
    cout << a[91] << endl; // index超过vector赋值的大小的时候，是不会报错的，和array不同
    cout << b[3] << endl;
    return 0;
}*/