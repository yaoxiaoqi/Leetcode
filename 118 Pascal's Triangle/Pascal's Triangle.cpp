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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows <= 0) {
            return ans;
        }
        for (int i = 0; i < numRows; i++) {
            if (i == 0) {
                ans.push_back({1});
            } else if (i == 1) {
                ans.push_back({1, 1});
            } else {
                vector<int> tmp;
                tmp.push_back(1);
                for (int j = 0; j < i - 1; j++) {
                    tmp.push_back(ans[i-1][j] + ans[i-1][j+1]);
                }
                tmp.push_back(1);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = s.generate(5);
    for (auto i: matrix) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
