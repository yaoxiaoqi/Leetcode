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

class MapSum {
private:
    struct TrieNode {
        TrieNode* children[N];
        bool isEndOfWord = false;
        int sum = 0;
    };
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    MapSum() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string key, int val) {
        TrieNode* cur = root;
        for (auto c : key) {
            if (cur->children[c - 'a'] == NULL) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        int diff = val;
        if (cur->sum != 0 && cur->isEndOfWord) {
            diff = val - cur->sum;
        }
        cur->isEndOfWord = true;
        updateSum(key, diff);
        return;
    }
    
    /** Returns if the word is in the trie. */
    void updateSum(string key, int diff) {
        TrieNode* cur = root;
        for (auto c : key) {
            cur->sum += diff;
            cur = cur->children[c - 'a'];
        }
        cur->sum += diff;
    }
    
    int sum(string prefix) {
        TrieNode* cur = root;
        for (auto c : prefix) {
            if (cur) cur = cur->children[c - 'a'];
        }
        if (cur) return cur->sum;
        return 0;
    }
    
};


int main() {
    MapSum obj;
    obj.insert("apple", 3);
    obj.insert("app", 2);
    obj.insert("apple", 1);
    cout << obj.sum("bbb");
    
    return 0;
}
