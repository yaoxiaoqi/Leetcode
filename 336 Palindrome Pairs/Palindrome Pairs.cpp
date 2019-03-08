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
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define N 26

class Solution {
public:
    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> wordToIndex;
        vector<vector<int>> pairs;
        for (int i = 0; i < words.size(); i++) {
            wordToIndex.insert({words[i], i});
        }
        // appended string is shorter than current string
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j <= words[i].size(); j++) {
                // current word at front, appended word is shorter than current word or same size as current word
                if (isPalindrome(words[i], j, words[i].size()-1)) {
                    string candidate = words[i].substr(0,j);
                    reverse(candidate.begin(), candidate.end());
                    if (wordToIndex.find(candidate)!=wordToIndex.end() && wordToIndex[candidate] != i) {
                        pairs.push_back({i, wordToIndex[candidate]});
                    }
                }
                // current word at back, appended word is shorter than current word
                if (j == 0) continue;
                if (isPalindrome(words[i], 0, j-1)) {
                    string candidate = words[i].substr(j);
                    reverse(candidate.begin(), candidate.end());
                    if (wordToIndex.find(candidate)!=wordToIndex.end()&& wordToIndex[candidate] != i) {
                        pairs.push_back({wordToIndex[candidate], i});
                    }
                }
                
            }
        }
        return pairs;
    }
};

int main() {
    Solution s;
    vector<string> words = {"abaabaa","aba"};
//    cout << isPalindrome("abaa");
    vector<vector<int>> pairs = s.palindromePairs(words);
    for (auto pair:pairs) {
        for (auto i:pair) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
