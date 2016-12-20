//
//  longest_substr_without_repeating_char.cpp
//  LeetCode
//
//  Created by Fang Liu on 8/7/14.
//  Copyright (c) 2014 Fang Liu. All rights reserved.
//

/*
 Given a string, find the length of the longest substring without repeating characters.
 For example, the longest substirng without repeating letters for "abcabcbb" is "abc", which the length is 3
 For "bbbb" the longest substring is "b", with the length of 1.
 */

#include "Header.h"

/*
 slow, fast all start from index 0
 [slow, fast) contain all the distinct chars
 use a container to hold all unrepeated chars
 and use one counter to keep track the max length between (fast-slow)
 
 when fast find un-repeated char, we push to set, and fast++
 when fast find repeated char, we pop input[slow] out of the container, at the meantime slow++, we keep doing this until slow move to the repeated char(which fast is pointing to)'s next char
 */
int longest_substr_no_repeated_charI(string input){
    if(input.size() <= 1){
        return input.size();
    }
    
    int slow = 0;
    int fast = 0;
    set<char> no_dup;
    int res = 0;
    
    while(fast < input.size()){
        if(no_dup.find(input[fast]) == no_dup.end()){ // input[fast] is not in the set
            no_dup.insert(input[fast++]);
            res = max(res, fast-slow); // 此时right已经+1，所以长度正好是所需要结果
        }else{
            no_dup.erase(input[slow++]);
        }
    }
    return res;
}


string longest_substr_no_repeated_char(string input){
    if(input.size() <= 1){
        return input;
    }
    string res;
    set<char> s;
    int left = 0;
    int right = 0;
    while(right < input.size()){
        if(s.find(input[right]) != s.end()){
            s.erase(input[left++]);
        }else{
            s.insert(input[right++]);
            if(right - left > res.size()){
                res = input.substr(left, right - left);
            }
        }
    }
    return res;
}

//=============================================
/*
 Set two pointers, i,j, scan the string from the start to the end. Set a table to store if the character has occurred.
 If s[j] has occurred in S[i..j-1],  compute current length and compare to the max length.
 Then table[s[i]]=false; i++;

 If s[j] has not occurred in S[i..j-1],
 table[s[j]]=true; j++;
 假设字串里含有重复字符，则父串里一定含有重复字符，单个子问题就可以解决父问题，因此可以用贪心算法。
 跟动态规划不同，DP里单个子问题只能影响父问题，不足以解决父问题
 time complexity O(N), space complexity O(N)
 */
int lengthOfLongestSubstring(string s) {
    if(s.size()==0){return 0;}
    if(s.size()==1){return 1;}
    int start=0;
    int end=0;
    int maxl = 0;
    unordered_map<char,bool> table;
    for(int i=0; i<s.size(); i++)   table[i]=false;
    // 保证i j之间的char都是distinct的
    // 只要char没出现，就一直+j，i不动，同时更新maxlen
    // 发现一个char出现过，立刻置为false, i+1开始重新计算长度
    while (end<s.size()){
        if (table[s[end]]==false){
            table[s[end]]=true;
            maxl = max(maxl,end-start+1);
            end++;
        }
        // 当发现重复字符（table[s[j]]==ture），就让j在重复字符的位置上不动，一直加i，直到i增加到重复字符第一次出现的位置之后一位，然后这个位置就是i的新的起始位置，此时j再继续前进，直到发现下一个重复字符。在此过程中不断更新最大距离，从（上一次记录的最大距离）和（这一次i,j之间距离）中最大值
        else if (table[s[end]]==true){ // 此时s[i]和s[j]相同，这个char已被标志为true，我们就一直加i，直到找到这个char上一次出现的时候，然后将它更新为false，i定位到它后面的一个位置，然后j继续
            table[s[start]]=false; // 这里不能换成table[s[end]]=false 不知道为什么
            maxl = max(maxl,end-start);
            start++;
        }
    }
    return maxl;
}


/*
 Given a string, returns the length of the longest substring without duplicate characters.
 For example,the longest substrings without repeating characters for “BDEFGADEF” are “BDEFGA”, whose size is 6.
 01 2345678
 BD EFGADEF
 Solution:
 slow index + fast index + hash_table (or a char vector).
 Main Idea:
	1. Always keep one copy of every char in the sub-section [slow, fast], when detecting there are duplicated letters between slow and fast index (when we are scanning A[fast]), keep moving slow until the invariant holds again.
 Hash_table contains all chars and its occurrences numbers between [Slow, Fast]
 */
string FindLongest(string input){
    if(input.empty()){
        return "";
    }
    unordered_map<char, int> mp;
    int s = 0;
    int max = 0;
    int start = 0, end = 0;
    for(int f = 0; f < input.size(); ++f){
        mp[input[f]]++;
        if(mp[input[f]] > 1){ // if has dup after ++f
            while(mp[input[f]] > 1){
                mp[input[s]]--;
                s++;
            }
        }else{ // if moving f doesn't cause duplication
            if(f - s + 1 > max){
                max = f - s + 1;
                start = s;
                end = f;
            }
        }
    }
    return input.substr(start, end - start + 1);
}

