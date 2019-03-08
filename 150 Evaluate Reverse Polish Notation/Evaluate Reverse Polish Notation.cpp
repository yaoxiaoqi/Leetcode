//
//  main.cpp
//  Leetcode
//
//  Created by 妖小七 on 2018/11/23.
//  Copyright © 2018 妖小七. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int res = 0;
        int num1, num2, tmp;
        for (auto token: tokens) {
            if (token == "+") {
                num1 = s.top();
                s.pop();
                num2 = s.top();
                s.pop();
                tmp = num1 + num2;
                s.push(tmp);
            } else if (token == "-") {
                num1 = s.top();
                s.pop();
                num2 = s.top();
                s.pop();
                tmp = num2 - num1;
                s.push(tmp);
            } else if (token == "*") {
                num1 = s.top();
                s.pop();
                num2 = s.top();
                s.pop();
                tmp = num1 * num2;
                s.push(tmp);
            } else if (token == "/") {
                num1 = s.top();
                s.pop();
                num2 = s.top();
                s.pop();
                tmp = num2 / num1;
                s.push(tmp);
            } else {
                s.push(stoi(token));
            }
        }
        if (!s.empty()) {
            res = s.top();
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << s.evalRPN(tokens) << endl;
    return 0;
}
