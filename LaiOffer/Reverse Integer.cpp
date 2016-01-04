//
//  reverse_integer.cpp
//  LeetCode
//
//  Created by Fang Liu on 8/9/14.
//  Copyright (c) 2014 Fang Liu. All rights reserved.
//

/*
 Reverse digits of an integer.
 Example1: x = 123, return 321
 Example2: x = -123, return -321

 Example Questions Candidate Might Ask:
 Q: What about negative integers?
 A: For input x = –123, you should return –321.
 Difficulty: Easy, Frequency: High
 ￼￼Q: What if the integer’s last digit is 0? For example, x = 10, 100, ...
 A: Ignore the leading 0 digits of the reversed integer. 10 and 100 are both reversed as 1.
 Q: What if the reversed integer overflows? For example, input x = 1000000003. A: In this case, your function should return 0.
 */

#include <iostream>
using namespace std;

/*
 We do not need to handle negative integers separately, because the modulus operator works for negative integers as well (e.g., –43 % 10 = –3).
 There is a flaw in the above code – the reversed integer could overflow/underflow. Take x = 1000000003 for example. To check for overflow/underflow, we could check if ret > 214748364 or ret < –214748364 before multiplying by 10. On the other hand, if ret == 214748364, it must not overflow because the last reversed digit is guaranteed to be 1 due to constraint of the input x.

 不用单独考虑x为负数的情况，因为负数模10仍为负数，符号不变。
 需要考虑溢出的情况。32位的int型的取值是2147483647 到 -2147483648，所以在res*10之前，要查看res的绝对值是否大于214748364。如果大于214748364，则一定会溢出，直接返回0。需要注意，如果等于214748364，则一定不会溢出。因为下一个需要reverse的digit一定是1（保证输入有效，如果是2，则输入已经溢出）
 */
int reverse(int x) {
    int res = 0;
    while(x != 0){
        if(abs(res) > 214748364)
            return 0;
        res = res*10 + x%10;
        x = x/10;
    }
    return res;
}