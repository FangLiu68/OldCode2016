//
//  Nested Int Weighted Sum.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Nested integer weighted sum. 一个list, 元素可能是list，也可能是Integer，但是每个元素都包装在NestedInteger类里面了，求weighted sum. 例子是{2{4{6}}}. 应该返回2×1 + 4×2 + 6×3.
 public int getSum(String cand) {
 if (cand == null || String.length() == 0) {
 return 0;
	}
	return help(cand, 1, 0);
 }
 private int help(String cand, int level, int index) {
 if (cand.charAt(index) == ‘)’) {
 return 0;
	}
	if (cand.charAt(index) == ‘(’) {
	index++;
	}
	boolean isNeg = false;
	if (cand.charAt(index) == ‘-’) {
	isNeg = true;
 index++;
	}
	int val = 0;
	for (; index < s.length(); index++) {
 if(!Chatacter.isDigit(s.charAt(index))) {
 break;
 }
 val = val * 10 + s.charAt(index) - ‘0’;
	}
	int val = val * level;
	if (isNeg) {
	val = -val;
	}
	return val + help(cand, level + 1; index);
 }
 static int getNum(String s, int lvl){
        if(s.length() == 0)
        return 0;
        int i = 0;
        while(i < s.length() && !isNum(s.charAt(i)))
            i++;
        int j = i;
        while(j < s.length() && isNum(s.charAt(j)))
            j++;
        return (s.substring(i, j).equals("") ? 0 : Integer.parseInt(s.substring(i, j)) * lvl) + getNum(s.substring(j), lvl + 1);
    }
    static boolean isNum(char c){
        return '0' <= c && c <= '9';
    }

 */