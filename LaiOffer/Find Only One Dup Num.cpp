//
//  Find Only One Dup Num.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/16/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 There is an unsorted array A[N+1] with all numbers from 1 to n, and there is only one duplicate number, try to find it.
 
 0, 1, 2
 1, 2, 3
 1 2 3 4 5 6 …… n  →
 n+1 numbers total
 public int getDup(int[] a) {
 if(a == null || a.length == 0)
 return -1;
 int res = 0;
 for(int i = 1; i <= n; i++)
 res ^= i;
 for(int i = 0; i < a.length; i ++)
 res ^= a[i];
 return res;
 }
 1 2 3 2
 1 2 3
 res = 1^2^3 ^1^2^3^2 = 2

 */