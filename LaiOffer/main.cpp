//
//  main.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/3/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
struct test{
    int value; // 4
    test* ptr; // 8
};

class test1{
    int value;
    test1* ptr;
};

void f1(int* &x){
    *x = 10;
}

int main(){
    //test* ptr = new test;
    //test* ptr1 = NULL;
    //test1* ptr2 = new test1;
    cout << sizeof(test1) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(ptr) << endl;
    cout << sizeof(test) << endl;
    cout << sizeof(ptr1) << endl;
    cout << &ptr1 << endl;
    int* pointer = NULL;
    cout << &pointer << endl;*/
    /*int* a = new int;
    cout << a << endl;
    cout << &a << endl;
    cout << *a << endl;
    int* b = NULL;
    cout << b << endl;
    //cout << *b << endl;
    cout << &b << endl;

    int x = 5;
    f4(x);
    cout << x << endl;

    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    cout << a[0] << " " << a[1] << endl;

    return 0;
}*/
/*
int main(){
    double a[] = {1,2,3,4};
    //cout << sizeof(a[0]) << endl;
    //cout << sizeof(a)/sizeof(a[0]) << endl;
    string s = "+";
    cout << stoi(s) << endl;
    return 0;
}*/

/*
 Q1.1 Given an array A[N] with all positive integers from [1...N]. How to get an array B[N] such that B[i] represents how many elements A[j] that are smaller than A[i] and  j > i.
 For example, given  A[N] = { 4, 1, 3, 2 }, we should get B[N] = { 3, 0, 1, 0 }.   Requirement:    Time = O(nlogn).
 */

/*
 Q2.Given a 2D array, in which each row is sorted in an ascending order and each column is sorted in ascending order. How to determine whether a target number x is in the array or not.

 1    2 3 4 5 6
 2    3 4 5 6 7
 3.5  4 5 6 7 7
 4    5 6 7 8 9

 E.g.,
 target = 3.5 return true;
 target = 0 return false;
 */

/*
 Q3 Given a 2D integer array, where every row is sorted in increasing order. How to find a common element in all rows. If there is no common element, then returns -1.
 Example:
 Input: Array[4][5] =
 { 
 {0, 1, 3, 4, 6},
 {3, 4, 6, 8, 10},
 {2, 6, 7, 9, 11},
 {0, 3, 6, 7, 9},
 };
 Output: 6
 */

class A{
private:
    static int a;
public:
     void changeA(int input){
        a = input;
    }
    int get(){
        return a;
    }
};

int A::a = 0;
/*
int main(){
    string s1 = "123";
    cout << s1[0] << endl;
    cout << s1[1] << endl;
    cout << s1[2] << endl;
    cout << s1[3] << endl;
    cout << s1[4] << endl;
    for(int i=0; s1[i]!=0; ++i) cout << s1[i] << " ";
    cout << endl << endl;

    char s2[] = "123";
    cout << s2[0] << endl;
    cout << s2[89] << endl;
    cout << *s2 << endl;


    A object;
    object.changeA(3);
    cout << object.get() << endl;

    char x1[] = "abcdefg";
    char x2[] = "cd";
    string s1 = strstr(x1, x2) ;
    char* res = strstr(x1, x2);
    cout << res << endl;
    cout << &res << endl;
    cout << &s1 << endl;
    cout << "1" << "    " << &res << endl;
    cout << &s1 << endl;
    cout << res << endl;
    //cout << s1 << endl;
    char c1[] = "hfg";
    cout << c1 << endl;
    cout << *c1 << endl;
    cout << &c1 << endl;
    return 0;
}*/