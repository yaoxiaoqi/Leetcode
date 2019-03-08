//
//  main.cpp
//  Leetcode
//
//  Created by 妖小七 on 2018/11/23.
//  Copyright © 2018 妖小七. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <regex>

using namespace std;

/**
 * Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    void buildNode(TreeNode* &node, string value) {
        if (value == "null") {
            node = NULL;
        } else {
            node = new TreeNode(stoi(value));
        }
        return;
    }
    string nodeToString(const TreeNode* node) {
        if (node == NULL) {
            return "null";
        }
        return to_string(node->val);
    }
    
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "";
        }
        queue<TreeNode*> nodes;
        string result = "";
        result += nodeToString(root) + ",";
        nodes.push(root);
        while(true) {
            if (nodes.size() <= 0) {
                break;
            }
            TreeNode* tmp = nodes.front();
            result += nodeToString(tmp->left) + ",";
            result += nodeToString(tmp->right) + ",";
            if (tmp->left) nodes.push(tmp->left);
            if (tmp->right) nodes.push(tmp->right);
            nodes.pop();
        }
        return result;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string tmp = "";
        TreeNode* root = NULL;
        queue<TreeNode*> nodes;
        bool isRoot = true;
        bool hasLeft = false;
        for (auto i: data) {
            if (i == ',') {
                if (isRoot) {
                    buildNode(root, tmp);
                    isRoot = false;
                    nodes.push(root);
                    tmp = "";
                    continue;
                }
                TreeNode* node = NULL;
                buildNode(node, tmp);
                if (!hasLeft) {
                    nodes.front() -> left = node;
                    if(node)
                        nodes.push(node);
                    hasLeft = true;
                } else {
                    nodes.front() -> right = node;
                    nodes.pop();
                    if(node)
                        nodes.push(node);
                    hasLeft = false;
                }
                tmp = "";
                continue;
            }
            tmp.push_back(i);
        }
//        if (tmp.size() > 0) {
//            TreeNode* node = NULL;
//            buildNode(node, tmp);
//            if (isRoot) {
//                buildNode(root, tmp);
//            } else if (!hasLeft) {
//                nodes.front() -> left = node;
//                if(node)
//                    nodes.push(node);
//                hasLeft = true;
//            } else {
//                nodes.front() -> right = node;
//                nodes.pop();
//                if(node)
//                    nodes.push(node);
//                hasLeft = false;
//            }
//        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
    Codec s;
    string tree = "1,2,null,";
    TreeNode* r = s.deserialize(tree);
    cout << s.serialize(r) << endl;
    return 0;
}
