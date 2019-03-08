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
    TreeNode* merge(TreeNode* a, TreeNode* b) {
        if (a == NULL) return b;
        if (b == NULL) return a;
        a->right = merge(a->right, b);
        return a;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val == key) {
            return merge(root->left, root->right);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};

int main() {
//    Solution s;
//    TreeNode* t1 = new TreeNode(2);
//    TreeNode* t2 = new TreeNode(1);
//    TreeNode* t3 = new TreeNode(3);
//    t1->left = t2;
//    t1->right = t3;
//    cout << s.isValidBST(t1) << endl;
    return 0;
}
