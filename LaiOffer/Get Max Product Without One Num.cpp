//
//  Get Max Product Without One Num.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/14/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Compute the max product of an array without an element.
 [1, 2, 3, 4, 5]    2 * 3 * 4 * 5
 */

#include <iostream>
using namespace std;

/*
 Method 1:
 找出所有相乘的结果，然后取最大的那个 O(n^2)
 注意不能先把所有结果相乘后，每次除以一个数。(1.除数是0怎么办？2.除的结果是int，会向下取整)
 
 

 Method 2:
 Find the index of the element we need remove.

 zero_count   => number of zeros
 pos_count => number of positive numbers
 neg_count => number of negative numbers
 zero_index => the index of zero
 s_neg_index => index of smallest negative number
 b_neg_index => index of largest negative number
 s_pos_index => index of smallest positive number
 
 1. Go through the array, and record those seven variables.
 2. if(zero_count == 1){
        return 0;
    }else if(zero_count == 1){
        if(neg_count == odd){
            return 0;
        }else{
            remove zero_index;
        }
    }else{
        if(neg_count == odd){
            remove b_neg_index;
        }else{
            if(pos_count == 0){
                remove s_neg_index;
            }else{
                remove s_pos_index;
            }
        }
    }
 3. multiply all other elements without the one needed
*/



