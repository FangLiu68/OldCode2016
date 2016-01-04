//
//  Templates Use.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/22/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 Templates are a feature that allows functions and classes to operate with generic types. This allows a function or class to work on many different data types without being rewritten for each one.
 Templates are a way of reusing code to apply the same class to different data types. For example, we might have a list-like data structure which we would like to use for lists of various types.
 */

template <class T>

class ShiftedList{
private:
    T* array;
    int offset, size;
public:
    ShiftedList(int sz) : offset(0), size(sz){
        array = new T[size];
    }

    ~ShiftedList(){
        delete[] array;
    }

    void shiftBy(int n){
        offset = (offset + n) % size;
    }

    T getAt(int i){
        return array[convertIndex(i)];
    }

    void setAt(T item, int i){
        array[convertIndex(i)] = item;
    }

private:
    int convertIndex(int i){
        int index = (i - offset) % size;
        while(index < 0){
            index += size;
        }
        return index;
    }
};

/*
int main(){
    int size = 4;
    ShiftedList<int>* list = new ShiftedList<int>(size);
    for(int i=0; i<size; ++i){
        list->setAt(i, i);
    }
    cout << list->getAt(0) << endl;
    cout << list->getAt(1) << endl;
    list->shiftBy(1);
    cout << list->getAt(0) << endl;
    cout << list->getAt(1) << endl;
    delete list;
}*/