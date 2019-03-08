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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        vector<bool> used(n, 0);
        return helper(used, 0, n-1);
    }
    vector<TreeNode*> helper(vector<bool>& used, int min, int max) {
        vector<TreeNode*> result;
        if (min > max) {
            return { NULL };
        }
        if (min == max) {
            TreeNode* tmp = new TreeNode(min+1);
            result.push_back(tmp);
            return result;
        }
        for (int i = min; i <= max; i++) {
            if (used[i]) continue;
            used[i] = 1;
            vector<TreeNode*> leftTrees = helper(used, min, i-1);
            vector<TreeNode*> rightTrees = helper(used, i+1, max);
            for (auto lt: leftTrees) {
                for (auto rt: rightTrees) {
                    TreeNode* tmp = new TreeNode(i+1);
                    tmp->left = lt;
                    tmp->right = rt;
                    result.push_back(tmp);
                }
            }
            used[i] = 0;
        }
        return result;
    }
};
