//
//  Parsing Message Format.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/9/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Parsing message format
 [ 4  ][  len  ][ 4  ][ len ][ 4  ][ len ]
 (len) (msg)    (len)

 4 + 10, 4 + 12, 4 + 20
 前4个byte代表后面紧接着的message的长度
 先把最前面的4个byte解析成integer，知道后面跟着的msg长度是多少（假设是10），那么就读后面紧接着的10个byte（是一个完整的msg）。
 然后再读4个byte，解析出长度（假设是12），就再度12个byte。
 ...
 当我们accept data的时候，假如我们每次读5byte，第一次读（读了5byte），不能解析；第二次读（迄今为止读了10byte），不能解析；第三次读（迄今为止读了15byte），这时候要解析了，因为上面的例子中最前面的第一个msg是14byte。
 拿到这个msg，就传给emit(msg)，解析，然后得到结果。
 直到传入的data array全部都读完，解析完。
 
 byte array for a stream of messages, the format is every 4 bytes determine the length of the message in byte, followed by the number of length of messages.

 void emit(byte[] msg); // 解析msg

 List<byte[]> accept(byte[] data) {
 
 }

 这种类型的题通常要记录上一次读到哪个位置

 */