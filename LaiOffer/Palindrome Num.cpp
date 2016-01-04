//
//  Palindrome Num.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/15/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Determine whether an integer is a palindrome. Do this without extra space.
 Some hints:
 Could negative integers be palindromes? (ie, -1)
 If you are thinking of converting the integer to string, note the restriction of using extra space.
 You could also try reversing an integer. However, if you have solved the problem ”Reverse Integer”,
 you know that the reversed integer might overflow. How would you handle such case? There is a more generic way of solving this problem.
 */

#include <iostream>
using namespace std;

/*
 首先想到,可以利用上一题,将整数反转,然后与原来的整数比较,是否相等,相等则为 Palindrome 的。可是 reverse() 会溢出。
 正确的解法是,不断地取第一位和最后一位(10 进制下)进行比较,相等则取第二位和倒数第 二位,直到完成比较或者中途找到了不一致的位。

 例如 12321
 div得到最高位后面有几个0.
 x/div 得到最高位
 x%10  得到最低位
 每次比较后，更新x，掐头去尾，对更新后的x再次比较最高位和最低位的值
 注意：/ 去掉后面的位数；% 得到后面位数上的数值
 */

// time complexity O(1), space complexity O(1)
bool isPalindrome(int x) {
    if(x < 0) return false;
    int div = 1;
    while(x/div >= 10)
        div = div*10;
    while(x != 0){
        int left = x/div;
        int right = x%10;
        if(left != right) return false;
        x = (x%div) / 10;
        div = div/100;
    }
    return true;
}