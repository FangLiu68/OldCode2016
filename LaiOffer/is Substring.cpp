//
//  is Substring.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/21/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Determine if a small string is a substring of another large string.
 Return the index of the first occurrence of the small string in the large string.
 Return -1 if the small string is not a substring of the large string.

 Assumptions
 Both large and small are not null
 If small is empty string, return 0
 Examples
 “ab” is a substring of “bcabc”, return 2
 “bcd” is not a substring of “bcabc”, return -1
 "" is substring of "abc", return 0
 */

#include "Header.h"

// 这个是自己写的  感觉比下面老师写的更简练一些
bool helper_match(string large, int index, string small);
int strStr(string haystack, string needle) {
    if(haystack.size() < needle.size()){
        return -1;
    }
    int index = 0;
    
    // index这里是从haystack的哪个位置开始比较needle
    // "abc" "c"，则终止位置是index==2 (which is 'c')
    while(index <= haystack.size()-needle.size()){ // 注意是<=
        if(helper_match(haystack, index, needle)){
            return index;
        }else{
            index++;
        }
    }
    return -1;
}

bool helper_match(string haystack, int index, string needle){
    for(int i=0; i<needle.size(); ++i){
        if(haystack[index++] != needle[i]){
            return false;
        }
    }
    return true;
}
//================================
// return the first match index of the large string. if not found, return -1
bool match(string large, int cur, string small){
    for(int i=0; i<small.size(); i++)
        if(large[cur+i] != small[i])
            return false;
    return true;
}

// check if the subarray starting from index start of the large array
int strStr1(string large, string small){
    if(small.empty()) return 0;
    int largeLen = large.size();
    int smallLen = small.size();
    if(smallLen > largeLen) return -1;
    for(int i=0; i<=largeLen-smallLen; i++){
        if(match(large, i, small))
            return i;
    }
    return -1;
}

//==================================================================
bool match_c(char* large, int index, char* small){
    if(small == NULL) return true;
    if(strlen(large) < strlen(small)) return false;
    for(int i=0; small[i]!='\0'; i++){
        if(large[i+index] != small[i])
            return false;
    }
    return true;
}

int strStr(char* large, char* small){
    if(small == NULL) return 0;
    int smallLen = strlen(small);
    int largeLen = strlen(large);
    if(smallLen > largeLen) return -1;
    for(int i=0; i<=largeLen-smallLen; i++){
        if(match_c(large, i, small))
            return i;
    }
    return -1;
}
/*
int main(){
    char large[] = "abcdehcdf";
    char small[] = "eh";
    int res = strStr(large, small);
    cout << res;
    cout << endl;
    return 0;
}
*/
