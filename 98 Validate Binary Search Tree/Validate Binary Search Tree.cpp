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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        int prev_val = 0;
        bool isFirst = true;
        while (cur || !s.empty()) {
            if (cur) {
                s.push(cur);
                cur = cur -> left;
            } else {
                cur = s.top();
                if (!isFirst && cur->val <= prev_val) {
                    return false;
                } else {
                    prev_val = cur->val;
                    if (isFirst) {
                        isFirst = false;
                    }
                }
                cur = cur->right;
                s.pop();
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    TreeNode* t1 = new TreeNode(2);
    TreeNode* t2 = new TreeNode(1);
    TreeNode* t3 = new TreeNode(3);
    t1->left = t2;
    t1->right = t3;
    cout << s.isValidBST(t1) << endl;
    return 0;
}
