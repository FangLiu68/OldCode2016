//
//  Divide.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/28/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Divide two integers without using "/"

#include <iostream>
using namespace std;

int divide(int a, int b){
    if(b == 0){
        return INT_MAX;
    }
    if(a == 0 || a<b){
        return 0;
    }
    if(a == b){
        return 1;
    }
    int left = 0;
    int right = 1;
    while(right * b < a){
        right = right*2;
    }
    while(left < right-1){
        int mid = left + ((right-left)>>1);
        if(mid*a == b){
            return mid;
        }
        if(mid*a < b){
            left = mid;
        }else{
            right = mid;
        }
    }
    if(a*right < b){
        return right;
    }
    return left;
}
/*
int main(){
    int a = 13;
    int b = 3;
    cout << divide(b, a) << endl;
    return 0;
}*/