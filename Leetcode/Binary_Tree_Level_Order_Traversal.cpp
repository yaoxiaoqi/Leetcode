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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        if (root == NULL) {
            return levels;
        }
        queue<TreeNode*> nodes;
        TreeNode* curNode;
        nodes.push(root);
        while(!nodes.empty()) {
            vector<int> tmp;
            int num = int(nodes.size());
            for (int i = 0; i<num;i++) {
                curNode = nodes.front();
                nodes.pop();
                tmp.push_back(curNode->val);
                if (curNode->left != NULL) {
                    nodes.push(curNode->left);
                }
                if (curNode->right != NULL) {
                    nodes.push(curNode->right);
                }
            }
            levels.push_back(tmp);
        }
        return levels;
    }
};
