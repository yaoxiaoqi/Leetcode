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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> numSet;
        vector<int> res;
        if (nums1.size() == 0 || nums2.size() == 0) return res;
        for (auto num: nums1) {
            numSet.insert(num);
        }
        for (auto num: nums2) {
            if (numSet.count(num) > 0) {
                res.push_back(num);
                numSet.erase(num);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 1};
    return 0;
}
