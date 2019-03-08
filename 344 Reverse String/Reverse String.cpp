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
    string reverseString(string s) {
        int l = 0;
        int r = (int)(s.size()) - 1;
        char tmp;
        while (l < r) {
            tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            ++l; --r;
        }
        return s;
    }
};

int main() {
    Solution s;
    string text = "mississippi";
    string pattern = "mississippi";
    cout << s.reverseString("hehe,yuki,fool1") << endl;
    return 0;
}
