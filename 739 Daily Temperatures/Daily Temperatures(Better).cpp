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
        stack<int> TStack;
        for (int i = 0; i < n; i++) {
            while (!TStack.empty() && T[i] > T[TStack.top()]) {
                int idx = TStack.top();
                res[idx] = i - idx;
                TStack.pop();
            }
            TStack.push(i);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> T = {3,4,5,1,0,2,6,3};
    vector<int> ans = s.dailyTemperatures(T);
//    cout << s.numSquares(7168) << endl;
    for (auto i : ans) {
        cout << i << endl;
    }
    return 0;
}
