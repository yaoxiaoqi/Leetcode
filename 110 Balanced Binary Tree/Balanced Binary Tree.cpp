/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Result {
public:
    int left_len;
    int right_len;
    bool isBalanced;
    Result(int l, int r, bool i): left_len(l), right_len(r), isBalanced(i) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        Result res = helper(root);
        return res.isBalanced;
    }
    
    Result helper(TreeNode* root) {
        if (root == NULL) return Result(-1,-1, true);
        if (root->left == NULL && root->right == NULL) return Result(0,0,true);
        Result res1 = helper(root->left);
        Result res2 = helper(root->right);
        if (!res1.isBalanced || !res2.isBalanced) return Result(0,0,false);
        int l = max(res1.left_len, res1.right_len)+1;
        int r = max(res2.left_len, res2.right_len)+1;
        if (abs(l-r) > 1) return Result(0,0,false);
        else return Result(l,r,true);
    }
};
