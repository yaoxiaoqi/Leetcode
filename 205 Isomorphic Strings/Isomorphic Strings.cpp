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
    bool isIsomorphicOneSide(string s, string t) {
        unordered_map<char, char> mapping;
        for (int i = 0; i < s.size(); i++) {
            mapping[s[i]] = t[i];
        }
        string tmp = "";
        for (auto ch : s) {
            tmp += mapping[ch];
        }
        return tmp == t;
    }
    
    bool isIsomorphic(string s, string t) {
        return isIsomorphicOneSide(s, t) && isIsomorphicOneSide(t, s);
    }
};

int main() {
    Solution s;
    return 0;
}
