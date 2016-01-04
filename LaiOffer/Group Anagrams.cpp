//
//  anagrams.cpp
//  LeetCode
//
//  Created by Fang Liu on 5/2/14.
//  Copyright (c) 2014 Fang Liu. All rights reserved.
//

/* Given an array of strings, return all groups of strings that are anagrams. Note: All inputs will be in lower-case. */

#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

// time complexity O(N), space complexity O(N)
vector<string> anagrams(string arr[], int len){
    vector<string> result;
    map<string, vector<string>> mp;
    for(int i=0; i<len; i++){
        string copy = arr[i];
        sort(copy.begin(), copy.end());
        mp[copy].push_back(arr[i]);
    }
    for(map<string, vector<string>>::iterator IT = mp.begin(); IT != mp.end(); IT++){
        if(IT->second.size() > 1) // 不能少！！！
            for(int i=0; i<(IT->second).size(); i++)
                result.push_back((IT->second)[i]);
    }
    return result;
}
/*
 int main(){
 string arr[] = {"abc", "a", "acb", " ", "cd", "e", "dc", "cab"};
 vector<string> result = anagrams(arr, 8);
 for(int i=0; i<8; i++)  cout << result[i] << " ";
 cout << endl;
 return 0;
 }
 */