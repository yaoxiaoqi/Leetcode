/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stack>

using namespace std;


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        stack<TreeNode*> nodes;
        TreeNode* curNode = root;
        while (true) {
            if (curNode || !nodes.empty()) {
                if(curNode) {
                    nodes.push(curNode);
                    curNode = curNode -> left;
                } else {
                    TreeNode* tmp = nodes.top();
                    answer.push_back(tmp->val);
                    nodes.pop();
                    curNode = tmp -> right;
                }
            } else {
                break;
            }
        }
        return answer;
    }
};
