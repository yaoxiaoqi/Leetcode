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
public:
    int numSquares(int n) {
        vector<int> squareList;
        bool findInNextLevel = false;
        for (int i = 1; (i * i) <= n; i++) {
            squareList.push_back(i*i);
        }
        queue<int> q;
        for (auto i : squareList) {
            q.push(i);
        }
        int level = 0;
        while (!q.empty()) {
            ++level;
            size_t size = q.size();
            for (int i = 0; i < size; i++) {
                int num = q.front();
                if (num == n) {
                    return level;
                }
                if (!findInNextLevel) {
                    for (auto i : squareList) {
                        if (num + i < n) {
                            q.push(num + i);
                        } else if (num + i == n) {
                            q.push(num + i);
                            findInNextLevel = true;
                        }
                    }
                }
                q.pop();
            }
            if (findInNextLevel) {
                return ++level;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.numSquares(7168) << endl;
    return 0;
}
