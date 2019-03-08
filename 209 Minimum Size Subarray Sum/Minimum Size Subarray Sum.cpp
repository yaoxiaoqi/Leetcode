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
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() < 1) {
            return 0;
        }
        int sum = 0, count = 0;
        int ans = INT_MAX;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            while (sum >= s) {
                ans = min(ans, count);
                sum -= nums[i - count];
                --count;
            }
            sum += nums[i];
            ++count;
        }
        while (sum >= s) {
            ans = min(ans, count);
            sum -= nums[len - count];
            --count;
        }
        if (ans == INT_MAX) {
            return 0;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 4, 4, 5};
    int ans = s.minSubArrayLen(9, a);
//    for (auto i : a) {
//        cout << i << " ";
//    }
//    cout << endl;
    cout << ans << endl;
    return 0;
}
