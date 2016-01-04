//
//  print All Paths Any Node to Any Node.cpp
//  LaiOffer
//
//  Created by Fang Liu on 7/5/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 You are given a binary tree in which each node contains a value. 
 Design an algorithm to print all paths which sum to a given value.
 the path does not need to start or end at the root or a leaf.
 */

#include "Header.h"

// 起点是root，终点是leaf
void helper_pathSumI(vector<vector<int>>& res, int target, BinaryTreeNode* root, vector<int> cur){
    if(root == NULL){
        return ;
    }

    cur.push_back(root->val);

    // 走到叶子节点时
    if(root->left == NULL && root->right == NULL){
        int curSum = 0;

        // 从root一直加到叶子节点
        for(int i = 0; i < cur.size(); ++i){
            curSum = curSum + cur[i];
        }

        if(curSum == target){
            res.push_back(cur);
        }
    }

    helper_pathSumI(res, target, root->left, cur);
    helper_pathSumI(res, target, root->right, cur);
    cur.pop_back();
}

vector<vector<int>> allPathSumToTargetI(BinaryTreeNode* root, int target){
    vector<vector<int>> res;
    if(root == NULL){
        return res;
    }
    vector<int> cur;
    helper_pathSumI(res, target, root, cur);
    return res;
}

//=============================================================
// 起点是root，终点是在root-leaf路径上任意点
void helper_pathSumII(vector<vector<int>>& res, int target, BinaryTreeNode* root, vector<int> cur){
    if(root == NULL){
        return ;
    }

    cur.push_back(root->val);
    int curSum = 0;

    // 从root一直加到当前节点
    for(int i = 0; i < cur.size(); ++i){
        curSum = curSum + cur[i];

    }

    if(curSum == target){
        res.push_back(cur);
    }

    helper_pathSumII(res, target, root->left, cur);
    helper_pathSumII(res, target, root->right, cur);

    cur.pop_back();
}

vector<vector<int>> allPathSumToTargetII(BinaryTreeNode* root, int target){
    vector<vector<int>> res;
    if(root == NULL){
        return res;
    }
    vector<int> cur;
    helper_pathSumII(res, target, root, cur);
    return res;
}


//=====================================================
// 起点和终点可以是任何节点，但必须是在root-leaf这条路上
void helper_PathSumIII(vector<vector<int>>& res, int target, BinaryTreeNode* root, vector<int>& cur){
    if(root == NULL){
        return;
    }

    int curSum = 0;
    cur.push_back(root->val);

    vector<int> tmp;

    // 从当前节点往回看这条路径，反方向加到任意节点，check是否和target相同（这里要反方向加）
    for(int i = cur.size()-1; i >= 0; --i){
        tmp.push_back(cur[i]);
        curSum = curSum + cur[i];
        if(curSum == target){
            res.push_back(tmp);
        }
    }

    helper_PathSumIII(res, target, root->left, cur);
    helper_PathSumIII(res, target, root->right, cur);

    cur.pop_back();
}

vector<vector<int>> allPathSumToTargetIII(BinaryTreeNode* root, int target){
    vector<vector<int>> res;
    if(root == NULL){
        return res;
    }
    vector<int> cur;
    helper_PathSumIII(res, target, root, cur);
    return res;
}


/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(-5);
    BinaryTreeNode* node4 = new BinaryTreeNode(4);
    BinaryTreeNode* node5 = new BinaryTreeNode(5);
    BinaryTreeNode* node7 = new BinaryTreeNode(7);
    BinaryTreeNode* node2 = new BinaryTreeNode(2);
    BinaryTreeNode* node6 = new BinaryTreeNode(6);
    BinaryTreeNode* node8 = new BinaryTreeNode(-8);
    BinaryTreeNode* node3 = new BinaryTreeNode(3);

    root->left = node4;
    root->right = node5;
    node4->left = node7;
    node4->right = node2;
    node5->right = node6;
    node7->left = node8;
    node8->left = node3;

    BinaryTreeNode* root1 = new BinaryTreeNode(2);
    BinaryTreeNode* _node3 = new BinaryTreeNode(3);
    BinaryTreeNode* _node4 = new BinaryTreeNode(-4);
    BinaryTreeNode* _node5 = new BinaryTreeNode(-2);
    BinaryTreeNode* _node6 = new BinaryTreeNode(6);
    root1->left = _node3;
    _node3->left = _node4;
    _node4->left = _node5;
    _node5->left = _node6;

    vector<vector<int>> res = allPathSumToTargetII(root1, 5);
    if(res.empty()) cout << "NO" << endl;
    else{
        for(int i=0; i<res.size(); ++i){
            vector<int> cur = res[i];
            for(int j=0; j<cur.size(); ++j){
                cout << cur[j] << " ";
            }cout << endl;
        }
    }

    return 0;
}
*/


