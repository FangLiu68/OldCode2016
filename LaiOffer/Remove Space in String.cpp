//
//  Remove Space in String.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/24/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Remove all leading/trailing and duplicate empty spaces from the input string.

 input   = “    abc      ed    ef    ”;
 output = “abc ed ef”;
 */

#include <string>
#include <iostream>
using namespace std;

/*
 Main idea:  两个挡板： slow/fast
 slow: all letters to the left-hand side of left (not including slow) is the final solution.
 fast: current/fast index to scan the string.

 For each word in the original string
 skipping all leading/duplicate empty space
 Add only one empty space in front of each word. (except for the 1st word in the sentence).
 */

void RemoveSpaces(string& s){
    if(s.empty()){
        return;
    }
    int slow = 0;
    int fast = 0;
    bool add_blank = false; // 当一部分连续非空单词copy完全之后，flag设置为true。注意第一个单词copy时flag仍旧为false
    while(fast < s.size()){
        while(fast < s.size() && s[fast] == ' '){
            fast++; // 1: skip all leading ‘ ’ in front of each word
        }
        if(fast == s.size()){
            break;
        }
        if(add_blank){
            s[slow++] = ' '; // 2: add ‘ ’ in front of (2nd+) word
        }
        while(fast < s.size() && s[fast] != ' '){
            s[slow++] = s[fast++]; // copy a word
        }
        add_blank = true;
    }
    s.resize(slow);
}

string removeSpaceI(string input){
    if(input.empty()){
        return input;
    }
    int end = 0;
    for(int i=0; i<input.size(); ++i){
        if(input[i] == ' ' && (i == 0 || input[i-1] == ' ')){
            continue;
        }
        input[end++] = input[i];
    }
    // 每个单词结束后，后面都会添加一个空格。所以最后一个单词后面也有一个空格，此时end的位置在那个空格位置的后面
    // 所以substr的结束的位置应该是空格之前，即长度为end-1
    if(end > 0 && input[end-1] == ' '){
        return input.substr(0, end-1);
    }
    return input.substr(0, end);
}


//==========================================
// 和上面的方法一样
void RemoveSpacesI(string &s) {
    if(s.empty()) return;
    int slow = 0;
    int fast = 0;
    int word_count = 0; // special case for the 1st word.
    while (1) {
        while(fast < s.size() && s[fast] == ' ') {
            fast++;
        }
        if (fast == s.size()) {
            break;
        }
        if (word_count > 0) {
            s[slow++] = ' ';
        }
        while(fast < s.size() && s[fast] != ' ') {
            s[slow++] = s[fast++];
        }
        word_count++;
    }
    s.resize(slow);
}

/*
int main(){
    string s = "      ";
    string res = removeSpaceI(s);
    cout << res << "END" << endl;
    return 0;
}
*/