//
//  First Non-Repeating Char in Stream.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/17/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Given a stream of characters, find the first non-repeating cahracter from the stream. You need to tell the first non-repeating character in O(1) time at any moment.

#include <list>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

/*
  Given a stream of characters, find the first non-repeating character from stream. You need to tell the first non-repeating character in O(1) time at any moment.
 Example:   a    b    c   a   c  d    b
 solution   a    a    a   b   b  b    d
 Data structure:
	1. doubly linked list : stream of char
	2. hash_map: <key=char; value: reference of the node in the doubly linkedlist>;
	3. counter: occurrence of the char in the stream
 when a new char ‘x’ comes in
 case1:   occurrence of x < 1; insert into dblinkedlist,   update counter;
 case 2:  >= 1: update counter; (== 2)remove from dblinkedlist;
 (>2)do nothing
 class Node {
 Node pre, next;
 char c;
 Node (char c) {
 this.c = c;
	}
 }
 class LRU {
 HashMap<Charracter, Node> map = new HashMap<Character, Node>();
 Node head, tail;
 int[] cnt;
 public LRU() {
 head = null;
 tail = null;
 cnt = new int[256];
	}
	char nonrepeat(char[] s) {
	for (char x : s) {
	cnt[x] += 1;
	if (cnt[x] == 1) {
	insert(x);
 } else if (cnt[x] == 2) {
 remove(x);
 }
 }
 if (tail != null) {
 return tail.c;
 } else {
 return null;
 }
	}
	void insert(char x) {
	Node curr = new Node(x);
	map.put(x, curr);
	curr.next = head;
	if (head != null) {
	head.pre = curr;
 }
 head = curr;
 if(tail == null) {
 tail = curr;
 }
	}
	void remove(char x) {
	Node curr = map.get(x);
	Node prev = curr. pre;
	Node post = curr.next;
	if (prev != null) {
	prev.next = post;
 } else {
 head = post;
 head.prev = null;
 }
 if (post != null) {
 post.pre = prev;
 } else {
 tail = prev;
 tail.next = null;
 }
	}
 }
 */

/*
class FirstNonRepeatingChar{
private:
    struct Node{
        char ch;
        Node(char _ch) : ch(_ch){}
    };
    list<Node> nonRepeated_list;
    unordered_map<char, list<Node>::iterator> nonRepeated_map;
    unordered_set<char> repeated;
public:
    void read(char ch){
        if(repeated.find(ch) != repeated.end())
            return; // 之前读过

        if(nonRepeated_map.find(ch) != nonRepeated_map.end()){
            list<Node>::iterator to_be_remove_entry = nonRepeated_map[ch];
            nonRepeated_list.erase(to_be_remove_entry);
            nonRepeated_map.erase(ch);
            repeated.insert(ch);
        }
        else{
            Node newEntry(ch);
            nonRepeated_list.push_back(newEntry);
            pair<char, list<Node>::iterator> insert(ch, nonRepeated_list.back());
            nonRepeated_map[ch] = *nonRepeated_list.back();
        }
    }

    char firstNonRepeating(){
        if
    }
};*/

/*
class FirstNonRepeatingChar{
private:
    struct Node{
        char key;
        Node* pre;
        Node* next;
        Node(char c): key(c), pre(NULL), next(NULL){}
    };
    unordered_map<char, Node> map;
    unordered_set<char> set;
    Node* head;
    Node* tail;
public:
    void read(char ch){
        if(set.find(ch) == set.end()){ // set don't contain ch

        }
    }
};*/