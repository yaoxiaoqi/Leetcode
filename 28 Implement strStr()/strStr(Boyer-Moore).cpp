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
        int R = 256;
        int N = haystack.size();
        int M = needle.size();
        vector<int> right(R, -1);
        for (int i = 0; i < M; i++) {
            right[needle[i]] = i;
        }
        int skip = 0;
        for (int j = 0; j <= N-M; j+=skip) {
            skip = 0;
            for (int k = M-1; k>=0; k--) {
                if (haystack[j+k] != needle[k]) {
                    skip = k - right[haystack[j+k]];
                    if (skip < 1) skip = 1;
                }
            }
            if (skip == 0) {
                return j;
            }
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
