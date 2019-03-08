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

#define N 26

class Trie {
private:
    struct TrieNode {
        TrieNode* children[N];
        bool isWord = false;
        // you might need some extra values according to different cases
    };
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for (auto c : word) {
            if (cur->children[c - 'a'] == NULL) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->isWord = true;
        return;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for (auto c : word) {
            if (cur->children[c - 'a'] == NULL) {
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        if (cur->isWord) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (auto c : prefix) {
            if (cur->children[c - 'a'] == NULL) {
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        return true;
    }
};


int main() {
    Trie obj;
    obj.insert("apple");
    bool param_2 = obj.search("apple");
    cout << param_2 << endl;
    bool param_3 = obj.search("app");
    cout << param_3 << endl;
    obj.insert("app");
    param_3 = obj.search("app");
    cout << param_3 << endl;
    return 0;
}
