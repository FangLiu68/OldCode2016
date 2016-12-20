//
//  isomorphic_str.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given two words, determine if they are isomorphic. 
 Two words are isomorphic if the letters in one word can be remapped to get the second word.
 Remapping a letter means replacing all  occurrences of it with another letter while the ordering of the letters  remains unchanged. No two letters may map to the same letter, but a letter may map to itself.

 * Example:
 *   given "foo", "app"; returns true
 * 	we can map 'f' -> 'a' and 'o' -> 'p'
 *
 *   given "foo", "boa"; returns false
 * 	we can map 'f' -> 'b', 'o' -> 'o', we can't map 'o' -> 'a'
 *
 *   given "bar", "foo"; returns false
 * 	we can't map both 'a' and 'r' to 'o'
 *
 *   given "turtle", "tletur"; returns true
 * 	we can map 't' -> 't', 'u' -> 'l', 'r' -> 'e', 'l' -> 'u', 'e' ->'r'
 *
 *   given "ab", "ca"; returns true
 * 	we can map 'a' -> 'c', 'b' -> 'a'
 */

#include "Header.h"

bool isIsomorphic(string s, string t) {
    if(s.size() != t.size()){
        return false;
    }
    map<char, char> mp1;
    map<char, char> mp2; // 要用两个Map, 否则若是"aa"-"ab"
    
    for(int i=0; i<s.size(); ++i){
        char c1 = s[i];
        char c2 = t[i];
        if(mp1.find(c1) != mp1.end()){
            if(mp1[c1] != c2) return false;
        }
        if(mp2.find(c2) != mp2.end()){
            if(mp2[c2] != c1) return false;
        }
        mp1[c1] = c2;
        mp2[c2] = c1;
    }
    return true;
}
