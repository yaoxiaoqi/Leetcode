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

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = int(nums.size()) - 1;
        int pos = 0;
        while (pos <= high) {
            if (nums[pos] == 0) {
                if (pos == 0) {
                    ++low;
                    ++pos;
                    continue;
                }
                auto it = nums.begin() + pos;
                std::rotate(nums.begin(), it, it + 1);
                ++low;
                ++pos;
            } else if (nums[pos] == 2) {
                if (pos == int(nums.size()) - 1) {
                    --high;
                    continue;
                }
                auto it = nums.begin() + pos;
                std::rotate(it, it + 1, nums.end());
                --high;
            } else {
                ++pos;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    s.sortColors(nums);
    
    for (auto i : nums) {
        cout << i << " ";
    }
    return 0;
}
