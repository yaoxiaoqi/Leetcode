//
//  main.cpp
//  Leetcode
//
//  Created by 妖小七 on 2018/11/23.
//  Copyright © 2018 妖小七. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

/**
 * Definition for binary tree with next pointer.
*/
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class BinaryTree {
public:
    TreeLinkNode* load() {
        //        TreeNode tree = TreeNode(1);
        TreeLinkNode* root = new TreeLinkNode(1);
        root->left = new TreeLinkNode(4);
        root->left->left = new TreeLinkNode(3);
        root->left->right = new TreeLinkNode(5);
        root->right = new TreeLinkNode(6);
        root->right->left = new TreeLinkNode(7);
        root->right->right = new TreeLinkNode(8);
        return root;
    }
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return;
        }
        if (root->left != NULL && root->right != NULL) {
            root->left->next = root->right;
            if (root->next != NULL) {
                root->right->next = root->next->left;
            }
        }
        connect(root->left);
        connect(root->right);
    }
};

int main() {
    Solution s;
    BinaryTree b;
    TreeLinkNode* root = b.load();
    s.connect(root);
    cout << root->left->right->next->val << endl;
    return 0;
}
