//
//  Is Permutation Strings.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/1/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Given two strings, decide if one is a permutation of the other.
/*
 Given two strings s and t, write a function to determine if t is an anagram of s.
 
 For example,
 s = "anagram", t = "nagaram", return true.
 s = "rat", t = "car", return false.
 
 Note:
 You may assume the string contains only lowercase alphabets.
 
 Follow up:
 What if the inputs contain unicode characters? How would you adapt your solution to such case?
 */

#include "Header.h"

// time O(n), space O(n)
bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;
    unordered_map<char, int> mp;
    for(int i=0; i<s.size(); ++i){
        if(mp.find(s[i]) == mp.end()){
            mp[s[i]] = 1;
        }else{
            mp[s[i]]++;
        }
    }
    
    for(int i=0; i<t.size(); ++i){
        if(mp.find(t[i]) == mp.end()) return false;
        mp[t[i]]--;
        if(mp[t[i]] < 0) return false;
    }
    
    return true;
}

// time O(n), space O(1)
bool isAnagram1(string s, string t) {
    if(s.size() != t.size()) return false;
    vector<int> mp(256, 0);
    for(int i=0; i<s.size(); ++i){
        mp[s[i]]++;
    }
    for(int i=0; i<t.size(); ++i){
        mp[t[i]]--;
        if(mp[t[i]] < 0) return false;
    }
    return true;
}


// assume all chars are ASCII
// runtime O(2N)
bool permutationStr(string str1, string str2){
    if(str1.size() != str2.size()){
        return false;
    }
    int count[256];
    for(int i=0; i<256; ++i){
        count[i] = 0;
    }
    for(int i=0; i<str1.size(); ++i){
        count[str1[i]]++;
    }
    for(int i=0; i<str2.size(); ++i){
        count[str2[i]]--;
        if(count[str2[i]] < 0){
            return false;
        }
    }
    return true;
}



// O(NlogN) runtime
bool isPermutationStr(string str1, string str2){
    if(str1.size() != str2.size()){
        return false;
    }
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return (str1 == str2);
}