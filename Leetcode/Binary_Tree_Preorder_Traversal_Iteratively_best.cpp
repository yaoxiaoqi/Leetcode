//
//  main.cpp
//  Leetcode
//
//  Created by 妖小七 on 2018/11/7.
//  Copyright © 2018 妖小七. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define LEFT 1
#define RIGHT 2


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree {
public:
    TreeNode* load() {
//        TreeNode tree = TreeNode(1);
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        root->right = new TreeNode(6);
        root->right->left = new TreeNode(7);
        root->right->right = new TreeNode(8);
        return root;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        if (root == NULL) {
            return answer;
        }
        stack<TreeNode*> nodes;
        nodes.push(root);
        while (true) {
            if (nodes.empty()) {
                break;
            }
            
            TreeNode* tmp = nodes.top();
            answer.push_back(tmp->val);
            nodes.pop();
            if (tmp -> right != NULL) {
                nodes.push(tmp->right);
            }
            if (tmp->left != NULL) {
                nodes.push(tmp->left);
            }
        }
        return answer;
    }
};

int main() {
    BinaryTree b;
    Solution s;
    TreeNode* root = b.load();
    vector<int> answer = s.preorderTraversal(root);
    for (auto i : answer) {
        cout << i << " ";
    }
    cout << endl;
}
