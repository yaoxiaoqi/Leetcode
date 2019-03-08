//
//  main.cpp
//  Leetcode
//
//  Created by 妖小七 on 2018/11/7.
//  Copyright © 2018 妖小七. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = int(arr.size())-k;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (abs(x - arr[mid]) > abs(x - arr[mid+k])) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
//        cout << left << "," << right << endl;
        return vector<int>(arr.begin() + left, arr.begin() + (left + k));
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 2, 3, 4, 5};
    
    for(auto i : s.findClosestElements(a, 3, 4)) {
        cout << i << " ";
    }
    cout << endl;
//    cout << s.findPeakElement(a) << endl;
}
