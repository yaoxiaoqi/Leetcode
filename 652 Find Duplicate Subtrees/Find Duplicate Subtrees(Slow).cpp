//
//  main.cpp
//  Leetcode
//
//  Created by 妖小七 on 2018/11/23.
//  Copyright © 2018 妖小七. All rights reserved.
//

#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<string, vector<TreeNode*>> treelist;
    
    string nodeToString(const TreeNode* node) {
        if (node == NULL) {
            return "null";
        }
        return to_string(node->val);
    }
    
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "";
        }
        queue<TreeNode*> nodes;
        string result = "";
        result += nodeToString(root) + ",";
        nodes.push(root);
        while(true) {
            if (nodes.size() <= 0) {
                break;
            }
            TreeNode* tmp = nodes.front();
            result += nodeToString(tmp->left) + ",";
            result += nodeToString(tmp->right) + ",";
            if (tmp->left) nodes.push(tmp->left);
            if (tmp->right) nodes.push(tmp->right);
            nodes.pop();
        }
        return result;
    }
    
    void traverseTreeNode(TreeNode* root) {
        if (root == NULL) return;
        string key = "";
        key = serialize(root);
        if (treelist.count(key) <= 0) {
            treelist[key] = {};
        }
        treelist[key].push_back(root);
        traverseTreeNode(root->left);
        traverseTreeNode(root->right);
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        if (root == NULL) return ans;
        traverseTreeNode(root->left);
        traverseTreeNode(root->right);
        for (auto it = treelist.begin(); it != treelist.end(); it++) {
            if (it->second.size() > 1) ans.push_back(it->second[0]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    
    return 0;
}
