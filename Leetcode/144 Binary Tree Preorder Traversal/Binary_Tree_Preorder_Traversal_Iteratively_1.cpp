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
        struct TreeNodePlus {
            TreeNode *node;
            int status;
            TreeNodePlus(TreeNode* t) : node(t), status(LEFT) {}
        };

        stack<TreeNodePlus*> nodes;
        TreeNodePlus* treeRoot = new TreeNodePlus(root);
        nodes.push(treeRoot);
        TreeNode* curNode = root;
        answer.push_back(curNode->val);
        while (true) {
            if (curNode == NULL) {
                break;
            }
            if (curNode -> left != NULL) {
                curNode = curNode -> left;
                TreeNodePlus* tmp = new TreeNodePlus(curNode);
                nodes.push(tmp);
                answer.push_back(curNode->val);
            } else if (curNode -> right != NULL) {
                nodes.top()->status = RIGHT;
                curNode = curNode -> right;
                TreeNodePlus* tmp = new TreeNodePlus(curNode);
                nodes.push(tmp);
                answer.push_back(curNode->val);
            } else {
                nodes.top()->status = RIGHT;
                while (true) {
                    if (nodes.top()->status == RIGHT) {
                        nodes.pop();
                        if (nodes.empty()) {
                            curNode = NULL;
                            break;
                        }
                    } else if (nodes.top()->status == LEFT) {
                        if (nodes.top()->node->right == NULL) {
                            nodes.top()->status = RIGHT;
                        } else {
                            nodes.top()->status = RIGHT;
                            curNode = nodes.top()->node->right;
                            TreeNodePlus* tmp = new TreeNodePlus(curNode);
                            nodes.push(tmp);
                            answer.push_back(curNode->val);
                            break;
                        }
                    }
                    
                }
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
