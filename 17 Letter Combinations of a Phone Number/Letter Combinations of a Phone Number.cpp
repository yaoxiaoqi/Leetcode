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

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return answer;
        }
        vector<string> sequence;
        string item;
        for (auto i: digits) {
            sequence.push_back(telenum[i-'0']);
        }
        bfs(sequence, item);
        return answer;
    }
private:
    vector<string> answer;
    vector<string> telenum = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void bfs(vector<string> sequence, string& ans) {
        if (sequence.size() == 0) {
            answer.push_back(ans);
            ans.pop_back();
            return;
        }
        while(sequence[0].size() > 0) {
            ans.push_back(sequence[0].back());
            vector<string> tmp(sequence.begin()+1, sequence.end());
            bfs(tmp, ans);
            sequence[0].pop_back();
        }
        if (ans.size()>0)
            ans.pop_back();
        return;
    }
};

int main() {
    Solution s;
    for (auto i : s.letterCombinations("234")) {
        cout << i << " ";
    }
    return 0;
}
