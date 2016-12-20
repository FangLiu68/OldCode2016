//
//  String Matching.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/3/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 A word such as “book” can be abbreviated to 4, 1o1k, b3, b2k, etc. Given a string and an abbreviation, return if the string matches the abbreviation.  Assume the original string only contains alphabetic characters. For example:  “s11d” matches “sophisticated”.
 */

#include "Header.h"

/*
 Abbreviation matching
 // s1: student     original string
 // s2: s2d2t        pattern
 
 NOTE:
 input.substr(num) return the sub-string of input from index num to the end of input
 if(num == input.size()) return empty string
 if(num > input.size()) false alarm
 eg. input = "abcde"
     input.substr(0) = "abcde"; input.substr(2) = "cde"; input.substr(4) = "e"; input.substr(5) = ""; 
     input.substr(6) false alarm
 */

bool isDigit(char input) {
    return  input >= '0' && input <= '9';
}

bool AbbrevMatch(string s1, string s2) {
    // base case
    if (s1.size() == 0 && s2.size() == 0) {
        return true;
    } else if (s1.size() == 0 || s2.size() == 0) {
        return false;
    }

    // s1: student     original string
    // s2: s2d2t        pattern
    // Case1: s2.at(0) is a digit
    if (isDigit(s2[0])) {
        int i = 0;
        int num = 0;
        while (i < s2.size() && isDigit(s2[i])) {
            num = num*10 + s2[i] - '0';
            i++;
        }
        if (num > s1.size()) {
            return false;
        } else { // when num<=s1.size()
            return AbbrevMatch(s1.substr(num), s2.substr(i));
        }
    }

    // Case2: s2.at(0) is not a digit
    else {
        if (s1[0] != s2[0]) {
            return false;
        } else {
            return AbbrevMatch(s1.substr(1), s2.substr(1));
        }
    }
}

/*
int main(){
    string s1 = "student";
    string s2 = "st1d3";
    if(AbbrevMatch(s1, s2)){
        cout << "match" << endl;
    }else{
        cout << "not match" << endl;
    }
    return 0;
}*/