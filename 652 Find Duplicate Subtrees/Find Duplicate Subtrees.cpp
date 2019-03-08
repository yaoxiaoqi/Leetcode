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
    unordered_map<string, int> treelist;
    vector<TreeNode*> ans;
    
    string DFS(TreeNode* root) {
        if (root == NULL) return "";
        string s = to_string(root->val) + "," + DFS(root->left) + "," + DFS(root->right);
        ++treelist[s];
        if (treelist[s] == 2) ans.push_back(root);
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if (root == NULL) return ans;
        DFS(root);
        return ans;
    }
};

int main() {
    Solution s;
    
    return 0;
}
