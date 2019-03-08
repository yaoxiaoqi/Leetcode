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
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int squareSum(int num) {
        int sum = 0;
        while (num) {
            int bit = num % 10;
            sum += bit*bit;
            num /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        unordered_set<int> res;
        while((n = squareSum(n)) != 1) {
            cout << n << " ";
            if (res.count(n) > 0) return false;
            res.insert(n);
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isHappy(2) << endl;
    return 0;
}
