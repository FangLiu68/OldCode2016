//
//  Longest subArr have Even 0 1.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/11/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//


// Givne an unsorted array with all 0 or 1s. Return the longest sub-array that contains even numbers of 0s and 1s.

#include "Header.h"

/*
 xxxxxxxx x xxxxxxxxx x xxxxxxxx
          i    	      j

 想要求sum between i and j, we could use M[i] and M[j]:
 M[i] represents the sum fom 0 to i,
 M[j] represents the sum from 0 to j,
 Sum[i, j] = M[j] - M[i] + A[i];

 */
