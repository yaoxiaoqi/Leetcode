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
        return top_down(root, NULL, NULL);
    }
    
    bool top_down(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == NULL)
            return true;
        if (min && root->val <= min->val) return false;
        if (max && root->val >= max->val) return false;
        return top_down(root->left, min, root) && top_down(root->right, root, max);
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
