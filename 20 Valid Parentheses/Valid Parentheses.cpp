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
    bool isValid(string s) {
        stack<char> parentheseStack;
        for (auto c : s) {
            if (parentheseStack.empty()) {
                parentheseStack.push(c);
                continue;
            }
            switch (c) {
                case ')':
                    if (parentheseStack.top() == '(') {
                        parentheseStack.pop();
                    } else {
                        return false;
                    }
                    break;
                case ']':
                    if (parentheseStack.top() == '[') {
                        parentheseStack.pop();
                    } else {
                        return false;
                    }
                    break;
                case '}':
                    if (parentheseStack.top() == '{') {
                        parentheseStack.pop();
                    } else {
                        return false;
                    }
                    break;
                default:
                    parentheseStack.push(c);
                    break;
            }
        }
        if (!parentheseStack.empty())
            return false;
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isValid("{([]([]))}") << endl;
    return 0;
}
