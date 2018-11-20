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
private:
    vector<int> answer;
public:
    void inorderTraversalRecursively(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorderTraversalRecursively(root->left);
        answer.push_back(root->val);
        inorderTraversalRecursively(root->right);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorderTraversalRecursively(root);
        return answer;
    }
};
