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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        if (head->next == NULL) {
            return head;
        }
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
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
    ListNode* p2 = new ListNode(3);
    head->next = p1;
    p1->next = p2;
    s.display(s.reverseList(NULL));
    return 0;
}
