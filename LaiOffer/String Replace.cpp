//
//  String Replace.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/6/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 String Replace
 HardString
 Given an original string input, and two strings S and T, replace all occurrences of S in input with T.

 Assumptions

 input, S and T are not null, S is not empty string
 Examples

 input = "appledogapple", S = "apple", T = "cat", input becomes "catdogcat"
 input = "dodododo", S = "dod", T = "a", input becomes "aoao"
 */

/*
 what if we don't know the size relationship btw s1 and s2?
 compare the lengths of s1 and s2:
 (1) if s1.size() < s2.size(), then replace from the right hand side to the left hand side. 和CC150原题一样
 (2) if s1.size() > s2.size(), then replace from the left hand side to the right hand side.因为结果比原string短，必须从头开始replace

 s1.size == m
 s2.size == k
 s.size == n
 use a strstr() helper function to identify the occurrence of s1 in the string s.
 
 下面这点没太懂，WHY？？？？？？？？？
 Time complexity: O(mn)
 assume that there are x times s1 in s;
 calculate the size change in s1:  == x *|m-k|

 */

#include "Header.h"

string replace(string input, string s, string t) {
    string res;
    int index = (int)input.find(s);
    while(index != -1){
        res = res + (input.substr(0, index));
        res = res + t;
        input = input.substr(index + s.size());
        index = (int)(input.find(s));
    }
    res = res + input;
    return res;
}


/*
string replaceShorter(string input, string s, string t);
string replaceLonger(string input, string s, string t);
bool equalSubstr(string input, int index, string s);
void copyFromLeft(string& input, int index, string t);
void copyFromRight(string& input, int index, string t);

string string_replace(string input, string s, string t){
    assert(!input.empty() && !s.empty() && !t.empty());
    if(s.size() > t.size()){
        return replaceShorter(input, s, t);
    }else{
        return replaceLonger(input, s, t);
    }
}

string replaceShorter(string input, string s, string t){
    assert(!input.empty() && !s.empty() && !t.empty());
    int end = 0;
    int cur = 0;
    while(cur < input.size()){
        if(cur<=input.size()-s.size() && equalSubstr(input, cur, s)){
            copyFromLeft(input, end, t);
            cur = cur + s.size();
            end = end + t.size();
        }else{
            input[end++] = input[cur++];
        }
    }
    return input.substr(0, end);
}

 需要改  没改完
string replaceLonger(string input, string s, string t){
    assert(!input.empty() && !s.empty() && !t.empty());
    //int diff = t.size() - s.size();
    int count = 0;
    int cur = 0;
    while(cur < input.size()){
        if(equalSubstr(input, cur, s)){
            count++;
        }
        cur = cur+s.size();
    }
    int newLen = input.size() + count*(t.size()-s.size());
    //input.resize(newLen);
    int lastIndex = newLen-1;
    int end =
}


// 检查在input中从index开始是否有substring和s相同
bool equalSubstr(string input, int index, string s){
    for(int i=0; i<s.size(); ++i){
        if(input[index+i] != s[i]){
            return false;
        }
    }
    return true;
}

// copy t to input both from left to right
void copyFromLeft(string& input, int index, string t){
    for(int i=0; i<t.size(); ++i){
        input[index++] = t[i];
    }
}

// copy t to input both from right to left
void copyFromRight(string& input, int index, string t){
    for(int i=t.size()-1; i>=0; --i){
        input[index--] = t[i];
    }
}

*/



/*
bool str_match_leftToRight(string& large, int cur, string small);
string replace_shorter(string& input, string s, string t);
string replace_longer(string& input, string s, string t);
string str_replace(string input, string s, string t){
    if(input.empty()){
        return "";
    }
    if(s.empty() || t.empty()){
        return input;
    }
    
    if(s.size() >= t.size()){
        return replace_shorter(input, s, t);
    }else{
        return replace_longer(input, s, t);
    }
    //return replace_shorter(input, s, t);
}

bool str_match_leftToRight(string& large, int cur, string small){
    assert(!large.empty() && !small.empty());
    for(int i=0; i<small.size(); ++i){
        if(large[cur++] != small[i]){
            return false;
        }
    }
    return true;
}

bool str_match_rightToLeft(string& large, int cur, string small){
   // assert(!large.empty() && !small.empty());
    for(int i=small.size()-1; i>=0; --i){
        if(large[cur--] != small[i]){
            return false;
        }
    }
    return true;
}

// s->t, s.size() > t.size()
string replace_shorter(string& input, string s, string t){
    assert(!input.empty() && !s.empty() && !t.empty());
    int index = 0;
    int count = 0;
    for(int i=0; i<input.size();){
        if(str_match_leftToRight(input, i, s)){
            for(int j=0; j<t.size(); ++j){
                input[index++] = t[j++];
            }
            i = i+s.size();
            count++;
        }else{
            input[index++] = input[i++];
        }
    }
    count = input.size() - count*(s.size() - t.size());
    return input.substr(0, count);
}

string replace_longer(string& input, string s, string t){
    assert(!input.empty() && !s.empty() && !t.empty());
    int count = 0;
    for(int i=input.size()-1; i>=0;){
        if(str_match_rightToLeft(input, i, s)){
            count++;
            i = i-s.size();
        }else{
            i--;
        }
    }
    count = input.size() - count*(s.size() - t.size());
    int runner = input.size()-1;
    input.resize(count);
    int index = count-1;
    for(int i=runner; i>=0;){
        if(str_match_rightToLeft(input, i, s)){
            for(int j=t.size()-1; j>=0; --j){
                input[index--] = t[j--];
            }
            i = i - s.size()+1;
        }else{
            input[index--] = input[i--];
        }
    }
    return input;
}

int main(){
    string input = "hd";
    string s = "h";
    string t = "abc";
    string res = str_replace(input, s, t);
    cout << res << endl;
    return 0;
}*/