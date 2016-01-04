//
//  Compare_Version_Numbers.cpp
//  LeetCode
//
//  Created by Fang Liu on 12/17/14.
//  Copyright (c) 2014 Fang Liu. All rights reserved.
//

/*
 Compare two version numbers version1 and version1.
 If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

 You may assume that the version strings are non-empty and contain only digits and the . character.
 The . character does not represent a decimal point and is used to separate number sequences.
 For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

 Here is an example of version numbers ordering:
 0.1 < 1.1 < 1.2 < 13.37
 */

#include <string>
using namespace std;

/*
 以version1=10.6.5, version2=10.6为例
 以每个点为界限，两个version同时从string index为零开始，分别得到每一层的值，然后进行对比。
 对比后若产生当前层的大小关系，直接返回结果。
 若同一层的值相同，则进行下一层的比较。
 */

// O(n) runtime, O(1) space
int compareVersion(string version1, string version2) {
    int index1 = 0;
    int index2 = 0;
    while(index1 < version1.size() || index2 < version2.size()){
        int curSum1 = 0;
        int curSum2 = 0;
        while(index1 < version1.size() && version1[index1] != '.'){
            curSum1 = curSum1 * 10 + version1[index1]-'0';
            index1++;
        }
        index1++;

        while(index2 < version2.size() && version2[index2] != '.'){
            curSum2 = curSum2*10 + version2[index2]-'0';
            index2++;
        }
        index2++;
        
        if(curSum1 > curSum2){
            return 1;
        }else if(curSum1 < curSum2){
            return -1;
        }else{
            continue;
        }
    }
    return 0;
}