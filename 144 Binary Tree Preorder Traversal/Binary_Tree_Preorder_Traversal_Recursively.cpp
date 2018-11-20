//
//  main.cpp
//  Leetcode
//
//  Created by 妖小七 on 2018/11/7.
//  Copyright © 2018 妖小七. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> answer;
    void preorderTraversalRecursively(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        answer.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorderTraversalRecursively(root);
        return answer;
    }
};
