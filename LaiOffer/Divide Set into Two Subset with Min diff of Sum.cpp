//
//  Divide Set into Two Subset with Min diff of Sum.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a set of n integers, divide the set in two subsets of n/2 sizes each such that the difference of the sum of two subsets is as minimum as possible.
 
 
 Solution:
 total = sum(a[i]); half = total / 2; m = n / 2;
 DFS: layer (m) , try (n)
 int sum( vector<int> cur) {TODO};
 void findhalf(const vector<int>& input,  int half_sum,  int index, vector<int> cur, vector<int>& res) {
 if (index == input.size() / 2) {
 int current_sum = sum(cur);
 }
 bool already[n];
 for (int i = 0; i < input.size(); i++) {
 if (!already[i]) {
 already[i] = true;
 cur.push_back(input[i]);
 findhalf(input, half_sum, index + 1, cur, res);

 */