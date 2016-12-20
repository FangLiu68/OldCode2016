//
//  Replace Elem with Multip of All Other Elems.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/3/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 For an int array, replace each element with the multiplication of all elements other than that element.
 eg, {1, 2, 3, 4} -> {24, 12, 8, 6}
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 Method 1:
 get the multiplication of all the elements in this array: x, for a[i]-> x/a[i]
 - several 0s
 - overflow
 - "/": expensive operation
 
 Method 2: 中心开花
 left[i] = multiplication of all the elements on the left side of i
 right[i] = multiplication of all the elements on the right side of i.
 a[i] = left[i] * right[i]
 */