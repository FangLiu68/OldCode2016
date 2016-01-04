//
//  Is Palindrome Linke List.cpp
//  LaiOffer
//
//  Created by Fang Liu on 3/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

// Given a linked list, check whether it is a palindrome.
#include "Header.h"

/*
 1. use stack
 2. use recursion
 3. 1). mid node
 2). reverse second half
 3). …..
 4). reverse back second half and concatenate with first half.
 */


// method1: push first half to stack, then compare each top node with the right half list
// O(N) runtime, O(n/2) space
bool isPalindrome_iter(ListNode* head){
    if(head == NULL || head->next == NULL){
        return true;
    }

    // push first half into stack
    stack<int> stk;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        stk.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast){
        slow = slow->next;
    }
    while(!stk.empty()){
        if(stk.top() != slow->val){
            return false;
        }
        stk.pop();
        slow = slow->next;
    }
    return true;
}

//==================================================================
// O(N) time, O(1) space
// find mid node, reverse the second part, then compare the reversed half list with the first part
ListNode* helper_reverse(ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    ListNode* pre = NULL;
    ListNode* cur = head;
    while(cur){
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

bool isPalindrome(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return true;
    }

    // find mid node
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast) slow = slow->next;

    ListNode* newHead = helper_reverse(slow);
    while(newHead){
        if(head->val != newHead->val){
            return false;
        }
        newHead = newHead->next;
        head = head->next;
    }
    return true;
}


//==================================================================
// use recursion, time = O(N), space = O(1), and do not change the original input
/*
 level0     a → b → c → b → a
            l               r
 level 2    a → b → c → b → a
                l       r
 level 3    a → b → c → b → a
                   l/r
 level 4    a → b → c → b → a
                r       l
 level 5    a → b → c → b → a
            r               l
 left代表runner，right代表head
 head和runner起始点都在a的位置，每次递归head=head->next，那么head一直走到最右边节点的next(NULL)，返回true
 然后在每次返回上一层递归的过程中，比较runner和head的值是否相同
 注意在每次返回之前都要将runner往后移，而head不用管，因为head的上一层本来就是head左边的那个节点
 注意，当runner和head相遇时，两者仍然继续往前走，因为head的起始位置是最左边的头结点，recursion过后他必然要返回到最初的节点
 */
bool isPalin_helper(ListNode* head, ListNode*& runner);
bool isPalin_recur(ListNode* head){
    if(head == NULL){
        return false;
    }
    if(head->next == NULL){
        return true;
    }
    ListNode* runner = head;
    return isPalin_helper(head, runner);
}

// head是原始list最开始的节点，他是recursion部分的input,当head一直触底到最后一个节点时，反弹往前走，每次都和runner的值做比较
bool isPalin_helper(ListNode* head, ListNode*& runner){
    if(head == NULL){
        return true;
    }
    bool res = isPalin_helper(head->next, runner);

    // put logic judge here
    if(res == true && head->val == runner->val){
        runner = runner->next;
        return true;
    }else{
        return false;
    }
}

/*
// 1 2 3 2 1
int main(){
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(1);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    if(isPalin_recur(head)) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}*/