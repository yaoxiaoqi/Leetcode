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
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head -> val == val) {
            head = head -> next;
        }
        ListNode* p = head;
        while (p) {
            while (p->next && p->next->val == val) {
                if (p->next->next) {
                    p->next = p->next->next;
                } else {
                    p->next = NULL;
                }
            }
            p = p->next;
        }
        return head;
    }
    
    void display(ListNode* head) {
        while (head) {
            cout << head -> val << " ";
            head = head -> next;
        }
        cout << endl;
    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode(1);
    ListNode* headB = new ListNode(10);
    ListNode* p1 = new ListNode(2);
    ListNode* p2 = new ListNode(2);
    head->next = p1;
    p1->next = p2;
    p2->next = headB;
    s.display(s.removeElements(head, 2));
    return 0;
}
