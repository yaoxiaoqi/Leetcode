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
private:
    
public:
    vector<int> preorder(Node* root) {
        vector<int> vals;
        stack<Node*> s;
        if (root) s.push(root);
        while(!s.empty()) {
            Node* cur = s.top();
            vals.push_back(cur->val);
            s.pop();
            auto it = cur->children.rbegin();
            auto end = cur->children.rend();
            for(;it != end;++it)
                s.push(*it);
        }
        return vals;
    }
};
