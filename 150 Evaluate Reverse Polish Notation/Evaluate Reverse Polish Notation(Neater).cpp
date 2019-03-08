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
        int num1, num2;
        for (auto token: tokens) {
            if (token.size() > 1 || (token[0] >= '0' && token[0] <= '9')) {
                s.push(stoi(token));
                continue;
            }
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            switch (token[0]) {
                case '+':
                    s.push(num2 + num1);
                    break;
                case '-':
                    s.push(num2 - num1);
                    break;
                case '*':
                    s.push(num2 * num1);
                    break;
                case '/':
                    s.push(num2 / num1);
                    break;
                default:
                    break;
            }
        }
        return s.top();
    }
};

int main() {
    Solution s;
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << s.evalRPN(tokens) << endl;
    return 0;
}
