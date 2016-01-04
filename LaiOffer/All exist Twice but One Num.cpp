//
//  All Exist Twice but One Num.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/3/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 only one number exists once, other numbers all exist twice
 Example - {1, 2, 3, 1, 3}, return 2
*/

#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;


/*
 Method 1: using HashSet, add to the hashset if the hashset not contains the value, if the hashset already contains the value, remove it from the hashset. the remaining element will be the answer. time complexity: O(n), space complexity: O(n)

 Method 2: XOR, since 1 ^ 1 = 0, 0 ^ 0 = 0, traverse the array and do XOR.
 time: O(n), space O(1)

 Method 3: integer = 32 bits, record number of 1s for each of the bits.
 for each bit,
 if the number of 1 is odd, then → 1
	if the number of 1 is even, then → 0
 time: O(n), space O(1)

 if contains all the number from [1 - n]
 Given an array contains n - 1 integers, only one number is missing from [1 - n]
 Method 4: sum
 time: O(n), space O(1)

 Method 5: sort the array → the number with same value will be neighbors.
 time: O(nlogn), space O(1)

 */

// time O(N), space O(N)
int all_twice_but_one(vector<int> input){
    if(input.empty()){
        return INT_MIN;
    }
    unordered_set<int> st;
    for(int i=0; i<input.size(); ++i){
        if(st.find(input[i]) == st.end()){
            st.insert(input[i]);
        }else{
            st.erase(input[i]);
        }
    }
    return *st.begin();
}
/*
int main(){
    vector<int> input = {1,2,3,1,3};
    cout << all_twice_but_one(input) << endl;
    return 0;
}*/