//
//  2Sum One Pair.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/24/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Suppose only exist one pairs of elements in a given array that sum to the given target number.
 Return the pairs of indices.

 Assumptions
 The given array is not null and has length of at least 2.
 Examples
 A = {1, 5, 2, 4}, target = 5, return [0, 3]
 A = {1, 3, 2, 4}, target = 6, return [2, 3]
 */

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// 如果只有一个结果
/*
 注意：不可以把所有arr[i]--i的配对全部先放入map中。例如输入：3，2，4；target=6
 如果先全部在map中放好，由于3+3=6，对第一个元素3找剩余数时，我们以为第一个遇到的3就是剩余数，于是直接返回（1，1），错误结果。
 一定要先寻找gap，再往map里面放入配对。
 记住：map里的value是arr[i]的Index，即i。如果我们都放的是gap的话，到时候找不出这个gap的index是多少。
 
 1 0
 3 1
 2 2
 
 */
// hash. 用map存储每个数的下标。time complexity O(N), space complexity O(N)
pair<int, int> twoSumOnePair(vector<int> &numbers, int target) {
    pair<int, int> res;
    if(numbers.empty()) return res;
    unordered_map<int, int> mp; // key:numbers[i], value: i
    for(int i=0; i<numbers.size(); i++){
        int gap = target - numbers[i];
        if(mp.find(gap) != mp.end()){
            res.first = mp[gap]+1;
            res.second = i+1;
        }
        mp[numbers[i]] = i; // 注意这里的顺序，我们一定要先在Map中查找gap，再把当前元素和他的Index放入Map中。这样可以避免当gap和当前元素的值相同时，我们把当前元素的值误以为gap
    }
    return res;
}
/*
int main(){
    vector<int> input = {1, 3,2,4};
    int target = 6;
    cout << twoSumOnePair(input, target).first << " " << twoSumOnePair(input, target).second << endl;
    return 0;
}
*/