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
        bool isEndOfRoot = false;
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
        cur->isEndOfRoot = true;
        return;
    }
    
    /** Returns if the word is in the trie. */
    string search(string word) {
        TrieNode* cur = root;
        int index = 0;
        for (auto c : word) {
            if (cur->children[c - 'a'] == NULL) {
                return word;
            }
            cur = cur->children[c - 'a'];
            if (cur->isEndOfRoot) return word.substr(0, index+1);
            ++index;
        }
        if (cur->isEndOfRoot) return word.substr(0, index+1);;
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie t;
        for (auto root: dict) {
            t.insert(root);
        }
        string new_sentence;
        size_t pos = 0;
        string token;
        while ((pos = sentence.find(" ")) != string::npos) {
            token = sentence.substr(0, pos);
            sentence.erase(0, pos + 1);
            new_sentence += t.search(token) + " ";
        }
        new_sentence += t.search(sentence);
        return new_sentence;
    }
};

int main() {
    vector<string> a = {"cat", "bat", "rat", "was"};
    string s = "";
    Solution ss;
    cout << ss.replaceWords(a, s) << endl;
    
    return 0;
}
