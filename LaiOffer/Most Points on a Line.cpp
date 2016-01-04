//
//  Most Points on a Line.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/18/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Given an array of coordinates of points, how to find largest number of points that can be crossed by a same line in 2D space?

#include <iostream>
using namespace std;

/*
 Point 1 <x1, y1>
 Point 2 <x2, y2>
 Point 3 <x3, y3>
 ……
 Point n <xn, yn>

 n points

 Method: y = ax + b
 a: slope
 b: intercept

 Hash_table1 <key=<a, b>,    value = Set() >

 P1: P2~Pn, <a, b>  → Hashtable1
 P2: P3~Pn, ….
 ….
 Pn-1: Pn …

 Corner case: what is the slope is infinity??????
 <x1, y1> <x2, y2>      iff (x1 == x2)
 When the slope is infinity (x1 == x2)
 Hash_table2 <key =  x coordinate,     value = Set()>

 */