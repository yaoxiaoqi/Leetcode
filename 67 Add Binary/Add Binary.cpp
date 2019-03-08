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
#include <cmath>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0) {
            if (i < 0) {
                int tmp = (b[j] - '0') + carry;
                carry = tmp / 2;
                ans = to_string(tmp % 2) + ans;
                --j;
            } else if (j < 0) {
                int tmp = (a[i] - '0') + carry;
                carry = tmp / 2;
                ans = to_string(tmp % 2) + ans;
                --i;
            } else {
                int tmp = (a[i] - '0') + (b[j] - '0') + carry;
                carry = tmp / 2;
                ans = to_string(tmp % 2) + ans;
                --i; --j;
            }
        }
        if (carry > 0) {
            ans = to_string(carry) + ans;
        }
        return ans;
    }
};

int main() {
    Solution s;
    string a = "11";
    string b = "1111";
    cout << s.addBinary(a, b) << endl;
    return 0;
}
