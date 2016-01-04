//
//  str_to_int(atoi).cpp
//  LeetCode
//
//  Created by Fang Liu on 5/2/14.
//  Copyright (c) 2014 Fang Liu. All rights reserved.
//

/* Implement atoi to convert a string to an integer.
 Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are respon- sible to gather all the input requirements up front.
 Requirements for atoi:
 The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
 The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
 If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is per- formed.
 If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

 A desirable solution does not require any assumption on how the language works. In each step we are appending a digit to the number by doing a multiplication and addition. If the current number is greater than 214748364, we know it is going to overflow. On the other hand, if the current number is equal to 214748364, we know that it will overflow only when the current digit is greater than or equal to 8. Remember to also consider edge case for the smallest number, –2147483648 (–2^31).
 */

#include <iostream>
using namespace std;

/*
 1. 跳过开始的所有空格
 2. 确定正负号(正负号不能连续出现)
 3. 如果当前字符不是数字，立即返回0
 4. 如果结果溢出，则返回溢出边界.
 注意：32位有符号int的范围是-2147483648(INT_MIN)~~~2147483647(INT_MAX)
 如果当前值大于214748364，则他继续往下一位转换的时候肯定会溢出
 如果当前值等于214748364，则他继续往下转换时，只有下一位大于7才会溢出
 */
int atoi(const char* str){
    while(*str == ' ') str++;
    int sign = 1;
    if(*str == '+') str++;
    else if(*str == '-') sign = -1, str++;
    int sum = 0;
    for(; *str != '\0'; str++){
        if(*str<'0' || *str>'9') break;
        if((sum > INT_MAX/10) || (sum == INT_MAX/10 && (*str-'0')>INT_MAX%10))
            return (sign==-1)? INT_MIN:INT_MAX;
        sum = sum*10 + *str-'0';
    }
    return sign*sum;
}

/*
 int main(){
 char str[] = "21474836455";
 cout << atoi(str) << endl;
 return 0;
 }*/