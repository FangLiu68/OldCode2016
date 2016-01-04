//
//  Count Num of Words in String.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given a string, count number of words in it. The delimiters can be the following characters: space (‘ ‘) or new line (‘\n’) or tab (‘\t’) or a combination of these.
 
 
 // returns number of words in str
 unsigned countWords(char *str) {
 int count = 0;
 if (str == NULL) return count;
 bool marker = false; //mean whether previous character is the delimiter
 char c = str[0];
 for (; c != ‘\0’; ++i) {
 if (c != ‘ ’ && c != ‘\t’ && c != ‘\n’) {
 marker = false;
 continue;
 }
 if (marker == false && (c == ‘ ’ || c == ‘\t’ || c == ‘\t’)) {
 marker = true;
 ++count;
 }
	}
	//check last word in string
	if (maker == false && str[0] != ‘\0’) {
	++count;
	}
	return count;
 }

 */