//
//  Largest Val from Arr of Nums in String type.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
  Given an array of numbers in string type, arrange them in a way that yields the largest value. For example.  For example,  if the given numbers are {“54”, “546”, “648”, “88”}, the arrangement “8864854654” gives the largest value.
 
 
 comparator:
 sort array based on first digit number
	if they are same, sorted by on the next digit number
	s1 = 9
	s2 = 98      9 > 98
	s1 + s2 =  “998”
	s2 + s1 =  “989”

	4
	49     49 > 4

 concatenate each string in order
 bool cmp (string &s1, string &s2) {
 string str1 = s1+s2;
 string str2 = s2+s1;
 if (str1.compare(str2) > 0) {
 return true;
	} else {
	return false;
	}
 }
 string LargestNumber(vector<string> &v) {
 sort(v.begin(), v.end(), cmp);
 string res = “”;
 for (int i = 0 ; i < v.size(); ++i) {
 res += v[i];
	}
	return res;
 }

 */