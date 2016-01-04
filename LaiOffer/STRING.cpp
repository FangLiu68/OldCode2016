//
//  STRING.cpp
//  LaiOffer
//
//  Created by Fang Liu on 5/1/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//
#include <iostream>
using namespace std;

class String{
private:
    char* buf;
    int buf_len;
public:
    String();
    String(const String& s);
    String(const char* s);
    String& operator=(const String& s);
    virtual ~String();

};

String::String():buf(0), buf_len(0){}

String::String(const char* s){
    buf_len = strlen(s) + 1;
    buf = new char[buf_len];
    strncpy(buf, s, buf_len-1);
}

String::~String(){
    if(buf){
        delete[] buf;
        buf = 0;
    }
}
/*
String& operator=(const String& s){

}*/
/*
int main(){
    char a[4] = "123";
    cout << sizeof(a) << endl;
    return 0;
}*/