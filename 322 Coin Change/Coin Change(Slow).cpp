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
#include <algorithm>

using namespace std;

class Solution {
    vector<int> coins_needed;
    vector<int> coin_list;
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        // initialize
        auto it = coins_needed.begin();
        coins_needed.insert(it, amount+1, -2);
        for (auto i:coins) {
            if (i <= amount) {
                coins_needed[i] = 1;
                coin_list.push_back(i);
            }
        }
        for (int i = 0; i <= amount; i++) {
            if (coins_needed[i] == 1) {
                break;
            }
            coins_needed[i] = -1;
        }
        return getCoinNumber(amount);
    }
    
    int getCoinNumber(int money) {
        if (coins_needed[money] > -2) {
            return coins_needed[money];
        }
        int tmp = -1;
        for (auto i : coin_list) {
            if (i > money) {
                continue;
            }
            int tmp1 = getCoinNumber(i);
            int tmp2 = getCoinNumber(money-i);
            if (tmp1>0 && tmp2>0) {
                if (tmp > 0) {
                    tmp = min(tmp, tmp1+tmp2);
                } else {
                    tmp = tmp1+tmp2;
                }
            }
        }
        coins_needed[money] = tmp;
        return coins_needed[money];
    }
};

int main() {
    Solution s;
    vector<int> coins = {3};
    cout << s.coinChange(coins, 4) << endl;
    return 0;
}
