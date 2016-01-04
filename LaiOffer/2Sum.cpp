//
//  2Sum.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/24/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Determine if there exist two elements in a given array, the sum of which is the given target number.
 Assumptions
 The given array is not null and has length of at least 2
 ​Examples
 A = {1, 2, 3, 4}, target = 5, return true (1 + 4 = 5)
 A = {2, 4, 2, 1}, target = 4, return true (2 + 2 = 4)
 A = {2, 4, 1}, target = 4, return false
 */

#include <vector>
#include <iostream>
using namespace std;

bool twoSum(vector<int> arr, int target){
    if(arr.empty()) return false;
    int left = 0;
    int right = arr.size()-1;
    sort(arr.begin(), arr.end());
    while(left < right){ // 注意这里是 < 
        if(arr[left] + arr[right] == target)
            return true;
        else if(arr[left] + arr[right] < target)
            left++;
        else
            right--;
    }
    return false;
}
/*
int main(){
    vector<int> arr = {2,4,2,1};
    if(twoSum(arr, 5)) cout << "1" << endl;
    else cout << "0" << endl;
    return 0;
}*/