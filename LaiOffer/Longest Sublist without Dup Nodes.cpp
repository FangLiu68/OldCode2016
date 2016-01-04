//
//  Longest Sub List with No Dup Value.cpp
//  LaiOffer
//
//  Created by Fang Liu on 4/30/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 determine the longest sub list not containing duplicate values.

 1 -> 2 -> 3 -> 1 -> 4 -> null, longest is 2 -> 3 -> 1 -> 4

 array :  {1, 2, 3, 1, 4}, longest subarray not containing duplicate values. , ,,
 longest substring with no duplicate characters.
 */

#include "Header.h"
#include "LinkedList.h"


/*
 1. use a HashSet to store the values.
 2. slow, fast pointers: no duplicate values.
        when to move fast: if fast.val not in the HashSet
        when to move slow: if fast.val in the HashSet
 3. count: number of nodes between slow and fast. (count == set.size())
        fast++, count++
        slow++, count--
 4. result: max(count).
 */

int longest_substr_noDup(ListNode* head){
    if(head == NULL){
        return 0;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    int res = INT_MIN;
    // int count = 0; // count本来跟踪的是当前没有重复值的这段list的大小，但其实不必要，因为这个count和set.size()是一样的
    set<int> val;
    while(fast){
        if(val.find(fast->val) == val.end()){
            val.insert(fast->val);
            fast = fast->next;
            // count++;
        }else{
            val.erase(slow->val);
            slow = slow->next;
            //count--;
        }
        int cur_size = val.size();
        res = max(res, cur_size);
    }
    return res;
}
/*
int main(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(1);
    ListNode* node5 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    cout << longest_substr_noDup(node1) << endl;
    return 0;
}

*/

