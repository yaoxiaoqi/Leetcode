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
    int titleToNumber(string s) {
        int power = 0;
        int res = 0;
        for (int i = int(s.size())-1;i>=0;i--) {
            res += (s[i] - 'A' + 1) * int(pow(26, power));
            ++power;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
    Solution s;
    cout << s.titleToNumber("ABB") << endl;
    return 0;
}
