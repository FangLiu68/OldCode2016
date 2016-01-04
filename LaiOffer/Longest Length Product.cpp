//
//  Longest Length Product.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/13/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 一个字典有给一系列strings，要求找两个string，使得他们没有共同字符，并且长度乘积最大
 assumption: all letters in the word is from 'a-z' in ASCII
 
 Example:
 w1 abcde     size = 5
 w2 adzz       size = 4
 w3 abd         size = 3
 w4 fgz          size = 3;
 solution:  abcde x fgz = 5 x 3  == 15
 */

/*
 Best First Search (BFS2):
 Initial state (start state)
 Expansion/generation
 Termination condition
 Deduplication (for the same state when generated)

 1.Initial state: <w1, w2>
 2.Expansion/Generation rule    <W1, W2> → <W2, W2>,  <W1, W3>.
 state<wi, wj> →  <wi+1, wj> or <wi, wj+1>. be careful about the caes like <wi, wi>
 3.Termination condition:  whenever a state <wi, wj> is popped out of the max_heap, and wi and wj do not share any common chars, then terminate.
 <w2 w3>  !=????  <w3 w2>

 */