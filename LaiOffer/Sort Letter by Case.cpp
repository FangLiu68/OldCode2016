//
//  Sort Letter by Case.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/17/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Sort Letters by Case
 Given a string which contains only letters. Sort it by lower case first and upper case second.
 Example, “aBcDe” → “aceBD”.
 */

#include "Header.h"

// O(N) runtime
string sortByCase(string input){
    if(input.empty()) return " ";
    int slow = 0;
    int fast = input.size()-1;
    while(slow <= fast){
        if(input[slow]>='a' && input[slow]<='z'){
            slow++;
        }else{
            swap(input[slow], input[fast--]);
        }
    }
    return input;
}
/*
int main(){
    string input = "aBcDe";
    cout << sortByCase(input) << endl;
    return 0;
}*/