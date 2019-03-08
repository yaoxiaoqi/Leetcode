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
#include <cmath>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode* detectStart(ListNode* head, int cycleLength) {
        ListNode* p = head;
        ListNode* q = head;
        for (int i = 0; i < cycleLength; i++) {
            q = q -> next;
        }
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        int cnt = 0;
        
        while (slow->next && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            ++cnt;
            if (slow == fast) {
                return detectStart(head, cnt);
            }
        }
        return NULL;
    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode(1);
    ListNode* p1 = new ListNode(2);
    ListNode* p2 = new ListNode(3);
    head->next = p1;
    p1->next = p2;
    p2->next = head;
    cout << s.detectCycle(head) -> val << endl;
    return 0;
}
