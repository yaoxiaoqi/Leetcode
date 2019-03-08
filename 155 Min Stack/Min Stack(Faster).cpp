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
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class MinStack {
private:
    vector<int> data;
    vector<int> min;
public:
    /** initialize your data structure here. */
    MinStack() {
        min.push_back(INT_MAX);
    }
    
    void push(int x) {
        data.push_back(x);
        if (x < min.back()) {
            min.push_back(x);
        } else {
            min.push_back(min.back());
        }
    }
    
    void pop() {
        if (data.empty())
            return;
        data.pop_back();
        min.pop_back();
        return;
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return min.back();
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
//    Solution s;
//    cout << s.numSquares(7168) << endl;
    return 0;
}
