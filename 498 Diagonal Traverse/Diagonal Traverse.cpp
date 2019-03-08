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
    enum Direction {LeftDown = 0, RightUp};
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        Direction direct = RightUp;
        if (matrix.size() == 0) {
            return ans;
        }
        int row = (int)(matrix.size());
        int column = (int)(matrix[0].size());
        int cur_row = 0, cur_column = 0;
        while(cur_row < row && cur_column < column) {
            ans.push_back(matrix[cur_row][cur_column]);
            if (direct == RightUp) {
                if (cur_row == 0 && cur_column < column - 1) {
                    ++ cur_column;
                    direct = LeftDown;
                } else if (cur_column == column - 1){
                    ++ cur_row;
                    direct = LeftDown;
                } else {
                    -- cur_row; ++ cur_column;
                }
            } else {
                if (cur_column == 0 && cur_row < row - 1) {
                    ++ cur_row;
                    direct = RightUp;
                } else if (cur_row == row - 1){
                    ++ cur_column;
                    direct = RightUp;
                } else {
                    ++ cur_row;
                    -- cur_column;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{}};
    vector<int> ans = s.findDiagonalOrder(matrix);
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
