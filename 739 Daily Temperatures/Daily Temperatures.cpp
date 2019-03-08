//
//  main.cpp
//  Leetcode
//
//  Created by 妖小七 on 2018/11/23.
//  Copyright © 2018 妖小七. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        size_t n = T.size();
        vector<int> res(n, 0);
        if (n == 0) {
            return res;
        }
        vector<int> TStack;
        TStack.push_back(0);
        for (int i = 1; i < n; i++) {
            for (int j = TStack.size()-1; j >= 0; j--) {
                int index = TStack[j];
                if (T[i] > T[index]) {
                    ++res[index];
                    TStack.pop_back();
                } else {
                    ++res[index];
                }
            }
            TStack.push_back(i);
        }
        for (auto index:TStack) {
            res[index] = 0;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> T = {1,2};
    vector<int> ans = s.dailyTemperatures(T);
//    cout << s.numSquares(7168) << endl;
    for (auto i : ans) {
        cout << i << endl;
    }
    return 0;
}
