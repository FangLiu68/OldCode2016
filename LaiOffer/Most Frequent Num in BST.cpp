//
//  Most Frequent Num in BST.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/10/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// 找BST里面出现次数最多的Integer

/*
 do inorder traversal:
	record:
 the number with max occurrence:  a
 max occurrence: an
 the current number:   c
 occurrence of current number: cn
 
 if (curr == c) {
	cn++;
 } else {
 c = curr;
 cn = 1;
 }
 if (an < cn) {
	a = c;
	an = cn;
 }

 */