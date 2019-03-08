//
//  main.cpp
//  Leetcode
//
//  Created by 妖小七 on 2018/11/23.
//  Copyright © 2018 妖小七. All rights reserved.
//

#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */

int DP(int pos, int end, int height, vector<vector<int>>& memo) {
    if (pos == 0) {
        return (height == 0);
    }
    if (memo[pos][height+end] >= 0) {
        return memo[pos][height+end];
    }
    
    memo[pos][height+end] = DP(pos-1, end, height, memo) + DP(pos-1, end, height-1, memo) + DP(pos-1, end, height+1, memo);
    
    return memo[pos][height+end];
};

int numOfWays(int end) {
    vector<vector<int>> memo(end+1,vector<int>(end*2+1, -1));
    return DP(end, end, 0, memo);
}


int main() {
    cout << numOfWays(2) << endl;
    return 0;
}
