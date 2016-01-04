//
//  2Sum Data Structure Design.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/18/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Design and implement a TwoSum class. It should support the following operations: add and find.

 add - Add the number to an internal data structure.
 find - Find if there exists any pair of numbers which sum is equal to the value.

 For example,
 add(1); add(3); add(5);
 find(4) -> true
 find(7) -> false
 */

#include <unordered_map>
using namespace std;

/*
 Method 1:
 add – O(1) runtime, find – O(n) runtime, O(n) space – Store input in hash table:
 A simpler approach is to store each input into a hash table. 
 To find if a pair sum exists, just iterate through the hash table in O(n) runtime. 
 Make sure you are able to handle duplicates correctly.
 Implemted as below.
 
 Method 2:
 add – O(log n) runtime, find – O(n) runtime, O(n) space – Binary search + Two pointers:
 Maintain a sorted array of numbers. 
 Each add operation would need O(log n) time to insert it at the correct position using a modified binary search (See Question [48. Search Insert Position]). 
 For find operation we could then apply the [Two pointers] approach in O(n) runtime.
 */

class TwoSum {
public:
    unordered_map<int,int> mp; // key:number; value:count of number
    void add(int number) {
        if(mp.find(number) == mp.end()){
            mp[number] = 1;
        }else{
            mp[number]++;
        }
    }

    bool find(int value) {
        for(unordered_map<int,int>::iterator IT = mp.begin(); IT != mp.end(); ++IT){
            int first_val = IT->first;
            int gap = value - first_val;
            int first_val_count = IT->second;
            if(gap == first_val){
                // for duplicates, to make sure there are at least two elements
                if(first_val_count >= 2){
                    return true;
                }
            }else if(mp.find(gap) != mp.end()){
                return true;
            }
        }
        return false;
    }
};