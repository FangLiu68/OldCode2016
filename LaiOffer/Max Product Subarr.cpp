//
//  Max Product Subarr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array that has both positive and negative integers (size  >= 2), find the product of the maximum product subarray.
 Examples:
 Input: arr[] = {6, -3, -10, 0, 2, 4, -1, -2}
 Output:   180  // The subarray is {6, -3, -10}
 Optimal and clean solution:
 MIN[i]   the Minimun product of the subarray that is ends with index i (must including i);
 MAX[i]  the Maximun product of the subarray that is ends with index i;
 base case: MIN[0]  = MAX[0] = arr[0];
 rule:
 MIN[i] = min( arr[i], MIN[i - 1] * arr[i], MAX[i - 1] * arr[i]);
 MAX[i] = max( arr[i], MIN[i - 1] * arr[i], MAX[i - 1] * arr[i]);
 

 */