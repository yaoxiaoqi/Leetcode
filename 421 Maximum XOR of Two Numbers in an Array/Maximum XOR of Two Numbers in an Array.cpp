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

#define BIT 31

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) {
        val = v;
        left = right = NULL;
    }
};

class Solution {
public:
    TreeNode* root = new TreeNode(-1);
    
    void initialize(vector<int>& nums) {
        // initialize Binary Tree
        for (auto num: nums) {
            vector<int> bits(BIT, 0);
            int index = BIT-1;
            while(num > 0) {
                bits[index--] = num % 2;
                num = num / 2;
            }
            
            TreeNode* cur = root;
            for (auto bit: bits) {
                if (bit) {
                    if (!cur->right) {
                        cur->right = new TreeNode(1);
                    }
                    cur = cur->right;
                } else {
                    if (!cur->left) {
                        cur->left = new TreeNode(0);
                    }
                    cur = cur->left;
                }
            }
        }
        return;
    }
    
    int findXOR(TreeNode* left, TreeNode* right, int exp) {
        // return 0 if reached the leaf nodes
        if (exp == -1) {
            return 0;
        }
        
        if (left && right) {
            int current_ans = 0;
            if (left->val != right->val) {
                current_ans = 1 << exp;
            }
            if (left->left && left->right && right->left && right->right) {
                return current_ans + max(findXOR(left->left, right->right, exp-1), findXOR(right->left, left->right, exp-1));
            } else if (left->left && right->right) {
                return current_ans + findXOR(left->left, right->right, exp-1);
            } else if (left->right && right->left) {
                return current_ans + findXOR(right->left, left->right, exp-1);
            } else if (left->left && right->left) {
                return current_ans + findXOR(left->left, right->left, exp-1);
            } else if (left->right && right->right) {
                return current_ans + findXOR(left->right, right->right, exp-1);
            } else {
                return current_ans;
            }
        } else if (left) {
            return findXOR(left->left, left->right, exp-1);
        } else if (right) {
            return findXOR(right->left, right->right, exp-1);
        }
        return 0;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        initialize(nums);
        return findXOR(root->left, root->right, BIT-1);
    }
};

int main() {
    Solution s;
    vector<int> a = {3, 10, 5, 25, 2, 8};
    cout << s.findMaximumXOR(a) << endl;
    return 0;
}
