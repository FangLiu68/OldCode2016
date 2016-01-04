//
//  longest_common_prefix.cpp
//  LeetCode
//
//  Created by Fang Liu on 5/2/14.
//  Copyright (c) 2014 Fang Liu. All rights reserved.
//

// Write a function to find the longest common prefix string amongst an array of strings.

#include <string>
#include <vector>
using namespace std;

/*
 纵向扫描
 固定第一个string，index i从strs[0][0]开始横向往后iterate
 从第二个string开始和strs[0]比较，纵向扫描直到最后一个string与strs[0]比较完毕
 纵向扫描过程中，一旦出现不相同字符，返回strs[0]的substr
 或者当前string的长度小于strs[0]的长度，而且当前string的所有字符都是strs[0]的前缀，则也返回strs[0]的substr
 */
// time complexity O(n1+n2+...), space complexity O(1)
string longestCommonPrefix1(vector<string> &strs) {
    if(strs.empty()) return "";
    for(int i=0; i<strs[0].size(); i++){ // i是横向在走
        for(int j=1; j<strs.size(); j++) // j是纵向在比较和第一行
            // substr里第一个值为string里起始index，第二个值为需要截取的长度.注意这里i不需要再-1
            if(i==strs[j].size() || strs[j][i]!=strs[0][i])
                return strs[0].substr(0,i); // 这里返回strs[j].substr(0,i)也一样
    }
    return strs[0];
}

// 横向扫描。每个字符串与第0个字符串，从左到右比较，直到遇到一个不匹配。
// 然后下一个字符串
// time complexity O(n1+n2+...)
string longestCommonPrefix(vector<string> &strs) {
    if(strs.empty()) return "";
    string res = strs[0];
    int right_most = res.size()-1;
    for(int i=1; i<strs.size(); i++){
        for(int j=0; j<=strs[i].size()-1; j++)
            if(strs[0][j] != strs[i][j])
                right_most = j-1;
    }
    return strs[0].substr(0, right_most+1);
}

string longestCommonPrefix_onlinePass(vector<string> &strs) {
    if(strs.empty()) return "";
    string result = strs[0]; // 结果先设置成第一个stirng，然后再裁剪
    int len = result.size();
    for(int i=1; i<strs.size(); i++){ // i=1,从vector里面的第二个string开始比较
        int j=0;
        while(j<len && j<strs[i].size() && strs[i-1][j]==strs[i][j])
            j++;
        len = j;
    }
    return result.substr(0,len); // len是substr里面包含的元素个数
}

