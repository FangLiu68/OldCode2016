//
//  Largest and Smallest.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/21/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Use the least number of comparisons to get the largest and smallest number in the given integer array. Return the largest number and the smallest number.

 Assumptions
 The given array is not null and has length of at least 1
 Examples
 {2, 1, 5, 4, 3}, the largest number is 5 and smallest number is 1.
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 M1: sort and return A[0] and A[n-1]
	O(nlog(n))  ~ 10*n
 M2:   for 1 loop  to find the MIN and MAX
	Times = 2 * n
 M3:  xx  xx  xx  xx  xx  xx  xx  xx  xx
 1	  1 1	  1 1	 1  1     (n/2)
 a>b				n       total = n + n/2 = 1.5 * n
 compare a with global_max,  compare b with global_min

 M4: compare each pair, put the larger values in LARGE[n/2]
	put smaller values in SMALL[n/2]
	Total time	= 1.5N
    成对儿比较，把每次比较结果分别放在larger_vector和smaller_vector中，用时O(n/2)
    再分别liner scan两个vector得到最大值和最小值。用时O(n/2+n/2)=O(n)
    一共用时1.5N
 */

// 2n次比较
pair<int, int> largest_and_smallest1(vector<int> arr){
    pair<int, int> res;
    if(arr.empty()) return res;
    /*
    priority_queue<int> pq;
    for(int i=0; i<arr.size(); i++)
        pq.push(arr[i]);
    int largest = pq.top();
    for(int i=0; i<arr.size()-1; i++)
        pq.pop();
    int smallest = pq.top();
    res = make_pair(largest, smallest);
    */
    int largest = arr[0];
    int smallest = arr[0];
    for(int i=1; i<arr.size(); i++){
        if(arr[i] < smallest)
            smallest = arr[i];
        if(arr[i] > largest)
            largest = arr[i];
    }
    res = make_pair(largest, smallest);
    return res;
}

// First, compare 1&2, 3&4, 5&6, .... put the small number in low vector.
// Put the higher number in high vector. Then loop through low and high
// and find the smallest & highest number

pair<int, int> minNumComparisonForLargestAndSmallest(vector<int> arr){
    int len = arr.size();
    if(len == 1) return make_pair(arr[len-1], arr[len-1]);
    vector<int> small;
    vector<int> large;
    // if we have odd number of elements in the array,
    // we need to add the last element to both larger smaller groups
    if(len %2 == 1){
        small.push_back(arr[len-1]);
        large.push_back(arr[len-1]);
    }
    for(int i=0; i<=len-2; i+=2){
        if(arr[i] < arr[i+1]){
            small.push_back(arr[i]);
            large.push_back(arr[i+1]);
        }
        else{
            small.push_back(arr[i+1]);
            large.push_back(arr[i]);
        }
    }
    int low = INT_MAX;
    int high = INT_MIN;
    for(int i=0; i<small.size(); i++){
        if(low > small[i]){
             low = small[i];
        }
    }

    for(int i=0; i<large.size(); i++){
        if(high < large[i]){
            high = large[i];
        }
    }

    return make_pair(low, high);
}
/*
int main(){
    vector<int> arr(5);
    arr[0] = 2;
    arr[1] = 1;
    arr[2] = 5;
    arr[3] = 4;
    arr[4] = 3;
    pair<int, int> res = minNumComparisonForLargestAndSmallest(arr);
    cout << res.first << " " << res.second << endl;
    return 0;
}*/