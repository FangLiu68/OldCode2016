//
//  Singleton.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/8/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 Singleton Class

 The singleton patton ensures that a class has only one instance and ensures access to the instance through the application. It can be useful in cases where you have a "global" object with exactly one instance. (only one object instantiation during program execution)
 For example, we may want to implement Restaurant such that it has exactly one instance of Restaurant.
 */

/*
class Singleton{
private:
    Singleton();
    static Singleton* instance;
public:
    static Singleton* getInstance();
};

Singleton* Singleton::instance = NULL;
Singleton* Singleton::getInstance(){
    if(instance == NULL){
        instance = new Singleton();
    }
    return instance;
}*/
/*
class singleton{
private:
    singleton();
    static singleton* instance;
public:
    static singleton* getInstance();
};

singleton* singleton::instance = NULL;
singleton* singleton::getInstance(){
    if(instance == NULL){
        instance = new singleton();
    }
    return instance;
}*/

