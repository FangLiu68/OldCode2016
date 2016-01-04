//
//  sum of All Digits.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// find the sum of all digits from 1 to n

#include "Header.h"

int getSum(int n){
    int res = 0;
    for(int i = 1; i <=n; ++i){
        if(i <= 9){
            res = res + i;
        }else{
            int div = 1; // 最高位后面有几个0
            while(i/div >= 10){
                div = div*10;
            }
            int cur = i;
            while(cur != 0){
                int first = cur / div;
                res = res + first;
                cur = cur % div;
                div = div / 10;
            }
        }
    }
    return res;
}
/*
int main(){
    cout << getSum(11) << endl;
    return 0;
}*/