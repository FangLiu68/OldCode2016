//
//  Read 4096 Bytes.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/8/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// sequentially read one file.
// guarantee the buffer size = 4096
// return actually how many bytes read.

#include "assert.h"
#include <iostream>
using namespace std;

/*
int read4096(int buffer[], int size) {
    assert (size == 4096);
}

//  1. read first k bytes of the file
//  2. call read4096 to implement this read method.

int read(int buffer[],int size, int k) {
    assert (size == k);
    int len = 0;
    int buff4read[];
    while (len < k) {
        int readLen = read4096(buff4read);
        readLen = readLen  < k- len ? readLen : k - len;
        copy(buff, buff4read, len, readLen);
        len += readLen;
        if (readLen != 4096) break;
    }
    return len;
}
*/

/*
 Repeatedly called read k

 class FileReader4K {
 public FileReader4K(File file) {
 // constructor.
 }

 // this is actually read4096 and you can call this consecutively
 // to traverse down the whole file.
 public int read(int[] buffer) {
 //…...
 }
 }

 class FileReader {
 FileReader4096 reader4096;
 char[] buff4096;
 int leftLen; // 记录剩下多少长度
 public FileReader(File file) {
 this.reader4096 = new FileReader4096(file);
 this.buff4096 = new char[4096];
 this.leftLen = 0;
 }

 // use the reader4096’s read method and this method can also be called consecutively to
 // traverse the whole file.
 public int read(int[] buffer, int k) {
 assert buffer.length == k;
	int len = 0;
 if (leftLen > 0) {
 if (leftLen >= k) {
 copy(buff4096.begin(), buff4096.begin() + k, buffer);
 leftLen -= k;
 copy(buff4096.begin() + k, buff4096.end(), buff4096.begin());
	return k;
 } else {
 copy(buff4096.begin(), buff4096.begin() + k, buffer);
 }
 
 
 保证在进入while之前leftLen为0，while里面需要读的是k-leftLen
 while (len < k) {
	int readLen = read4096(buff4read);
	readLen = readLen  < k- len ? readLen : k - len;
 copy(buff, buff4read, len, readLen);
	len += readLen;
 if (read多了) 就copy 到buff4096里面，更新leftLen;
 if (readLen != 4096) break;
 }
 return len;
 }
 }

 */

/*
Repeatedly called read k

class FileReader4K {
    public FileReader4K(File file) {
        // constructor.
    }

    // this is actually read4096 and you can call this consecutively
    // to traverse down the whole file.
    public int read(int[] buffer) {
        //…...
    }
}

class FileReader {
    FileReader4096 reader4096;
    char[] buff4096;
    int leftLen;
    public FileReader(File file) {
        this.reader4096 = new FileReader4096(file);
        this.buff4096 = new char[4096];
        this.leftLen = 0;
    }

    // use the reader4096’s read method and this method can also be called consecutively to
    // traverse the whole file.
    public int read(int[] buffer, int k) {
        assert buffer.length == k;
        int len = 0;
        if (leftLen > 0) {
            if (leftLen >= k) {
                copy(buff4096.begin(), buff4096.begin() + k, buffer);
                leftLen -= k;
                copy(buff4096.begin() + k, buff4096.end(), buff4096.begin());
                return k;
            } else {
                copy(buff4096.begin(), buff4096.begin() + k, buffer);

                while (len < k) {
                    int readLen = read4096(buff4read);
                    readLen = readLen  < k- len ? readLen : k - len;
                    copy(buff, buff4read, len, readLen);
                    len += readLen;
                    if (read多了) 就copy 到buff4096里面，更新leftLen;
                    if (readLen != 4096) break;
                }
                return len;
            }
        }
*/