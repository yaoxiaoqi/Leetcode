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

#define LEFT 1
#define RIGHT 2

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        if (root == NULL) {
            return answer;
        }
        struct TreeNodePlus {
            TreeNode *node;
            int status;
            TreeNodePlus(TreeNode* t) : node(t), status(LEFT) {}
        };
        
        stack<TreeNodePlus*> nodes;
        TreeNodePlus* treeRoot = new TreeNodePlus(root);
        nodes.push(treeRoot);
        TreeNode* curNode = root;
        while (true) {
            if (curNode == NULL) {
                break;
            }
            if (curNode -> left != NULL) {
                curNode = curNode -> left;
                TreeNodePlus* tmp = new TreeNodePlus(curNode);
                nodes.push(tmp);
            } else if (curNode -> right != NULL) {
                nodes.top()->status = RIGHT;
                answer.push_back(curNode->val);
                curNode = curNode -> right;
                TreeNodePlus* tmp = new TreeNodePlus(curNode);
                nodes.push(tmp);
            } else {
                nodes.top()->status = RIGHT;
                answer.push_back(curNode->val);
                while (true) {
                    if (nodes.top()->status == RIGHT) {
                        nodes.pop();
                        if (nodes.empty()) {
                            curNode = NULL;
                            break;
                        }
                    } else if (nodes.top()->status == LEFT) {
                        if (nodes.top()->node->right == NULL) {
                            nodes.top()->status = RIGHT;
                            answer.push_back(nodes.top()->node->val);
                        } else {
                            nodes.top()->status = RIGHT;
                            answer.push_back(nodes.top()->node->val);
                            curNode = nodes.top()->node->right;
                            TreeNodePlus* tmp = new TreeNodePlus(curNode);
                            nodes.push(tmp);
                            break;
                        }
                    }
                    
                }
            }
        }
        return answer;
    }
};
