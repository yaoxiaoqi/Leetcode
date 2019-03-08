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
    int binarySearch(vector<int>& numbers, int l, int target) {
        if (numbers.size() < 1) {
            return -1;
        }
        int r = (int)numbers.size() - 1;
        int middle = 0;
        while (l <= r) {
            middle = (l+r)/2;
            if (numbers[middle] == target) {
                return middle;
            } else if (numbers[middle] < target) {
                l = middle + 1;
            } else {
                r = middle - 1;
            }
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2, 0);
        for (int i = 0; i < numbers.size(); i++) {
            int tmp = binarySearch(numbers, i+1, target - numbers[i]);
            if (tmp >= 0) {
                ans[0] = i + 1;
                ans[1] = tmp + 1;
                return ans;
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
