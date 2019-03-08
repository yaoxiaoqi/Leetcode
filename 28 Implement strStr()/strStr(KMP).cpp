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
//    vector<vector<int>> *constructDFA(string pattern) {
//        int r = 256;
//        int len = static_cast<int>(pattern.size());
//        static vector<vector<int>> dfa(r, (vector<int>(len, 0)));
//        dfa[pattern[0]][0] = 1;
//
//        for (int X = 0, j = 1; j < len; j++) {
//            for (int i = 0; i < r; i++) {
//                dfa[i][j] = dfa[i][X];
//            }
//            dfa[pattern[j]][j] = j + 1;
//            X = dfa[pattern[j]][X];
//        }
//
//        return &dfa;
//    }
    
    int strStr(string haystack, string needle) {
        if (needle == "" || haystack == "") {
            return 0;
        }
        int N = static_cast<int>(haystack.size());
        int M = static_cast<int>(needle.size());
        int R = 256;
        vector<vector<int>> dfa(R, (vector<int>(M, 0)));
        dfa[needle[0]][0] = 1;
        for (int X = 0, j = 1; j < M; j++) {
            for (int i = 0; i < R; i++) {
                dfa[i][j] = dfa[i][X];
            }
            dfa[needle[j]][j] = j + 1;
            X = dfa[needle[j]][X];
        }

        int j = 0;
        for (int i = 0; i < N; i++) {
            j = dfa[haystack[i]][j];
            if (j == M) {
                return i - M + 1;
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
