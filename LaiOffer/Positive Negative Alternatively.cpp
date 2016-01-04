//
//  Positive Negative Alternatively.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 An array contains both positive and negative numbers in random order. Order the array elements so that positive and negative numbers are placed alternatively. If there are more positive numbers they appear at the end of the array. If there are more negative numbers, they too appear in the end of the array.
 For example, if the input array is [1 2 3 4 5 -1 -1 -1], then the output should be [1, -1, 2, -1, 3, -1, 4, 5,]  (The ordering of positive/negative numbers do not matter)


 1 2 3 -1 4 5 -1 -1 4   -1
 Step 1:   use quick sort way to put all positive numbers to the left-hand side, (negative number on the right-hand side)
 Step 2:    [1  -1 3 -2 5 -3 4 2]
                                   i            j

 */