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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mapping;
        int minDist = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (mapping.count(nums[i]) > 0) {
                minDist = min(minDist, i-mapping[nums[i]]);
            }
            mapping[nums[i]] = i;
        }
        return minDist <= k;
    }
};

int main() {
    Solution s;
    return 0;
}
