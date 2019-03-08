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
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> indexSum;
        int min = 3000;
        vector<string> res;
        for (int i = 0; i < list1.size(); i++)
            indexSum[list1[i]] = i;
        for (int j = 0; j < list2.size(); j++) {
            if (indexSum.count(list2[j]) > 0) {
                int tmpSum = indexSum[list2[j]] + j;
                if (tmpSum < min) {
                    min = tmpSum;
                    res = {list2[j]};
                } else if (tmpSum == min) {
                    res.push_back(list2[j]);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
