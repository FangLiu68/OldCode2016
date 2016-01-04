//
//  Majority Num.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/17/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// 给一个integer array, 允许duplicates, 而且其中某个未知的integer的duplicates的个数占了整个array的一大半（>50%）。如何有效地找出这个integer
#include <vector>
#include <iostream>
using namespace std;

/*
 Method1:
 hashtable <key = integer, value = counter(integer)>
 time = O(N)+ O(N) 扫一遍保存+检查一遍hashmap[key]
 space = O(N)
 
 Method2:
 sort time = O(NlogN), space = O(1)
 return A[n/2]
 
 Method3:
 O(1): maintain a counter for the current candidate
 出现两个不同的数，就可以同时删除这两个数。最后剩下的那个数，就是结果
 */

int get_majorNum(vector<int> input){
    if(input.empty()){
        return INT_MIN;
    }
    int count = 1;
    int can = input[0];
    for(int i=1; i<input.size(); ++i){
        if(input[i] == can){
            count++;
        }else{
            if(count == 0){
                can = input[i];
                count = 1;
            }else{
                count--;
            }
        }
    }
    return can;
}
/*
int main(){
    vector<int> input = {1,1,1,1,1,2,3};
    cout << get_majorNum(input) << endl;
    return 0;
}*/