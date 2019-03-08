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
        unordered_set<int> numsSet;
        for (auto num : nums) {
            if (numsSet.count(num) > 0) {
                numsSet.erase(num);
            } else {
                numsSet.insert(num);
            }
        }
        return *numsSet.begin();
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 1};
    cout << s.singleNumber(nums) << endl;
    return 0;
}
