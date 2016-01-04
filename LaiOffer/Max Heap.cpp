//
//  Max Heap.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/8/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include "Max Heap.h"
#include <iostream>
using namespace std;

#define MAXSIZE 100

// Heapify:
MaxHeap::MaxHeap(int* input, int size) {
    hList = input;
    heapSize = size;
    maxHeapSize = MAXSIZE;
    int cut = (size - 2) / 2;                // Complete binary tree.
    for (int i = cut; i >= 0; --i) {
        FilterDown(i);
    }
}

void MaxHeap::FilterDown(int pos) {
    int curr = pos;
    int child = curr * 2 + 1;    // left child index.
    int temp = hList[curr];
    while (child < heapSize) {
        if (child + 1 < heapSize && hList[child + 1] > hList[child]) {
            child++;
        }
        if (hList[child] > temp) {
            hList[curr] = hList[child];
            curr = child;
            child = curr * 2 + 1;
        } else {
            break;
        }
    }
    hList[curr] = temp;
}

void MaxHeap::Insert(int value) {
    if (heapSize >= maxHeapSize) {
        return;
    }
    hList[heapSize] = value;
    FilterUp(heapSize);
    heapSize++;
}

void MaxHeap::FilterUp(int pos) {
    int curr = pos;
    int parent = (pos - 1) / 2;
    int temp = hList[pos];
    while (curr != 0) {
        if (temp > hList[parent]) {
            hList[curr] = hList[parent];
            curr = parent;
            parent = (parent - 1) / 2;
        } else {
            break;
        }
        hList[curr] = temp;
    }
}
int MaxHeap::Max() const {
    if (heapSize == 0) {
        return -1;
    }
    return hList[0];
}

void MaxHeap::DeleteMax() {
    if (heapSize == 0) {
        return;
    }
    hList[0] = hList[heapSize - 1];
    heapSize--;
    FilterDown(0);
}

int MaxHeap::size() const {
    return heapSize;
}
