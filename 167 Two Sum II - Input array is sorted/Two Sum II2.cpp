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
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2, 0);
        int l = 0, r = (int)numbers.size() - 1;
        while (l < r) {
            if (numbers[l] + numbers[r] == target) {
                ans[0] = l + 1;
                ans[1] = r + 1;
                return ans;
            } else if (numbers[l] + numbers[r] < target) {
                ++l;
            } else {
                --r;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 2, 3, 4, 4, 9, 20};
    vector<int> ans = s.twoSum(a, 8);
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
//    cout << s.binarySearch(a, 3) << endl;
    return 0;
}
