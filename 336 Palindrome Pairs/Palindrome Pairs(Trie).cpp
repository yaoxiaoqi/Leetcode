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

bool isPalindrome(string s) {
    int left = 0, right = s.size()-1;
    while (left < right) {
        if (s[left++] != s[right--]) return false;
        ++left; --right;
    }
    return true;
}

struct TrieNode {
    TrieNode* children[N];
    int index;
    vector<int> palindromeList;
    TrieNode(): index(-1) {
        for (int i = 0; i < N; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(int idx, string word) {
        TrieNode* cur = root;
        if (word == "") {
            root->index = idx;
            return;
        }
        if (idx!=root->index && isPalindrome(word)) root->palindromeList.push_back(idx);
        reverse(word.begin(), word.end());
        for (int i = 0; i < word.size(); i++) {
            if (!cur->children[word[i] - 'a']) {
                cur->children[word[i] - 'a'] = new TrieNode();
            }
            cur = cur->children[word[i] - 'a'];
            if (i < word.size()-1 && isPalindrome(word.substr(i+1))) cur->palindromeList.push_back(idx);
        }
        cur->index = idx;
        return;
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> pairs;
        
        Trie t;
        for (int i = 0; i < words.size(); i++) {
            t.insert(i, words[i]);
        }
        
        TrieNode* cur = t.root;
        for (int i = 0; i < words.size(); i++) {
            cur = t.root;
            string word = words[i];
            for (int j = 0; j < word.size(); j++) {
                if (cur->children[word[j] - 'a'] == NULL) break;
                cur = cur->children[word[j] - 'a'];
                if (cur->index >= 0) {
                    if (i != cur->index && isPalindrome(word.substr(j+1))) pairs.push_back({i, cur->index});
                }
                if (j == word.size()-1) {
                    for (auto idx:cur->palindromeList) pairs.push_back({i, idx});
                }
            }
        }
        
        if (t.root->index >= 0) {
            int emptyIdx = t.root->index;
            for (auto idx:t.root->palindromeList) {
                pairs.push_back({emptyIdx, idx});
                pairs.push_back({idx, emptyIdx});
            }
        }
        
        return pairs;
    }
};

int main() {
    Solution s;
    vector<string> words = {"a",""};
    vector<vector<int>> pairs = s.palindromePairs(words);
    for (auto pair:pairs) {
        for (auto i:pair) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
