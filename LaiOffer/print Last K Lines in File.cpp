//
//  print Last K Lines in File.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/7/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*

 */
#include "Header.h"
// use circular array

/*
void printLast10Lines(char* fileName){
    const int k = 10;
    std::ifstream file (fileName);
    string L[k];
    int size = 0;

    // read file line by line into circular array
    while(file.good()){
        getline(file, L[size % k]);
        size++;
    }

    // compute start of circular array, and the size of it
    int start = size > k ? size%k : 0;
    int count = min(k, size);

    // print elements in the order they were read
    for(int i=0; i<count; ++i){
        cout << L[(start+i) % k] << endl;
    }
}*/