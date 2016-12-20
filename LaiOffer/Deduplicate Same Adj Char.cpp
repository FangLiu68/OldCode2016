//
//  Deduplicate Same Adj Char.cpp
//  LaiOffer
//
//  Created by Fang Liu on 1/21/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Repeatedly remove all adjacent, repeated characters in a given string from left to right.
 No adjacent characters should be identified in the final string.

 Examples
 "abbbaaccz" → "aaaccz" → "ccz" → "z"
 "aabccdc" → "bccdc" → "bdc"
 */

#include <string>
#include <stack>
#include <iostream>
using namespace std;

/*
 0 1 2 3 4 5 6 7
 a b b b b a z x → abbbbaz x → zx
 Use a stack to store the last letter that is known (so far) to be non-duplicated.
 i = 0,  push stack → ||a
 i = 1,  push stack → ||a b
 i = 2,  b == stack.top() :i++  || a b
 i = 3,  b == stack.top() :i++  || a b
 i = 4,  b == stack.top() :i++  || a b
 i = 5,  a != stack.top().   pop stack (b is out ),
         a == stack.top(). i++  || a,
 i = 6,  z != stack.top()   pop stack (a is out). z is in the stack.
 i = 7,
 output == (keep popping all letters out of the stack and reverse the order.)
 */

string deduplicate_same_adjacent_chars(string s){
    string res;
    if(s.empty()) return res;

    stack<char> stk;
    stk.push(s[0]);

    int index_cur = 1;

    // cur是还没有放入stack的，即将检查的下一个char
    while(index_cur < s.size()){
        char cur = s[index_cur];

        // 一定要先把size check放在前面
        if(stk.size() > 0 && cur == stk.top()){
            while(index_cur < s.size() && cur == s[index_cur])
                index_cur++;
            stk.pop();
        }
        else{
            stk.push(s[index_cur]);
            index_cur++;
        }
    }

    while(!stk.empty()){
        res = res + stk.top();
        stk.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
/*
int main(){
    string str = "abbbacd";
    string res = deduplicate_same_adjacent_chars(str);
    cout << res << endl;
    return 0;
}*/