//
//  Binary Search Tree Iterator.cpp
//  LaiOffer
//
//  Created by Fang Liu on 6/18/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

 Calling next() will return the next smallest number in the BST.

 Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 

 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();

 */

#include "Header.h"

/*
 I use Stack to store directed left children from root. When next() be called, I just pop one element and process its right child as new root. The code is pretty straightforward.

 So this can satisfy O(h) memory, hasNext() in O(1) time, But next() is O(h) time.

 I can't find a solution that can satisfy both next() in O(1) time, space in O(h).
 */
/*
 题目是构造BST数的升序的iterator，实质是树的中序遍历。
 题目中的第一个条件是O(h) memory，因为中序遍历的实现中，stack存的左节点，并且是从root开始到某点结束的左节点和结束点的右儿子的左后代的节点，着说明了stack的大小是O(h)的。
 题目中的第二个条件是，平均时间复杂度是O(1)。由于对整棵树的N个节点做了hasNext()调用之后，也就是说，一共做了N次调用之后，都只把整棵树的N个节点的每个节点遍历了1遍，所以N次调用的时间复杂度是O(N)，平均下来每次就是O(1)。同理对于Next()的调用。
 */
class BSTIterator {
private:
    stack<BinaryTreeNode*> myStack;
public:
    BSTIterator(BinaryTreeNode *root) {
        while(root){
            myStack.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        BinaryTreeNode* cur = myStack.top();
        BinaryTreeNode* return_cur = cur;
        myStack.pop();
        cur = cur->right;
        while(cur){
            myStack.push(cur);
            cur = cur->left;
        }
        return return_cur->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */