//
//  word play.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/30/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 wordPlay:
 (“act”, “cat”)->true; 
 (“bacus”, “abacus”)->false; 
 (“aaaabacus”, “abacus”)->true; 
 (“block”, “book”)->false
 让判断两个词的关系
 */

#include "Header.h"

/*
int cc(string s, char c);
bool wordPlay(string str1, string str2){
    if(str2.empty()){
        return true;
    }
    if(str1.empty()){
        return false;
    }
    for(int i=0; i<str2.size(); ++i){
        if(cc())
    }
}*/

int cc(char* s, char c){
    int count = 0;
    while(*s){
        if(*s == c){
            count++;
        }
        s++;
    }
    return count;
}

bool wordplay(char* letter, char* word){
    if(word==NULL) return true;
    if(letter==NULL) return false;
    char* start = word;
    while(*word){
        if(cc(start, *word) > cc(letter, *word)){
            return false;
        }
        word++;
    }
    return true;
}
/*
int main(){
    char* letter = "aaaabacus";
    char* word = "abacus";
    if(wordplay(letter, word)){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }
    cout << sizeof(word) << endl;
    return 0;
}*/