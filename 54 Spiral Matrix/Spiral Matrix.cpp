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
    enum Direction {Right = 0, Down, Left, Up};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = static_cast<int>(matrix.size());
        if (row == 0) {
            return ans;
        }
        int column = static_cast<int>(matrix[0].size());
        int count = 0;
        int i = 0, j = 0;
        Direction dir = Right;
        
        int upBound = 0, rightBound = column - 1, downBound = row - 1, leftBound = 0;
        
        while (count < row * column) {
            ans.push_back(matrix[i][j]);
            ++count;
            switch (dir) {
                case Right:
                    ++j;
                    if (j >= rightBound) {
                        dir = Down;
                        ++upBound;
                        if (j > rightBound) {
                            j = rightBound;
                            ++i;
                        }
                    }
                    break;
                case Down:
                    ++i;
                    if (i >= downBound) {
                        dir = Left;
                        --rightBound;
                        if (i > downBound) {
                            i = downBound;
                            --j;
                        }
                    }
                    break;
                case Left:
                    --j;
                    if (j <= leftBound) {
                        dir = Up;
                        --downBound;
                        if (j < leftBound) {
                            j = leftBound;
                            --i;
                        }
                    }
                    break;
                case Up:
                    --i;
                    if (i <= upBound) {
                        dir = Right;
                        ++leftBound;
                        if (i < upBound) {
                            i = upBound;
                            ++j;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> answer = s.spiralOrder(matrix);
    for (auto i: answer) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
