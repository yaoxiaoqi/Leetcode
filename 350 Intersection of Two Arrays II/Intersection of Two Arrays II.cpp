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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> time;
        vector<int> res;
        for (auto num: nums1) {
            if (time.count(num) > 0) ++time[num];
            else time[num] = 1;
        }
        for (auto num: nums2) {
            if (time.count(num) > 0 && time[num] > 0) {
                res.push_back(num);
                --time[num];
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
