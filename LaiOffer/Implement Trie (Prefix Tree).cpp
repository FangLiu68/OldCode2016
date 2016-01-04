//
//  Implement Trie (Prefix Tree).cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/19/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Implement a trie with insert, search, and startsWith methods.

 Note:
 You may assume that all inputs are consist of lowercase letters a-z.
 */

#include <iostream>
using namespace std;

/*
 参考下面链接
 http://blog.csdn.net/beiyetengqing/article/details/7856113 
 http://blog.csdn.net/lisonglisonglisong/article/details/45584721
 */

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode(char c) {
        isEnd = false;
        count = 0;
        content = c;
        for(int i=0; i<26; ++i){
            children[i] = NULL;
        }
    }
    bool isEnd; // whether the end of the words
    int count; // the number of words sharing this char
    char content; // the char in the node
    TrieNode* children[26]; // the children list
};

class Trie {
public:
    Trie() {
        root = new TrieNode(' ');
    }

    // Inserts a word into the trie.
    void insert(string s) {
        if(search(s) == true){
            return;
        }
        TrieNode* p = root;
        for(int i=0; i<s.size(); ++i){
            int idx = s[i] - 'a';
            if(p->children[idx] == NULL){
                p->children[idx] = new TrieNode(s[i]);
            }
            p = p->children[idx];
        }
        p->count++;
        p->isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode* p = root;
        for(int i=0; i<key.size(); ++i){
            int idx = key[i] - 'a';
            if(p->children[idx]){
                p = p->children[idx];
            }else{
                return false;
            }
        }
        /*
         * This means that a string exists, but make sure its
         * a word by checking its 'isEnd' flag
         */
        if(p->isEnd){
            return true;
        }else{
            return false;
        }
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(int i=0; i<prefix.size(); ++i){
            int idx = prefix[i] - 'a';
            if(p->children[idx]){
                p = p->children[idx];
            }else{
                return false;
            }
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

