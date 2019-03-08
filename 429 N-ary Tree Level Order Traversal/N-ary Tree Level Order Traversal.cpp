/*
 // Definition for a Node.
 class Node {
 public:
     int val;
     vector<Node*> children;
 
     Node() {}
 
     Node(int _val, vector<Node*> _children) {
     val = _val;
     children = _children;
 }
 };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<Node*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            ans.push_back({});
            int tmp = q.size();
            for (int i = 0; i < tmp; i++) {
                Node* cur = q.front();
                ans[level].push_back(cur->val);
                q.pop();
                for (auto child:cur->children) {
                    q.push(child);
                }
            }
            ++level;
        }
        return ans;
    }
};
