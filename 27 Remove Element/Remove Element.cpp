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
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() < 1) {
            return 0;
        }
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};

int main() {
    Solution s;
    vector<int> a = {1};
    int ans = s.removeElement(a, 1);
    for (auto i : a) {
        cout << i << " ";
    }
    cout << endl;
//    cout << s.binarySearch(a, 3) << endl;
    return 0;
}
