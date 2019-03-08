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
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> diffToIndex;
        for (int i = 0; i < nums.size(); i++) {
            if (diffToIndex.count(nums[i]) > 0) {
                return {diffToIndex[nums[i]], i};
            }
            diffToIndex[target-nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution s;
    return 0;
}
