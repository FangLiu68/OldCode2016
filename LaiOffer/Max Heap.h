//
//  Max Heap.h
//  LaiOffer
//
//  Created by Fang Liu on 4/8/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#ifndef __LaiOffer__Max_Heap__
#define __LaiOffer__Max_Heap__

#include <queue>

// max_heap.h
class MaxHeap {
public:
    MaxHeap(int* input, int size);
    int Max() const;      // O(1).
    void Insert(int value);
    void DeleteMax();
    int size() const;
private:
    int maxHeapSize;
    int* hList;
    int heapSize;
    void FilterDown(int index);
    void FilterUp(int index);
};


#endif /* defined(__LaiOffer__Max_Heap__) */
