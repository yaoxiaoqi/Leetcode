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
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {0}, column[9][9] = {0}, subbox[9][9] = {0};
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                int k = (i/3)*3 + (j/3);
                if (row[i][num] || column[j][num] || subbox[k][num]) return false;
                row[i][num] = column[j][num] = subbox[k][num] = 1;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    
    return 0;
}
