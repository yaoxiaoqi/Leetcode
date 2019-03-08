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
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;
        else if (head -> next == NULL) {
            return false;
        }
        ListNode* p = head;
        ListNode* q = head;
        do {
            if (p -> next != NULL) {
                p = p->next;
            } else {
                return false;
            }
            if (q -> next != NULL) {
                q = q->next;
                if (q->next != NULL) {
                    q = q->next;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } while (p != q);
        return true;
    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode(1);
    ListNode* p1 = new ListNode(2);
    ListNode* p2 = new ListNode(3);
    head->next = p1;
    p1->next = p2;
    p2->next = p1;
    cout << s.hasCycle(head) << endl;
    return 0;
}
