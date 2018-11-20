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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return a(root->left, root->right);
    }
    
    bool a(TreeNode* curNode, TreeNode* mirrorNode) {
        if (curNode == NULL && mirrorNode == NULL) {
            return true;
        } else if (curNode == NULL || mirrorNode == NULL) {
            return false;
        } else if (curNode->left == NULL && curNode->right == NULL && mirrorNode->left == NULL && mirrorNode -> right == NULL) {
            if (curNode->val == mirrorNode->val) {
                return true;
            }
        }
        if (curNode->val == mirrorNode->val) {
            return a(curNode->left, mirrorNode->right) && a(curNode->right, mirrorNode->left);
        }
        return false;
    }
};
