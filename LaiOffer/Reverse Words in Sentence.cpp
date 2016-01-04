//
//  Reverse Words in String.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/20/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Reverse the words in a sentence.

 Assumptions
 Words are separated by single space
 There are no heading or tailing white spaces
 Examples
 “I love Google” → “Google love I”
 Corner Cases
 If the given string is null, we do not need to do anything.
 */

#include <string>
#include <iostream>
using namespace std;

/*
 Step1: swap the whole sentence       oohay evol I
 Step2: swap every single word        yahoo love I
 */
void helper_reverse(string &s, int left, int right){
    while(left <= right){
        char tmp = s[left];
        s[left++] = s[right];
        s[right--] = tmp;
    }
}

string reverse_word_in_string(string s) {
    if(s.empty()) return "";

    // reverse the whole sentence
    helper_reverse(s, 0, s.size()-1);
    int start = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' '){
            helper_reverse(s, start, i-1); // reverse each of the words
            start = i+1;
        }
    }
    if(s[s.size()-1] != ' ') // reverse last word
        helper_reverse(s, start, s.size()-1);
    return s;
}


//====================================================
// 如果每个单词之间有连续空格
// time complexity O(N), space complexity O(N)
void reverseWords(string& input){
    if(input.empty()){
        return;
    }
    helper_reverse(input, 0, input.size()-1);
    string res;
    for(int i=0; i < input.size(); ++i){
        while(input[i] == ' '){ // 除去string开始的空格
            i++;
        }
        if(i == input.size()){
            break; // 不可少
        }
        if(!res.empty()){
            res.push_back(' '); // 每次扫描完一个单词，就在res后面添加空格
        }
        string temp; // 存储遇到的单词，并reverse
        while(i<input.size() && input[i]!=' '){
            temp.push_back(input[i]);
            i++;
        }
        helper_reverse(temp, 0, temp.size()-1);
        res.append(temp); // 添加reverse后的单词到res
    }
    input = res;
}

/*
int main(){
    string input = "I love Google";
    string input2 = "hi!";
     reverse_word_in_string(input2);
    //reverseWords(input);

    //cout << input2 << "END" << endl;

    string input3 = "   how    are      you   ";
    reverseWords(input3);
    cout << "N" << input3 << "N" << endl;
    return 0;
}*/