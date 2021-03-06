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

struct TrieNode {
    TrieNode* children[N];
    bool isWord = false;
};

class Trie {
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
};

class Solution {
private:
    size_t width = 0;
    size_t height = 0;
    set<string> resSet;
public:
    bool isValid(int x, int y) {
        return x >= 0 && x < height && y >= 0 && y < width;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        height = board.size();
        if (height) width = board[0].size();
        else return {};
        
        Trie t;
        for (auto word: words) {
            t.insert(word);
        }
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                findWordInBoard(board, i, j, t.root, "");
            }
        }
        vector<string> res(resSet.begin(), resSet.end());
        return res;
    }
    
    void findWordInBoard(vector<vector<char>>& board, int x, int y, TrieNode* node, string curWord) {
        if (board[x][y] != '$' && node->children[board[x][y] - 'a']) {
            TrieNode* cur = node->children[board[x][y] - 'a'];
            curWord += board[x][y];
            board[x][y] = '$';
            if (cur->isWord) resSet.insert(curWord);
            if (isValid(x-1, y)) findWordInBoard(board, x-1, y, cur, curWord);
            if (isValid(x, y-1)) findWordInBoard(board, x, y-1, cur, curWord);
            if (isValid(x+1, y)) findWordInBoard(board, x+1, y, cur, curWord);
            if (isValid(x, y+1)) findWordInBoard(board, x, y+1, cur, curWord);
            board[x][y] = curWord.back();
        }
        return;
    }
};

int main() {
    Solution s;
    vector<vector<char>> b = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> dict = {"oath","pea","eat","rain"};
//    vector<vector<char>> b = {{'b','a','a','b','a','b'},{'a','b','a','a','a','a'}};
//    vector<string> dict = {"baababaaaaba"};
//    vector<vector<char>> b = {{'a'}};
//    vector<string> dict = {"a"};
    vector<string> ans = s.findWords(b, dict);
    for (auto a:ans) cout << a << endl;
    return 0;
}
