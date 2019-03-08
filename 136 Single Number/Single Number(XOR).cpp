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
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto num: nums) {
            res ^= num;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 1};
    cout << s.singleNumber(nums) << endl;
    return 0;
}
