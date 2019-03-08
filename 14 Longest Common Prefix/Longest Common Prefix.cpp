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
#include <cmath>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if (strs.size() == 0) {
            return prefix;
        } else if (strs.size() == 1) {
            return strs[0];
        }
        bool flag = true;
        bool isLast = false;
        int no = 0;
        while (flag && (!isLast)) {
            char tmp = strs[0][no];
            for (int i = 0; i < strs.size(); i++) {
                if  (strs[i][no] != tmp) {
                    flag = false;
                    break;
                }
                if (no == strs[i].size() - 1) {
                    isLast = true;
                }
            }
            if (flag) {
                prefix += strs[0][no++];
            }
        }
        return prefix;
    }
};

int main() {
    Solution s;
    string text = "mississippi";
    string pattern = "mississippi";
    vector<string> strs = {"mississippi", "mississippi"};
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}
