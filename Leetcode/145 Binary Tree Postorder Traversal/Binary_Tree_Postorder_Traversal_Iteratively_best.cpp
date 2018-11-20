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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> answer;
        if (root == NULL) {
            return answer;
        }
        stack<TreeNode*> nodes;
        TreeNode* curNode;
        nodes.push(root);
        while (true) {
            if (nodes.empty()) {
                break;
            }
            curNode = nodes.top();
            answer.insert(answer.begin(), curNode->val);
            nodes.pop();
            if (curNode -> left != NULL) {
                nodes.push(curNode -> left);
            }
            if (curNode -> right != NULL) {
                nodes.push(curNode -> right);
            }
        }
        return answer;
    }
};
