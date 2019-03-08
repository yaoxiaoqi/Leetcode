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
    vector<int> plusOne(vector<int>& digits) {
        int len = int(digits.size());
        plusOneRecur(digits, len - 1);
        return digits;
    }
private:
    vector<int> plusOneRecur(vector<int>& digits, int cnt) {
        if (digits[cnt] < 9) {
            digits[cnt] += 1;
            return digits;
        } else {
            digits[cnt] = 0;
            if (cnt <= 0) {
                digits.insert(digits.begin(), 1);
                return digits;
            }
            plusOneRecur(digits, cnt-1);
        }
        return digits;
    }
};

int main() {
    Solution s;
    vector<int> a = {9, 9, 9, 9};
    for (auto i: s.plusOne(a)) {
        cout << i << endl;
    }
    
    return 0;
}
