//
//  Word Pattern.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/11/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a pattern and a string str, find if str follows the same pattern.
 
 Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
 
 Examples:
 pattern = "abba", str = "dog cat cat dog" should return true.
 pattern = "abba", str = "dog cat cat fish" should return false.
 pattern = "aaaa", str = "dog cat cat dog" should return false.
 pattern = "abba", str = "dog dog dog dog" should return false.
 Notes:
 You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
 */

#include "Header.h"

bool wordPattern(string pattern, string str) {
    if(pattern.empty() || str.empty()) return false;
    
    vector<string> tokens;
    stringstream ss(str); // insert the string into a stream
    string buffer; // have a buffer string
    // The stringstream will use the output operator (>>) and put a string into buf everytime a whitespace is met, buf is then used to push_back() into the vector
    while(ss >> buffer){
        tokens.push_back(buffer);
    }
    
    if(pattern.size() != tokens.size()) return false;
    
    map<char, string> mp1;
    map<string, char> mp2;
    for(int i=0; i<pattern.size(); ++i){
        if(mp1.find(pattern[i]) != mp1.end()){
            if(mp1[pattern[i]] != tokens[i]) return false;
        }
        if(mp2.find(tokens[i]) != mp2.end()){
            if(mp2[tokens[i]] != pattern[i]) return false;
        }
        mp1[pattern[i]] = tokens[i];
        mp2[tokens[i]] = pattern[i];
    }
    
    return true;
}