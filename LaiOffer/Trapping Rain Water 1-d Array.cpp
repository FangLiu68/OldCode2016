//
//  Trapping Rain Water 1-d Array.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/3/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 
 For example,
 Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 
 
 The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. 
 */

/*
 for each index, how much water it can be trapped at its position
 max_water[i] = min(highest_on_left[i], highest_on_right[i]);
 
 space optimization -> 2 pointers
 */