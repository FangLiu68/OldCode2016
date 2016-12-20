//
//  Missing Number.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/8/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an integer array of size N - 1, containing all the numbers from 1 to N except one, find the missing number.

 Assumptions
 The given array is not null, and N >= 1
 Examples
 A = {2, 1, 4}, the missing number is 3
 A = {1, 2, 3}, the missing number is 4
 A = {}, the missing number is 1
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
 M1:  hash_table     to count the number of occurrence of each number

 M2: [1-N]所有数字相加的和 减去 数组里面所有数字相加的和
 1 + 2 + 3 +4 …+n   = n(n-1)/2        sum1
 a[0] +a[1] +.... a[n-2]   == sum 2
 sum1 - sum2 == the missing number.
 
 M3: [1-N]所有数字 XOR 数组里面的所有数字，结果就是缺少的
 
 M4: 桶排序 swap- a[i]=i+1
     {3,1,5,4} -> {1,5,3,4} 返回2
 */

// 不管是不是sorted都可以
// M2: 从1加到arr.size()+1 得到本来应该的sum，减去实际在input里面的sum，就得到miss的
int find_missing_add(vector<int> input){
    if(input.empty()) return 1;
    int sum1 = 0;
    int sum2 = 0;
    for(int i=0; i<=input.size()+1; ++i) // 注意是从i=0开始，第一个sum为0
        sum1 = sum1+i;
    for(int i=0; i<input.size(); ++i)
        sum2 = sum2+input[i];
    return sum1-sum2;
}

// M3: XOR
int find_missing_XOR(vector<int> input){
    if(input.empty()){
        return 1;
    }
    int res=0; // 0异或任何数都是任何数本身
    for(int i=0; i<input.size(); ++i){
        res ^= input[i];
    }
    for(int i=1; i<=input.size()+1; ++i){
        res ^= i;
    }
    return res;
}

// M4: bucket sort
int find_missing_bucketSort(vector<int> input){
    if(input.empty()){
        return 1;
    }
    for(int i=0; i<input.size(); ++i){
        while(input[i]!=i+1 && input[i]<=input.size()){
            swap(input[i], input[input[i]-1]);
        }
    }
    for(int i=0; i<input.size(); ++i){
        if(input[i] != i+1){
            return i+1;
        }
    }
    return input.size()+1;
}

// given array containing number 1-n, one missing, find it
int find_missing(vector<int> input, int n){
    if(input.empty()){
        return 1;
    }
    int sum = 0;
    for(int i=0; i < n-1; ++i){
        sum = sum + input[i];
    }
    return (1+n)*n/2 - sum;
}

int find_missing_hash(vector<int> array) {
    // write your solution here
    if(array.empty()){
        return 1;
    }
    int N = array.size()+1;
    bool count[N];
    fill(count, count+N, false);
    for(int i = 0; i < array.size(); ++i){
        count[array[i]] = true;
    }
    for(int i = 1; i < array.size()+1; ++i){
        if(count[i] == false){
            return i;
        }
    }
    return array.size()+1;
}

// 先放在set里，再逐个查找set看是否有miss掉的
int find_missing_num2(vector<int> input) {
    if(input.empty()) return 1;
    unordered_set<int> s;
    for(int i = 0; i < input.size(); i++){
        s.insert(input[i]);
    }
    for(int i = 1; i <= input.size()+1; ++i){
        if(s.find(i) == s.end())
            return i;
    }
    return input.size()+1;
}
/*
int main(){
    vector<int> input = {1,3,2};
    cout << find_missing_bucketSort(input) << endl;
    return 0;
}*/
