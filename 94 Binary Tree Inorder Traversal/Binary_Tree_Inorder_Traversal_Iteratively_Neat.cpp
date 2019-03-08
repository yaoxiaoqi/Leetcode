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
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        stack<TreeNode*> nodes;
        TreeNode* cur = root;
        while (!nodes.empty() || cur) {
            if (cur) {
                nodes.push(cur);
                cur = cur->left;
            } else {
                cur = nodes.top();
                answer.push_back(cur->val);
                cur = cur->right;
                nodes.pop();
            }
        }
        return answer;
    }
};

int main() {
    Solution s;
    return 0;
}
