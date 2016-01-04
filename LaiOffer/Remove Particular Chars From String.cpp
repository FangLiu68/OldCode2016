//
//  Remove Particular Chars From String.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/24/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Remove a/some particular chars from a string.
// Example: string input = "student", remove "u and n" --> output: "stdet"

#include <string>
#include <iostream>
using namespace std;

/*
 快慢指针(挡板)，同向而行：     i = slow; j = fast
 Only thing to do: if char should not be removed, then call move(s[j], s[i]) to move s[j] to s[i]

 initialization (2个挡板，3个区域，同向而行):
 i = 0: all letters to the left-hand side of i (not including i) are all processed letters that should not be removed (slow);
 j = 0: j is the current index to move (fast).
        all letters in [i, j] are all area that we do not care (empty space xxx).
 (j, size-1]      (unknown area to explore);
 */
// 确定的是，任何时候slow的左边（不包括slow在内的元素）都是满足要求的元素
// 所以当循环结束后，slow的右边（包括slow在内的元素）都是多余的，需要删掉
void removeChar(string& input, char a){
    if(input.empty()) return;
    int slow = 0;
    int fast = 0;
    while(fast < input.size()){
        if(input[fast] != a){
            input[slow++] = input[fast++];
        }else{
            fast++;
        }
    }
    // earase(t1,t2)表示删除从iterator t1指向的元素一直到iterator t2指向的元素，包括t1 不包括t2
    //input.erase(input.begin()+slow, input.end());
    // 或者用resize，只去前slow个字符
    input.resize(slow);
}

// 如果我们想要返回string，而不是在原input上修改，那么可以直接用substr
string removeCharI(string input, char a){
    if(input.empty()) return "";
    int slow = 0;
    int fast = 0;
    while(fast < input.size()){
        if(input[fast] != a){
            input[slow++] = input[fast++];
        }else{
            fast++;
        }
    }
    // substr(index, len) 表示从index开始（包括index）取substr一直取len的长度
    return input.substr(0, slow); // slow从0开始，结束后在需要结果的后面一个字符的位置，大小正好  不用-1
}
/*
int main(){
    string input = "12345";
    char a = '2';
    removeChar(input, a);
    //string res = removeCharI(input, a);
    cout << input << endl;
    return 0;
}*/