//
//  Q2.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/18/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 One buyer can buy stock at most twice and the second transaction can only start after first one is complete (Sell->buy->sell->buy). 
 Given stock prices throughout day, find out maximum profit that a share trader could have made.  
 Restriction: Time =O(n); space: O(1)
 */

#include <iostream>
using namespace std;

/*
 如果是只能trade一次。then always keep the min value till now, and get the reslut of (current_val - min_val_till_now)
 and then compare it with the global max value. update max when necessary.
 */