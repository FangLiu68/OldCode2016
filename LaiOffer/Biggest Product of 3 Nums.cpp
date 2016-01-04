//
//  Biggest Product of 3 Nums.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Given an array, return the highest positive product by multiplying 3 distinct numbers.
 for example:
 {1,3,5,2,8,0,-1,3} => 8*5*3 = 120
 {0,-1,3,100,-70,-5} => -70 * -50 * 100 = 350000
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 1) Find top 3 and bottom 2 values from the list in O(n)
 2) Let the list be [a, b, c ..... d, e]

 modification:
 3) find maximum of b*c and d*e.
 prod1 = max(b*c, d*e);

 4. output: a * prod1.
 */

int biggest_product_for_3Nums(vector<int> input){
    if(input.size() <= 3){
        int res = 1;
        for(int i=0; i<input.size(); ++i){
            res = res * input[i];
        }
        return res;
    }
    sort(input.begin(), input.end());
    reverse(input.begin(), input.end());
    int front = input[1] * input[2];
    int back = input[input.size()-1] * input[input.size()-2];
    int prod = max(front, back);
    return input[0] * prod;
}
/*
int main(){
    vector<int> input1 = {1,3,5,2,8,0,-1,3};
    vector<int> input2 = {0,-1,3,100,-70,-5};
    vector<int> input3 = {-5,-4,2,7};
    cout << biggest_product_for_3Nums(input1) << endl;
    cout << biggest_product_for_3Nums(input3) << endl;
    return 0;
}*/