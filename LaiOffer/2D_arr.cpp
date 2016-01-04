//
//  2D_arr.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include <iostream>
using namespace std;

int** my2DAlloc_true(int row, int col) {
    int ** res = (int**) malloc (row * sizeof(int*) + row * col * sizeof(int));
    if (!res)
        return NULL;
    // base is the starting memory that stores 2D array content.
    int* base =  (int*)(res + row);   // res + row: row * sizeof(int*)
    //int** base = res + row;
    for (int i = 0; i < row; ++i) {
        // connect row pointer (i) with starting address of row(i)
        res[i] = base + i * col;
    }
    return res;
}

int** my2DAlloc_false(int row, int col) {
    int ** res = (int**) malloc (row * sizeof(int*) + row * col * sizeof(int));
    if (!res)
        return NULL;
    int** base = res + row;
    for (int i = 0; i < row; ++i) {
        res[i] = (int*) (base + i * col);      // shifting i * col * sizeof(int*)
    }
    return res;
}

/*
int main() {
    int row = 2;
    int col = 3;

    int** a = my2DAlloc_true(row, col);        // using my2DAlloc to allocate a
    int* b = (int*) malloc(10 * sizeof(int));     // Then, immediately allocate 1D array b.

    for (int i = 0; i < 10; ++i) {
        b[i] = i;
    }
    for (int i = 0; i < row; ++i) {     // 0 1 2
        for (int j = 0; j < col; ++j) {  // 3 4 5
            a[i][j] = i * col + j;
        }
    }
    for (int i = 0; i < 10; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    if(sizeof(int) == sizeof(int*)){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
}
*/
