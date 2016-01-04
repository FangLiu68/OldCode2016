//
//  Fibonacci sequence.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include <iostream>

/*
 O(2^n) runtime, O(n) space
                                                       F(4)
                                                /                   \
                               F(3)   breaking point       +          F(2)
                                        /         \                 /   \
                                  F(2)=1 ==>  +   F(1)         F(1) + F(0)   ⇒ 0 +1 = 1
                                   /   \
                             F(1) =1  + F(0)=0
 从F(4)往下一直走到底，其实是个深度优先。
 F4一直都到F1，然后和F0得到F2.。。。
 可以看出左半部分的F2和右半部分的F2完全没有关系，右边的F2又重新计算了一次。所以这里可以更新成DP做法

 time complexity:   1 2 4 8 16……  O(2^(n-1)) 即求这个二叉树所有的节点数
 第一行2^0, second line 2^1, third line 2^2...nth line 2^(n-1)
 Trick: 所有前面的node的个数的总和，都没有最后一层node的个数多，因此我们分析tree的time complexity，往往只看最后一层node的个数。
 如果每层都recur 3次  那么就是3^0+...3^(n-1)
 n layers total
 2^0 +  2^1  + 2^2 + …    2^(n-1) =
 1 +     2  +  4 +  8 ... 16  + … 2^(n-1)

  immediately return 1
 2^0 + 2^1 + 2^2 ... 2^1000 == 2^n
 1+ 2 + 4 + 8 + 16 + 32  →
 Time complexity = O(2^n)
 Space complexity = O(n)
 假设n=1000，第一行执行2^0, 第二行执行2^1, 第三行执行2^2… 最后一行执行2^1000
 加起来几乎是2^n
 Trick: 最后一行以上的执行次数都比最后一行小，所以只看最后一行就可以。最后一行是1000，那就是2^1000，即O(2^n)
 因为是DFS，一直压栈，有多少元素就压栈多少次，那么space complexity O(n)
 */

// calculating Fibonacci value
int fibo_recur(int n){
    // base case
    if(n == 0) return 0;
    else if(n == 1) return 1;

    return fibo_recur(n-1) + fibo_recur(n-2); // recursive rule
}

// use O(n) space
long fibo_dp1(int K) {
    // Write your solution here
    if(K <= 0){
        return 0;
    }
    long* arr = new long[K];
    arr[0] = 1;
    arr[1] = 1;
    for(int i=2; i<K; ++i){
        arr[i] = arr[i-1] + arr[i-2];
    }
    long res = arr[K-1];
    delete[] arr;
    return res;
}

// use O(1) space
long fibo_dp2(int K) {
    if(K<=0){
        return 0;
    }
    if(K<=2){
        return 1;
    }
    long a = 1;
    long b = 1;
    for(int i=3; i<=K; ++i){
        long tmp = a+b;
        a = b;
        b = tmp;
    }
    return b;
}
