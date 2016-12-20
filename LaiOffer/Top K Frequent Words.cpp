//
//  Top K Frequent Words.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/20/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

/*
 Given a composition with different kinds of words, return a list of the top K most frequent words in the composition.

 Assumptions
 the composition is not null and is not guaranteed to be sorted
 K >= 1 and K could be larger than the number of distinct words in the composition, in this case, just return all the distinct words
 Return
 a list of words ordered from most frequent one to least frequent one (the list could be of size K or smaller than K)
 Examples

 Composition = ["a", "a", "b", "b", "b", "b", "c", "c", "c", "d"], top 2 frequent words are [“b”, “c”]
 Composition = ["a", "a", "b", "b", "b", "b", "c", "c", "c", "d"], top 4 frequent words are [“b”, “c”, "a", "d"]
 Composition = ["a", "a", "b", "b", "b", "b", "c", "c", "c", "d"], top 5 frequent words are [“b”, “c”, "a", "d"]
 Composition = ["a", "a", "b", "b", "b", "b", "c", "c", "c", "d"], top 0 frequent words are []
 */
struct comp{
    bool operator()(pair<string, int> p1, pair<string, int> p2){
        return p1.second > p2.second; // min heap
    }
};

vector<string> top_k_frequent_words(vector<string> input, int k){
    vector<string> res;
    if(input.empty()) return res;
    if(k>input.size()) return input;

    // a map store each word and its occurrence count
    unordered_map<string, int> mp;
    // go through the entire array and count each word
    for(int i=0; i<input.size(); i++){
        if(mp.find(input[i]) == mp.end())
            mp[input[i]] = 1;
        else
            mp[input[i]]++;
    }

    // min heap is needed for top k elements. each entry of the heap is pair<word, word_count>
    priority_queue<pair<string, int>, vector<pair<string, int>>, comp> pq;
    for(unordered_map<string, int>::iterator IT = mp.begin(); IT != mp.end(); IT++){
        pq.push(*IT);
        if(pq.size() > k){ // only maintain k elements
            pq.pop();
        }
    }

    /* 更清楚是下面这样写
     for(unordered_map<string, int>::iterator IT = mp.begin(); IT != mp.end(); ++IT){
     if(minHeap.size() < k){
     minHeap.push(*IT);
     }else if(IT->second > minHeap.top().second){
     minHeap.pop();
     minHeap.push(*IT);
     }
     }
     */
    while(!pq.empty()){
        pair<string, int> cur = pq.top();
        res.push_back(cur.first);
        pq.pop();
    }
    return res;
}

struct comp1{
    bool operator()(pair<string, int> p1, pair<string, int> p2){
        return p1.second > p2.second; // min heap
    }
};

//========================================================
vector<string> solve(vector<string> input, int k){
    vector<string> res;
    if(input.empty()){
        return res;
    }

    // build map
    unordered_map<string, int> mp;
    for(int i=0; i<input.size(); ++i){
        if(mp.find(input[i]) == mp.end()){
            mp[input[i]] = 1;
        }else{
            mp[input[i]]++;
        }
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, comp> minHeap;
    for(unordered_map<string, int>::iterator IT = mp.begin(); IT != mp.end(); ++IT){
        if(minHeap.size() < k){
            minHeap.push(*IT);
        }else if(IT->second > minHeap.top().second){
            minHeap.pop();
            minHeap.push(*IT);
        }
    }

    while(!minHeap.empty()){
        res.push_back(minHeap.top().first);
        minHeap.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

/*
int main(){
    vector<string> input1(7);
    input1[0] = "a";
    input1[1] = "b";
    input1[2] = "a";
    input1[3] = "a";
    input1[4] = "b";
    input1[5] = "c";
    input1[6] = "c";
    vector<string> res = solve(input1, 2);
    for(int i=0; i<res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}*/