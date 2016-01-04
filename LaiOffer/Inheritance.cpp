//
//  Inheritance.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/22/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//


/*
 Definition
 Inheritance is a form of software reusability. New classes are created from existing classes by absorbing their attributes and operation, then overriding these with capabilities new classes require, therefore enhance the new capabilities.

 What a derived class inherits:
 Every data member defined in the parent class and every ordinary member functions of the parent class.
 
 What a derived class doesn't Inherit:
 The base class's constructors, destructor, assignment operator, friends.
 */

#include <iostream>
#include <string>
using namespace std;

#define NAME_SIZE 50 // define a macro

class Person{
    int id; // all members are private by default
    char name[NAME_SIZE];
public:
    Person(){};
    virtual ~Person(){
        cout << "delete a person" << endl;
    }
    virtual void aboutMe(){
        cout << "I'm a person." << endl;
    }
    virtual bool addCourse(string s) = 0;
};

class Student : public Person{
public:
    ~Student(){
        cout << "delete a student" << endl;
    }
    void aboutMe(){
        cout << "I'm a student." << endl;
    }
    bool addCourse(string s){
        cout << "add course " << s << " to student" << endl;
        return true;
    }
};
/*
int main(){
    Student* p = new Student();
    p->aboutMe(); // print "I'm a student"

    Person* q = new Student();
    q->aboutMe(); // print "I'm a person", because aboutMe is resolved at compile-time, which is static binding

    q->addCourse("history");

    delete p; cout << endl << endl;
    delete q;
    return 0;
}*/