//
//  Find Two Repeating Num in Arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/31/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Find two repeating elements in a given array. The elements are from 1 to n. and there are two elements repeated. The array size is n+2.
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 第一种做法是桶排序，和first missing positive方法一样。O(n)time, O(1) space
 第二种用数学的做法 前提是不会溢出
 sum of array - sum(1 .. n) = p + q;
 mult of array / mult(1 .. n)   = p  * q;
 (p + q) ^ 2 - 4 * p *q = (p - q ) ^ 2 => p - q

 */

vector<int> two_repeating_nums(vector<int> input){
    vector<int> res(2);
    if(input.empty()){
        return res;
    }

    for(int i=0; i<input.size(); ++i){
        while(input[i]!=i+1 && input[i]!=input[input[i]-1]){
            swap(input[i], input[input[i]-1]);
        }
    }
    
    // 注意，用push_back是错的。初始化res size为2，如果用push_back，就在后面继续增加size。应该用res[i]来赋值
    //res.push_back(arr[index-1]);
    //res.push_back(arr[index-2]);
    res[0] = input[input.size()-1];
    res[1] = input[input.size()-2];
    return res;
}
/*
int main(){
    vector<int> arr = {3,1,3,2,2};
    vector<int> res = two_repeating_nums(arr);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}*/