//
//  shortest_square_in_num.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Q2 Given positive integer n, return all the lists of squares that sum up to n.
 Note that length of the returned list should be shortest of all such lists.

 E.g.
 5 => 4, 1   (not 1 1 1 1 1 )
 6 => 4, 1, 1
 8 => 4, 4
 11 => 1, 1, 9
 12 -> 4, 4, 4
 */

#include <iostream>
using namespace std;

/*
 Base case:  when n == 1.
 Induction Rule:

 M[i] represents what????
 pair<first = length, second= <list value> >

 1^1=1;
 2^2 = 4;
 3^2 = 9;
 4^2 = 16;
 ….


 n == 1,  solved!					M[1] =1
 n == 2,   M[2]      1 = M[1]   |   1			M[2] =2
 n == 3,           1  1  = M[2] |   1  = 1^2    M[3] = 3
 n == 4,       1 1 1 1         case1		  1 1 1  |  1
                               case2          _ |    1111      = 0 + 1 (2^2)
               M[4] = min (case1, case2)
                    = min(4,      1)
                    = 1
 n == 5,   1 1 1 1   | 1      = 	case1   M[4] +   1     = 1 + 1 =2
           1    |  1 1 1 1    =		case2   M[1]  +  1  =	1+1  =2
           M[5] = min(case1, case2) = 2

 for a given target number   T
 case1		M[T-1]
 case2		M[T-4]
 case3	.	M[T-9]
 min(case1, case2,  case3…..)
 xxxxxxxxxxxxxxxxxxxxxxxxx|   xxx
 M[] tells you 						1^2, 2^2, 3^2, 4^2
 1   4  9  16 25 …..36

 =========================================================

 target = T

 T＝		 sum1 + 		sum2
 CASE1	M[T-1]			1^2
        M[T-2^2]		2^2
        M[T-3^2]		3^2
 */

int shortest_square(int num){
    int M[num+1];
    for(int i=1; i<=num; ++i){
        M[i] = INT_MAX;
        for(int j=1; j*j <= i; ++j){
            M[i]= min(M[i - j*j] + 1, M[i]);
        }
    }
    return M[num];
}
/*
int main(){
    int num = 6;
    cout << shortest_square(num) << endl;
    return 0;
}*/