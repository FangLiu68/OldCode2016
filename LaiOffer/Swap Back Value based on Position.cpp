//
//  Swap Back Value based on Position.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/9/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/* Given a value array with its corresponding position array, swap back the value array.
    exmpale:
 value = {1, 2, 3}, pos = {2, 1, 0} → {3, 2, 1}

 Swap pos {2, 1, 0} → {0, 1, 2} at the same time swap the value.
 方法：swap position的同时swap value
*/

#include <vector>
#include <iostream>
using namespace std;

vector<int> swap_back(vector<int> input, vector<int> position){
    vector<int> res;
    if(input.empty() || position.empty()){
        return res;
    }
    // 注意，position和value是绑定的，swap时候要先swap value，因为swap position之后position就变了，这时候再swap value就晚了
    for(int i=0; i<position.size(); ++i){
        while(position[i]!=i){
            swap(input[i], input[position[i]]);
            swap(position[i], position[position[i]]);
        }
    }
    return input;
}
/*
int main(){
    vector<int> input = {4,8,2,6};
    vector<int> position = {2,1,0,3};
    vector<int> res = swap_back(input, position);
    for(int i=0; i<res.size(); ++i){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
*/


