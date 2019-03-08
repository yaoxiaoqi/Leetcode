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

class BSTIterator {
private:
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        updateStack(root);
    }
    
    void updateStack(TreeNode* cur) {
        while(cur) {
            s.push(cur);
            cur = cur->left;
        }
        return;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* cur = s.top();
        s.pop();
        int res = cur->val;
        updateStack(cur->right);
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!s.empty());
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
