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
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i< nums.size(); i+=2) {
            sum += nums[i];
        }
        return sum;
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 4, 3, 2};
    cout << s.arrayPairSum(a) << endl;
    return 0;
}
