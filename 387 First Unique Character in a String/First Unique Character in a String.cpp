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
    int firstUniqChar(string s) {
        vector<int> time(26, 0);
        for (auto ch: s) {
            ++time[ch-'a'];
        }
        for (int i = 0; i < s.size(); i++) {
            if (time[s[i]-'a'] == 1) return i;
        }
        return -1;
    }
};
int main() {
    Solution s;
    s.firstUniqChar("loveleetcode");
    return 0;
}
