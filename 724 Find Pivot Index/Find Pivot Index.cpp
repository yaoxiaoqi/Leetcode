//
//  main.cpp
//  Leetcode
//
//  Created by 妖小七 on 2018/11/23.
//  Copyright © 2018 妖小七. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, left_sum = 0;
        for (auto i : nums) {
            sum += i;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (left_sum == (sum - left_sum - nums[i])) {
                return i;
            }
            left_sum += nums[i];
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> a = {-1, -1, -1, -1, -1, 0};
    cout << s.pivotIndex(a) << endl;
    return 0;
}
