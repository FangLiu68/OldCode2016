//
//  All Unique Chars.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/31/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Determine if the characters of a given string are all unique.

 Assumptions
 We are using ASCII charset, the value of valid characters are from 0 to 255
 The given string is not null
 Examples
 all the characters in "abA+\8" are unique
 "abA+\a88" contains duplicate characters
 */

#include "Header.h"

// O(N) time, O(1) space
bool isUnique_arr1(string s) {
    if(s.empty()) return false;
    if(s.size() > 256) return false;

    bool arr[256] = {false};
    for(int i=0; i<s.size(); i++){
        if(arr[s[i]]) return false;
        arr[s[i]] = true;
    }
    return true;
}


// 如果只有26个字母，那么只需要占用大小为26的数组即可。注意这里的写法 arr[s[i] - 'a']
// O(N) time, O(1) space
bool isUnique_arrII(string s){
    if(s.empty()) return false;
    if(s.size() > 26) return false;
    
    bool arr[26] = {false};
    for(int i=0; i<s.size(); i++){
        if(arr[s[i] - 'a']) return false;
        arr[s[i] - 'a'] = true;
    }
    return true;
}

// O(N) runtime, O(N) space
bool isUnique_set(string input){
    if(input.empty()) return false;
    unordered_set<char> st;
    for(int i=0; i<input.size(); ++i){
        if(st.find(input[i]) != st.end()){
            return false;
        }
        st.insert(input[i]);
    }
    return true;
}


// O(N^2) runtime, O(1) space
bool isUnique12(string input){
    if(input.empty()) return false;
    for(int i=0; i<input.size(); ++i){
        char cur = input[i];
        for(int j=i+1; j<input.size(); ++j){
            if(cur == input[j]){
                return false;
            }
        }
    }
    return true;
}

// abcde...xyz   26个
bool isUnique_bitI(string input) {
    int bits = 0;  // variable contains 32 bits available to use.
    for(int i = 0; i < input.length(); i++){
        int bit_to_set = input[i] - 'a';
        int tmp = 1 << (bit_to_set);
        if (bits && tmp > 0) {
            return false;
        }
        bits |= tmp;
    }
    return true;
}

bool isUnique_bitII(string input){
    if(input.size() <= 0 || input.size() > 256){
        return false;
    }
    int checker = 0;
    for(int i=0; i < input.size(); ++i){
        int val = input[i] - 'a';
        if((checker & (1 << val)) > 0){
            return false;
        }
        checker = checker | (1 << val);
    }
    return true;
}
/*
int main(){
    string input = "abc+/e";
    if(isUnique_bitII(input)){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }return 0;
}*/