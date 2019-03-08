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
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mapping;
        int index = 0;
        vector<vector<string>> ans;
        for (auto str: strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            if (mapping.count(tmp) <= 0) {
                mapping[tmp] = index++;
                ans.push_back({});
            }
            ans[mapping[tmp]].push_back(str);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"ate", "eat", "tab"};
    vector<vector<string>> ans = s.groupAnagrams(strs);
    for (auto group: ans) {
        for (auto item: group) {
            cout << item << " ";
        }
        cout << endl;
    }
    return 0;
}
