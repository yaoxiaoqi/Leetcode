//
//  main.cpp
//  Leetcode
//
//  Created by 妖小七 on 2018/11/23.
//  Copyright © 2018 妖小七. All rights reserved.
//

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/**
 * Definition for undirected graph.
 */

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {}
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    map<Node*, Node*> clonedNodes;
public:
    Node *cloneGraph(Node *node) {
        if (clonedNodes.find(node) != clonedNodes.end()) {
            return clonedNodes[node];
        } else {
            if (node == NULL) {
                return NULL;
            }
            Node* newNode = new Node(node->val, {});
            clonedNodes[node] = newNode;
            for (auto neighbor: node->neighbors) {
                Node* newNeighbor = cloneGraph(neighbor);
                newNode->neighbors.push_back(newNeighbor);
            }
            return newNode;
        }
    }
};

int main() {
    Solution s;
    return 0;
}
