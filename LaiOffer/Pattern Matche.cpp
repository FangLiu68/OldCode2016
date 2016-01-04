//
//  Pattern Matche.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
  Given a text txt (size = n) and a pattern pat (size = m), write a function PatternMatch(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m.
 

            public void PatternMatch (char[] pat, char[] txt) {
  for (int i=0; i <= txt.length - pat.length; i++) {
 int j = i;
 while((j-i) < pat.legnth) {
 if (pat[j-i] != txt[j]) {
 break;
 }
 j++;
 }
 if (j - i == par.length) {
 System.out.println(Arrays.toString(txt,i,j));
 }
 }

 */