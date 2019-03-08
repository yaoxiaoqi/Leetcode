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
    int dominantIndex(vector<int>& nums) {
        int max = -1;
        bool is_twice = false;
        int pos = -1;
        
        for (int i = 0; i< nums.size(); i++) {
            int old_max;
            if (nums[i] > max) {
                old_max = max;
                max = nums[i];
                if (max >= 2*old_max) {
                    is_twice = true;
                    pos = i;
                } else {
                    is_twice = false;
                }
            } else {
                if (max < 2 * nums[i]){
                    is_twice = false;
                }
            }
        }
        if (is_twice) {
            return pos;
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> a = {3, 4, 2, 1};
    cout << s.dominantIndex(a) << endl;
    return 0;
}
