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
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class MyHashMap {
public:
    int* m_plist[1024];
    /** Initialize your data structure here. */
    MyHashMap() {
        memset(m_plist, 0, sizeof(m_plist));
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int idx1 = key>>10;
        int idx2 = (key & 0x3ff);
        if (m_plist[idx1] == NULL) {
            m_plist[idx1] = new int[1024];
            memset(m_plist[idx1], -1, sizeof(int)*1024);
        }
        m_plist[idx1][idx2] = value;
        return;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int idx1 = key>>10;
        int idx2 = (key & 0x3ff);
        if (m_plist[idx1] == NULL) return -1;
        return m_plist[idx1][idx2];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int idx1 = key>>10;
        int idx2 = (key & 0x3ff);
        if (m_plist[idx1] == NULL) return;
        m_plist[idx1][idx2] = -1;
        return;
    }
};

int main() {
    MyHashMap obj;
    obj.put(1,2);
    int param_2 = obj.get(1);
    cout << param_2 << endl;
    obj.remove(1);
    return 0;
}
