//
//  Virtual Function.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/22/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//


/*
 Virtual function: 
 When derived class overrides the base class method by redefining the same function, and we can use a pointer from base class object to access the redefined method from derived class, the function in base class is called virtual function.
 
 How virtual function works
 A virtual function depends on a virtual table. If any function of a class is declared to be virtual, a virtual table is constructed which stores addresses of the virtual functions of this class.
 1. every class that uses virtual functions (or is derived from a class that uses virtual functions) is given it’s own virtual table. The table is a static array that the compiler sets up at compile time.
 A virtual table contains one entry for each virtual function that can be called by objects of the class. Each entry in this table is a function pointer that points to the most-derived function accessible by that class.
 2. the compiler adds a hidden virtual pointer to the base class. The virtual pointer is set automatically when a class instance is created so that it points to the virtual table for that class. And the important thing is virtual pointer is inherited by derived classes.
 */

#include <string>
#include <unordered_map>
#include "assert.h"
#include <iostream>
using namespace std;

struct BookStore{
    int id;
    int zip;
    string name;
    string city;
    string state;
    string category;
    BookStore(int _id, int _zip, string _name, string _city, string _state, string _category) :
        id(_id), zip(_zip), name(_name), city(_city), state(_state), category(_category) {}
};

void print_name(BookStore input[], int n){
    if(input == NULL){
        return;
    }
    for(int i = 0; i < n; ++i){
        cout << input[i].name << endl;
    }
    cout << endl;
}

// 2b. Write an automated test to verify this method works.  Assume invalid input is not supported.
void testPrintName(){
    BookStore BS1(1, 01, "book_store1", "city1", "state1", "book stores");
    BookStore BS2(2, 02, "book_store2", "city2", "state2", "book stores");
    BookStore BS3(3, 03, "book_store3", "city3", "state3", "book stores");
    BookStore BS4(4, 04, "book_store4", "city4", "state4", "book stores");
    BookStore BS5(5, 05, "book_store5", "city5", "state5", "book stores");

    cout << "// test case1:" << endl;
    BookStore a[] = {};
    int len_a = sizeof(a) / sizeof(BookStore);
    print_name(a, len_a);

    cout << "// test case2:" << endl;
    BookStore b[] = {BS1};
    int len_b = sizeof(b) / sizeof(BookStore);
    print_name(b, len_b);

    cout << "// test case3:" << endl;
    BookStore c[] = {BS1, BS2, BS3};
    int len_c = sizeof(c) / sizeof(BookStore);
    print_name(c, len_c);

    cout << "// test case4:" << endl;
    BookStore d[] = {BS1, BS2, BS3, BS4, BS5};
    int len_d = sizeof(d) / sizeof(BookStore);
    print_name(d, len_d);
}

// 2c. Write an automated test to verify that any @book_stores object does not contain any duplicate book store names
void testDupNames(BookStore input[], int n){
    if(input == NULL){
        throw "Invalid Input";
    }

    // put all BookStore's names into map.
    // key:name, value:how many times the name appears
    unordered_map<string, int> name_count;
    for(int i = 0; i < n; ++i){
        if(name_count.find(input[i].name) == name_count.end()){
            name_count[input[i].name] = 1;
        }else{
            name_count[input[i].name]++;
        }
    }

    // assert each name only appear onece
    for(unordered_map<string, int>::iterator IT = name_count.begin(); IT != name_count.end(); ++IT){
        assert(IT->second == 1);
    }
}
/*
int main(){
   // testPrintName();

    BookStore BS1(1, 01, "book_store1", "city1", "state1", "book stores");
    BookStore BS2(2, 02, "book_store2", "city2", "state2", "book stores");
    BookStore BS3(3, 03, "book_store3", "city3", "state3", "book stores");
    BookStore BS4(4, 04, "book_store4", "city4", "state4", "book stores");
    BookStore BS5(5, 05, "book_store5", "city5", "state5", "book stores");
    BookStore d[] = {BS1, BS2, BS3, BS4, BS5};
    int len_d = sizeof(d) / sizeof(BookStore);
    testDupNames(d, len_d);
    return 0;
}*/