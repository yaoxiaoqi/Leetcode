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
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        for (auto key : nums) {
            if (hashset.count(key) > 0) {
                return true;
            }
            hashset.insert(key);
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 1};
    cout << s.containsDuplicate(nums) << endl;
    return 0;
}
