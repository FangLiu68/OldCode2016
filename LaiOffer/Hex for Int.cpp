//
//  Hex for Int.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/8/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a number x, how to get the hexadecimal representation of the number in string type?  
 E.g  29   ⇒   “0x 1D”
 1*16^1 +   13* 16^0
 = 16 + 13 = 29

 16 +13
 10 进制=> 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
 16 进制=> 0 1 2 3 4 5 6 7 8 9  A  B  C  D  E  F
 */

#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
string hex(int num){
    if(num == 0){
        return "";
    }
    map<int, char> mp;
    for()
}*/