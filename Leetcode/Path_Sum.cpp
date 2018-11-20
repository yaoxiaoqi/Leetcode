/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool fg = false;
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }
        return hasPathSumTD(root, 0, sum);
    }
    bool hasPathSumTD(TreeNode* root, int cur_sum, int sum) {
        bool flag = false;
        if (root == NULL) {
            if (cur_sum == sum) {
                flag = true;
            }
            return flag;
        }
        cur_sum += root->val;
        bool tmp1 = hasPathSumTD(root->left, cur_sum, sum);
        bool tmp2 = hasPathSumTD(root->right, cur_sum, sum);
        if (tmp1 && (tmp1 == tmp2)) {
            fg = true;
        }
        return fg;
    }
};
