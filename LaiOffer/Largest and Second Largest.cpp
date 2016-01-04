//
//  Largest and Second Largest.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/21/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Use the least number of comparisons to get the largest and 2nd largest number in the given integer array. Return the largest number and 2nd largest number.

 Assumptions
 The given array is not null and has length of at least 2
 Examples
 {2, 1, 5, 4, 3}, the largest number is 5 and 2nd largest number is 4.
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 1. v_index里存的是每个数的Index
 2. 两两成对儿比较，每次把较大的数放在v_half_index里
    同时用map记录较大的这个数和谁比较过. key:较大数的index；value:vector存储他都和谁比较过
 3. 每轮比较结束，v_index和v_half_index对换
 4. 最大的数就是v_index里面最后剩下的那个数，记为max
    第二大的数在map里map[max]对应的vector中，liner scan就能找到第二大的数
 每轮比较次数指数递减，一共
 */

int findMax(vector<int> v) {
    int max = INT_MIN;
    for (int i = 0; i < v.size(); ++i) {
        if (max < v[i]) max = v[i];
    }
    return max;
}
// Find two largest numbers in an array with minimum comparison.
void findTwoLargest(vector<int> arr, int& l1, int& l2) {
    if (arr.size() < 2) return;

    // a temp vector storing all idices. Initialized as 0, 1, 2, 3....
    vector<int> v_index;
    for (int i = 0; i < arr.size(); ++i){
        v_index.push_back(i);
    }

    // key: index. value: all values that the v[index] number has compared to
    // index to compared numbers
    unordered_map<int, vector<int> > mp;

    // Two-two compare, until there's only one element left (the final winner)
    while (v_index.size() > 1) {
        vector<int> v_half_index;
        for (int i = 0; i < v_index.size(); i += 2) {
            if (i == v_index.size() - 1) {
                v_half_index.push_back(v_index[i]);
                continue;
            }
            if (arr[v_index[i]] > arr[v_index[i + 1]]) {
                v_half_index.push_back(v_index[i]);
                mp[v_index[i]].push_back(arr[v_index[i + 1]]);
            }
            else {
                v_half_index.push_back(v_index[i + 1]);
                mp[v_index[i + 1]].push_back(arr[v_index[i]]);
            }
        }
        v_index.clear();
        v_index = v_half_index;
    }
    l1 = arr[v_index[0]];
    l2 = findMax(mp[v_index[0]]);
}

vector<int> largestAndSecond(vector<int> array) {
    vector<int> res;
    if(array.empty()){
        return res;
    }

    vector<int> index;
    for(int i=0; i<array.size(); ++i){
        index.push_back(i); // store all index
    }
    unordered_map<int, vector<int>> mp;
    while(index.size() > 1){
        vector<int> half_index;
        for(int i=0; i<index.size(); i=i+2){ // 注意这里i [0, index.size())
            if(i == index.size()-1){
                half_index.push_back(index[i]);
                continue;
            }
            if(array[index[i]] < array[index[i+1]]){
                half_index.push_back(index[i+1]);
                mp[index[i+1]].push_back(array[index[i]]);
            }else{
                half_index.push_back(index[i]);
                mp[index[i]].push_back(array[index[i+1]]);
            }
        }
        index.clear();
        index = half_index;
    }

    int first = array[index[0]];
    int second = INT_MIN;
    vector<int> has_second = mp[index[0]];
    for(int i=0; i<has_second.size(); ++i){
        if(second < has_second[i]){
            second = has_second[i];
        }
    }
    res.push_back(first);
    res.push_back(second);
    return res;
}

/*
int main(){
    vector<int> arr = {2,1,5,4,3};
    int l1 = 0;
    int l2 = 0;
    findTwoLargest(arr, l1, l2);
    cout << l1 << " " << l2 << endl << endl;

    vector<int> res = largestAndSecond(arr);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}
*/