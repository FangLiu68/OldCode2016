//
//  Fibonacci.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/12/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

 /*
 写一个函数，输入N，求Fibonacci数列的第N项。
 f(n)=0; // n=0
 f(n)=1; // n=1
 f(n)=f(n-1)+f(n-2); n>1
 */

#include <iostream>
using namespace std;

/*
 DP 的解题常用方法：
 一维的original data (such as a rope, a word, a piece of wood)，求MAX or MIN (cut, merge, etc..)
 if the weight of each smallest element in the original data is identical/similar
 e.g. identical:  1 meter of rope
 e.g. similar:  a letter, a number
	Then this kind of problem is usually simple:
	Linear scan and look back to the previous element(s)
	For example:
 Longest Ascending Subarray (when at i, look back at i-1)
 Longest Ascending Subsequence (when at i, look back at 1….i-1)
 Cut rope
 Cut palindrome
 */


/*
                Fn                     1
    Fn-1                 Fn-2          2
 Fn-2	Fn-3	    Fn-3	Fn-4       4
                                       8…
 由上图可见，如果想要求Fn，就需要一个Fn为根，Fn...F1（中间有很多重复元素）组成的完全二叉树
 二叉树中有多少节点，就表明Fn()这个function需要算多少次
 所以一共是 2^N 时间复杂度
 
                                   F(7)
                     F(6)                          F(5)
               F(5)        F(4)              F(4)          F(3)
         F(4)     F(3)  F(3)  F(2)     F(3)    F(2)    F(2)   F(1) 到最右边第一次出现F(1)，是lower bound
      F(3)  F(2) F(2) F(1)...
    F(2) ...
  F(1) 到最左边第一次出现F(1)，是upper bound

 看最左边这一路径，从F(7)到F(1)行，是2^0 + 2^1 + 2^2 + ... + 2^6 = 2^7-1
 所以upper bound 是 2^n-1 = 2^n
 
 看最右边这一路径，从F(7)到右边第一次出现F(1)，有 (n+1)/2行，是 2^((n+1)/2)
 所以lower bound 是 2^((n+1)/2) = 2^(n/2)
 */
long long Fibonacci_recur(int n){
    if(n <= 0){
        return 0;
    }else if(n == 1){
        return 1; // base case
    }else{
        return Fibonacci_recur(n-1) + Fibonacci_recur(n-2); // recursive rule
    }
}

// Fibonacci[i]表示第i个数
// 记住，fibo的base case是Fibo(0)和Fibo(1) 就这俩
long long Fibonacci_dp(int n){
    if(n <= 0){
        return 0;
    }else if(n == 1){
        return 1;
    }else{
        long long first = 0;
        long long second = 1;
        long long res = 0;
        for(int i=2; i<=n; ++i){
            res = first + second;
            first = second;
            second = res;
        }
        return res;
    }
}



// use recursion with O(N) time complexity and O(1) space
static int res;
static int a = 0;
static int b = 1;
void Fibo(int n){
    if(n==0 || n==1){
        res = n;
        return;
    }
    Fibo(n-1); // breaking point
    res = a + b;
    a = b;
    b = res;
    return;
}


int Fibonacci_dpI(int n){
    if(n==0) return 0;
    else if(n==1 || n==2)   return 1;
    else{
        int* Fibonacci = new int[n+1]; // Fibonacci[i]表示第i个Fibonacci数
        Fibonacci[0] = 0;
        Fibonacci[1] = 1;
        Fibonacci[2] = 1;
        for(int i=3; i<=n; i++){ //注意由于fibonacciArray[0]表示第0个元素，这里是i<=n，而不是i<n
            Fibonacci[i] = Fibonacci[i-1] + Fibonacci[i-2];
        }
        return Fibonacci[n];
    }
}


/*
int main(){
    for(int i=0; i<=10; ++i){
        cout << Fibonacci_dpII(i) << " ";
    }
    cout << endl;
    cout << Fibonacci_dpII(2) << endl;
    return 0;
}*/