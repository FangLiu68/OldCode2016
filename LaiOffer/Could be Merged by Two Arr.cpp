//
//  Could be Merged by Two Arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/18/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// How to determine whether an array C[] can be merged by A[] and B[], while reserving the relative order of the letters in the original arrays A[] and B[]?

#include <iostream>
using namespace std;

/*
 string A = “abcd”
 string B = “acde”
 string C = “acde abcd”

 Method1: DP
 Base case:    M[0][0] = true;
 Induction Rule:  M[i][j]

 The i+j-th letter can be from either A[i] or B[j]

 M[i][j] represents what:      Whether the prefix of the C[], that is C[0...i+j] can be represented by A[i] and B[j].

 M[i][j]  = M[i-1]M[j] && A[i] == C[i+j]         if the i+j-th letter is  from A[]
            ||  M[i]M[j-1] && B[j] == C[i+j]        else
 A :aab      B:   ba
 C= ababc
 B=	   b a
 index 0 1 2
 A
 0     T f f
 1 a   T T T
 2 a   F T T
 3 b   F T F

 O(m*n)

 Method2: Recursion
 Base case: When one string is empty, just check whether the other string’s suffix is identical to the C string’s suffix
 Recursive rule:
 A[i],  B[j]  vs    C[i+j]
 Case1	A.substring(i+1)   B.substring(j)      C.substring(i+j+1]),  when only A[i] == C[i+j]
 Case2	A.substring(i)   B.substring(j+1)   C.substring(i+j+1]),  when only B[j] == C[i+j]
 Case3  if both A[i] == C[i+j] &&  B[j] == C[i+j]      
        A.substring(i+1)   B.substring(j)      C.substring(i+j+1]),  
        ||   A.substring(i)   B.substring(j+1)   C.substring(i+j+1]),
 Case4, return false;
 */

//Method 1: recursion
/*
bool Combineable(int index_a, int index_b, int index_c ) {
    if (index_a == A.size() && index_b == B.size()) {
        return index_c == C.size(); // base case
    }
    // case 3.
    if (A[index_a] == C[index_c] && B[index_b] == C[index_c]) {
        return Combineable(index_a + 1,  index_b,  index_c +1) ||
        Combineable(index_a, index_b + 1,index_c + 1);
        // case1.
    } else if (index_a < A.size() && A[index_a] == C[index_c]) {
        return Combineable(index_a + 1,   index_b, index_c + 1);
        // case2.
    } else if (index_b < B.size() && B[index_b] == C[index_c]) {
        return Combineable(index_a, index_b + 1,  index_c + 1);
        // case 4.
    } else {
        return false;
    }
}
*/

//Second way of writing code with recursion.
/*
bool result1 = false;
bool result2 = false;
if(index_a < A.size()) && a[index_a]== C[index_c]{
    result1 = Combineable(index_a+1，index_b,index_c-1);
}

if(index_B < B.size()) && b[index_b]== C[index_c]{
    result2 = Combineable(index_a+1，index_b,index_c-1);
}

return result1 || result2;
*/

//Worst Case Time = O(2^(m+n))
//Best Case Time = O(m+n)

/*
int main() {
    bool result = Combineable(0, 0, 0);
    if (result) {
        cout << "Yes!!!" <<endl;
    } else  {
        cout << "No!!!" <<endl;
    }
    return 0;
}
*/