//
//  All exist Three times but One Num.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/3/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 only one number exists once, other three times
 Example {1, 2, 3, 1, 1, 3, 3}, return 2
 */

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

/*
 Naive Solution: Method 1 - HashMap record # of existence
 Better Solution: Method 3 - time/complexity
 Best Solution: Method 2? - “XOR” - how to let every 3 “1”s to be 0?

 0 → 1 → 0

 two bits to record how many “1”s seen so far.
 (0,     0) → (0, 1) → (1, 0) → (1, 1) ⇔ (0, 0)
 two   one

 int one = 0;
 int two = 0;

 one:
 0 + 0 = 0
 0 + 1 = 1
 1 + 0 = 1
 1 + 1 = 0
 two:
 1). one == 1 && value == 1 → two = 1
 2). two == 1 → two = 1

 int one = 0;
 int two = 0;
 for (int value : array) {
 two  |= one & value;
 one ^= value;
 //if (two and one are (1, 1), they will be changed to (0, 0))
 int three = one & two;
 one &= ~three;  // one ^= three
 two &= ~three;  //  two ^= three
 }
 return one;
 */

// time O(N), space O(N)
int all_threeTimes_but_one(vector<int> input){
    if(input.empty()){
        return INT_MIN;
    }
    unordered_map<int, int> mp;
    for(int i=0; i<input.size(); ++i){
        if(mp.find(input[i]) != mp.end()){
            mp[input[i]]++;
        }else{
            mp[input[i]] = 1;
        }
    }
    for(unordered_map<int, int>::iterator IT = mp.begin(); IT != mp.end(); ++IT){
        if(IT->second == 1){
            return IT->first;
        }
    }
    return INT_MIN;
}
/*
int main(){
    vector<int> input = {1, 2, 3, 1, 1, 3, 3};
    cout << all_threeTimes_but_one(input) << endl;
    return 0;
}*/