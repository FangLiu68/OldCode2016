//
//  quick sort.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//
#include <iostream>
#include <vector>
using namespace std;

/*
 quick sort
 principle: iterate over the whole array, and put all numbers smaller than pivot to the left, then put the pivot following (all numbers larger than the pivot are already on the pivot's right hand)
 implementation details: first put the pivot to the right most position (swap(arr[pivot], arr[right])).
 */

/*
 1 9 8 5 3

 1st Question: 
 what  is the final position of 5?  5 is randomly selected (5 is called pivot).
 
 principle:
 iterate over the whole array, and put all numbers smaller than 5 to the left, then put 5 following (all numbers larger than 5 are already on 5’s r-hand).

 implementation details:   
 first put 5 to the right most position (swap(5, 3)).

 两个挡板 i j ,三个区域 a) b) c) 的思想：
 a) [0...i) :   i 的左侧（不包含i） 全部为比pivot小的数
 b) [i...j]:    i 和 j 之间为未知探索区域
 c) (j...n-1]:  j 的右侧(不包含j) 全部为比pivot大或等于的数字

 1 9 8 3 5    current number: 1 .  1 < 5, so nothing changes, we will look at the next number 9
 i     j
 1 9 8 3 5    current number: 9.  9 > 5, so put 9 to the number to the left of 5, ⇒  swap(9, 3)
   i   j
 1 3 8 9 5    current number: 3.  3 < 5, so nothing changes, we look at the next number 8
   i j
 1 3 8 9 5    current number: 8.  8 > 5, so put 8 to the number to the left of 9
     ij         (9 was the left boundary of all numbers that are larger than 5)

 1 3 5 9 8   finally, 5 is put to the right and FINAL position   (by calling swap(5, 8))
 Recursive rule:	
 Quicksort all numbers to the left of 5,
 Quicksort all numbers to the right of 5,
 */


/*
 quicksort space complexity
 如果算stack call的话，average O(logN)
 因为每次Partition O(1)，一共logN次recursion call，stack上占空间O(LOGN)
 
 When does the worst case of Quicksort occur?
 The answer depends on strategy for choosing pivot. In early versions of Quick Sort where leftmost (or rightmost) element is chosen as pivot, the worst occurs in following cases.

 1) Array is already sorted in same order.
 2) Array is already sorted in reverse order.
 3) All elements are same (special case of case 1 and 2)

 Since these cases are very common use cases, the problem was easily solved by choosing either a random index for the pivot, choosing the middle index of the partition or (especially for longer partitions) choosing the median of the first, middle and last element of the partition for the pivot. With these modifications, the worst case of Quick sort has less chances to occur, but worst case can still occur if the input array is such that the maximum (or minimum) element is always chosen as pivot.
 */


// partition返回的是一个index，这个index所指向的数字在他正确的位置上
int partition(int arr[], int left, int right) {
    int pivotPos = left + (right-left)/2;
    int pivot = arr[pivotPos];

    // swap the pivot element to the rightmost position first
    swap(arr[pivotPos], arr[right]);

    int leftBound = left;
    int rightBound = right - 1;

    /*
     1 3 2 8 9 5
         r l
     */

    // 保证leftBound的左边都是<pivot的值，rightBound的右边都是>=pivot的值，直到两者都不符合条件时，互换两者指向的元素，同时leftBound和rightBound都各自往前走
    while(leftBound <= rightBound){ // NOTE: left <= right
        if(arr[leftBound] < pivot){
            leftBound++;
        }else if(arr[rightBound] >= pivot){
            rightBound--;
        }else{
            swap(arr[leftBound++], arr[rightBound--]);
        }
    }

    // 此时，leftBound指向的位置的左边所有的数都小于pivot，leftBound位置的右边的所有的数都大于等于pivot
    // 所以我们需要swap back pivot(在arr[right]的位置上)，把他放回他在arr中正确的位置上
    swap(arr[leftBound], arr[right]);
    return leftBound;
}

void quickSort(int array[], int left, int right) {
    if (left >= right)  return;

    /* pivotPos得到的是以left/right为左右边界，中间取一个任意值(在实现中我们取arr[(left+right)/2]为这个任意值)，这个任意值在排序后应该存在的位置.例如[0, 5, 1, 4, 2, 3], 则pivotPos为1；[0, 5, 4, 1, 2, 3]，则pivotPos为4. */
    int pivotPos = partition(array, left, right);

    // 上面一步完成之后，pivot已经放在的本应该放的位置上（4）。那么我们只用再分别quickSort[0,3], quickSort[5,5]，就可以了
    quickSort(array, left, pivotPos - 1);
    quickSort(array, pivotPos + 1, right);
}

void quickSort(int array[], int len) {
    if (array == NULL)  return;
    quickSort(array, 0, len - 1);
}

//============same as before, just use vector
void helper_swap(int& i, int& j);
int partition1(vector<int>& input, int left, int right);
void quicksort1(vector<int>& input, int left, int right);

vector<int> quickSort(vector<int> array) {
    if(array.empty()) return vector<int>();
    
    quicksort1(array, 0, array.size()-1);
    return vector<int>(array.begin(), array.end());
}

// 注意，如果我们用vector传入input的话，都要传入引用&
void quicksort1(vector<int>& input, int left, int right){
    if(left >= right) return;
    
    int index = partition1(input, left, right);
    
    quicksort1(input, left, index-1);
    quicksort1(input, index+1, right);
}

int partition1(vector<int>& input, int left, int right){
    int pivot_index = left + (right-left)/2;
    int pivot_value = input[pivot_index];
    
    helper_swap(input[pivot_index], input[right]);
    
    int left_bound = left;
    int right_bound = right-1;
    
    while(left_bound <= right_bound){
        if(input[left_bound] < pivot_value){
            left_bound++;
        }else if(input[right_bound] >= pivot_value){
            right_bound--;
        }else{
            helper_swap(input[left_bound++], input[right_bound--]);
        }
    }
    
    helper_swap(input[left_bound], input[right]);
    
    return left_bound;
}

void helper_swap(int& i, int& j){
    int temp = i;
    i = j;
    j = temp;
}

//====================================================================================================
// 方法2
// 两个挡板 三个区间。storeIdx的左侧全部都比pivot小，storeIdx和i之间未知，i右侧全部比pivot大
void quicksort(int *a, int left, int right){
    if (left >= right)
        return;
    int pivot = left+(right-left)/2;
    swap(a[pivot], a[right]);
    int storeIdx = left;
    for (int i = left; i < right; i++) {
        if (a[i] < a[right]) {
            swap(a[storeIdx++], a[i]);
        }
    }
    swap(a[storeIdx],a[right]);
    quicksort(a, left, storeIdx-1);
    quicksort(a, storeIdx+1, right);
}

/*
int main(){
    //           0  1  2  3  4  5
    int arr[] = {0, 5, 4, 1, 2, 3};
    cout << partition(arr, 0, 5) << endl;
    //quickSort(arr, 6);
    for(int i=0; i<6; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
*/