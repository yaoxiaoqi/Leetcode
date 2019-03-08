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

class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[N];
        bool isEndOfWord = false;
        // you might need some extra values according to different cases
    };
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* cur = root;
        for (auto c : word) {
            if (cur->children[c - 'a'] == NULL) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->isEndOfWord = true;
        return;
    }
    
    bool search(string word) {
        return searchSubtree(word, root);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool searchSubtree(string word, TrieNode* cur) {
        if (word.size() == 0) return true;
        else if (word.size() == 1) {
            if (word[0] == '.') {
                for (int i = 0; i < N; i++) {
                    if (cur->children[i] && cur->children[i]->isEndOfWord)
                        return true;
                }
                return false;
            } else {
                return cur->children[word[0] - 'a'] && cur->children[word[0] - 'a']->isEndOfWord;
            }
        }
       if (word[0] == '.') {
           for (int i = 0; i < N; i++) {
               if (cur->children[i] && searchSubtree(word.substr(1, word.size()), cur->children[i]))
                   return true;
           }
           return false;
       } else {
           return cur->children[word[0]- 'a'] && searchSubtree(word.substr(1, word.size()), cur->children[word[0]- 'a']);
       }
    }
};

int main() {
    WordDictionary obj;
    obj.addWord("dad");
    obj.addWord("bad");
    obj.addWord("mad");
    bool param_2 = obj.search(".");
    cout << param_2 << endl;
    return 0;
}
