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
private:
    size_t colNum = 0, rowNum = 0;
public:
    bool isValid(int x, int y) {
        return x >= 0 && x < rowNum && y >= 0 && y < colNum;
    }
    void findIslandRange(vector<vector<char>>& grid, int x, int y) {
        if (grid[x][y] == '1') {
            grid[x][y] = '0';
            if (isValid(x, y - 1)) {
                findIslandRange(grid, x, y-1);
            }
            if (isValid(x - 1, y)) {
                findIslandRange(grid, x-1, y);
            }
            if (isValid(x, y + 1)) {
                findIslandRange(grid, x, y+1);
            }
            if (isValid(x + 1, y)) {
                findIslandRange(grid, x+1, y);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        rowNum = grid.size();
        if (rowNum)
            colNum = grid[0].size();
        else
            return 0;
        int islandNum = 0;
        for (int i = 0; i < rowNum; i++)
            for (int j = 0; j < colNum; j++) {
                if (grid[i][j] == '1') {
                    ++islandNum;
                    findIslandRange(grid, i, j);
                }
            }
        return islandNum;
    }
};

int main() {
    Solution s;
    vector<vector<char>> grid = {{'1','1','0','0','0'}};
    //    vector<vector<char>> grid = {{'1', '1', '0'}};
    cout << s.numIslands(grid) << endl;
    return 0;
}
