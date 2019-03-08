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
    vector<int> postorder(Node* root) {
        vector<int> vals;
        stack<Node*> s;
        if (root) s.push(root);
        while(!s.empty()) {
            Node* cur = s.top();
            vals.push_back(cur->val);
            s.pop();
            for (auto child : cur->children) {
                s.push(child);
            }
        }
        return {vals.rbegin(),vals.rend()};
    }
};
