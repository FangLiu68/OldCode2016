//
//  Str to Hex Int.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Given a number x, how to get the hexadecimal representation of the number in string type?
// eg, 29 => 0x1D = 1*16+13 = 29

#include <iostream>
#include <string>
using namespace std;

/*
                                16 +    13
 10 进制 => 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
 16 进制 => 0 1 2 3 4 5 6 7 8 9  A  B  C  D  E  F
 */


string arr_map[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

string toHex(int num){
    string res;
    while(num != 0){
        int digit = num % 16;
        string _char = arr_map[digit];
        res = _char + res;
        num = num/16;
    }
    return "0x" + res;
}