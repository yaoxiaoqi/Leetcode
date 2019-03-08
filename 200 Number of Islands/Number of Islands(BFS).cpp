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
        queue<vector<int>> q;
        q.push({x, y});
        while(!q.empty()) {
            size_t size = q.size();
            for (int i = 0; i < size; i++) {
                vector<int> point = q.front();
                x = point[0];
                y = point[1];
                if (grid[x][y] == '0') {
                    q.pop();
                    continue;
                }
                if (isValid(x, y - 1) && grid[x][y - 1] == '1') {
                    q.push({x, y - 1});
                }
                if (isValid(x - 1, y) && grid[x - 1][y] == '1') {
                    q.push({x - 1, y});
                }
                if (isValid(x, y + 1) && grid[x][y + 1] == '1') {
                    q.push({x, y + 1});
                }
                if (isValid(x + 1, y) && grid[x + 1][y] == '1') {
                    q.push({x + 1, y});
                }
                grid[x][y] = '0';
                q.pop();
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
    void display(vector<vector<char>>& grid) {
        for (auto i : grid) {
            for (auto j : i) {
                cout << j;
            }
            cout << endl;
        }
    }
};

int main() {
    Solution s;
    vector<vector<char>> grid = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
//    vector<vector<char>> grid = {{'1', '1', '0'}};
    cout << s.numIslands(grid) << endl;
    return 0;
}
