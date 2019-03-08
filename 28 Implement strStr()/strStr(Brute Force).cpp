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
    int strStr(string haystack, string needle) {
        if (needle == "") {
            return 0;
        } else if (haystack == "") {
            return -1;
        }
        int N = static_cast<int>(haystack.size());
        int M = static_cast<int>(needle.size());
        for (int i = 0; i <= N - M; i++) {
            int j = 0;
            int tmp = i;
            for (j = 0; j < M; j++) {
                if (haystack[tmp++] != needle[j])
                    break;
            }
            if (j == M)
                return i;
        }
        return -1;
    }
};

int main() {
    Solution s;
    string text = "mississippi";
    string pattern = "mississippi";
    cout << s.strStr(text, pattern) << endl;
    return 0;
}
