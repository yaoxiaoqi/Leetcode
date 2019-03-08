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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                ++k;
            } else {
                ans = max(ans, k);
                k = 0;
            }
        }
        ans = max(ans, k);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> a = {};
    int ans = s.findMaxConsecutiveOnes(a);
//    for (auto i : a) {
//        cout << i << " ";
//    }
//    cout << endl;
    cout << ans << endl;
    return 0;
}
