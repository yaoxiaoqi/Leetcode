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
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    int ans = 0;
    int targetSum;
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        targetSum = S;
        DFS(nums, 0, '+', 0);
        DFS(nums, 0, '-', 0);
        return ans;
    }
    
    void DFS(vector<int>& nums, int pos, char sign, int cur_sum) {
        if (sign == '+') {
            cur_sum += nums[pos];
        } else {
            cur_sum -= nums[pos];
        }
        if (pos == nums.size()-1) {
            if (cur_sum == targetSum) {
                ++ans;
            }
            return;
        }
        DFS(nums, pos+1, '+', cur_sum);
        DFS(nums, pos+1, '-', cur_sum);
    }
};

int main() {
    Solution s;
    vector<int> num = {1, 1, 1, 1, 1};
    cout << s.findTargetSumWays(num, 3) << endl;
    return 0;
}
