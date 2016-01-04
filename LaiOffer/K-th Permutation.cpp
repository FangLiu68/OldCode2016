//
//  K-th Permutation.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/9/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 All permutations of {1, 2, 3} sorted from smallest to largest:
 {1, 2, 3}
 {1, 3, 2}
 {2, 1, 3}
 {2, 3, 1}
 {3, 1, 2}
 {3, 2, 1}
 Find the kth one of all the permutations of {1, 2, 3, …, n}, where n <= 9.
 Example: n = 3, k = 4 → {2, 3, 1}

 1: 2 * 1
 2: 2 * 1
 3: 2 * 1

 from left to right, what is the value for each position.
 */